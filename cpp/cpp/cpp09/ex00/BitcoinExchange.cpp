#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
    std::cout << "You should create a param object." << std::endl;
}

// Function to trim leading and trailing whitespace from a string
std::string trim(const std::string &str)
{
    std::string::const_iterator start = str.begin();
    while (start != str.end() && std::isspace(*start))
        ++start;

    if (start == str.end()) // The string is all whitespace
        return "";

    std::string::const_iterator end = str.end();
    do {
        --end;
    } while (end != start && std::isspace(*end));

    return std::string(start, end + 1);
}

// Constructor: Load exchange rates from the database CSV
BitcoinExchange::BitcoinExchange(const std::string &databaseFile)
{
    std::ifstream file(databaseFile.c_str()); // Convert to const char*
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file " + databaseFile);
    }

    std::string line, date;
    double rate;
    getline(file, line); // Skip the header line

    while (getline(file, line))
    {
        line = trim(line); // Trim the line
        std::stringstream ss(line);
        if (getline(ss, date, ',') && ss >> rate)
            exchangeRates[trim(date)] = rate;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->exchangeRates = other.exchangeRates;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// Validate date format as YYYY-MM-DD
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }

    // Days in each month (index 1 = January, 2 = February, ..., 12 = December)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year (if February has 29 days)
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYear && month == 2)
    {
        daysInMonth[2] = 29;
    }

    // Validate day within range for the month
    if (day > daysInMonth[month])
    {
        return false;
    }

    return true;
}

// Retrieve the exchange rate for the closest prior date
double BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(trim(date)); // Trim date for lookup
    if (it == exchangeRates.begin() && it->first != date)
        return (-1); // No prior date
    if (it == exchangeRates.end() || it->first != date)
        --it;
    return (it->second);
}

// Process each line in the input file and output results
void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
    std::ifstream file(inputFile.c_str()); // Convert to const char*
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file " + inputFile);
    }

    std::string line, date, valueStr;
    getline(file, line); // Skip the header line
    trim(line);
    if (line != "date | value")
        throw std::runtime_error("Error first line should be 'date | value'");

    while (getline(file, line))
    {
        line = trim(line); // Trim the line
        if (line.empty())
        {
            std::cerr << "Warning: empty or whitespace-only line detected." << std::endl;
            continue;
        }
        std::stringstream ss(line);
        if (!getline(ss, date, '|') || !(getline(ss >> std::ws, valueStr)))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = trim(date); // Trim the date
        if (!isValidDate(date))
        {
            std::cerr << "Error: invalid date format => " << date << std::endl;
            continue;
        }
        valueStr = trim(valueStr);

        std::stringstream valueStream(valueStr);
        double value;
        char extra;
        if (!(valueStream >> value) || valueStream >> extra) // Check for trailing characters
        {
            std::cerr << "Error: invalid value." << std::endl;
            continue;
        }

        if (value == 1000)
        {
            size_t dotPos = valueStr.find(".");
            std::string str = valueStr.substr(dotPos + 1);
            if (std::atoi(str.c_str()) != 0)
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = getExchangeRate(date);
        if (rate < 0)
        {
            std::cerr << "Error: date not found in database => " << date << std::endl;
            continue;
        }

        double result = rate * value;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}