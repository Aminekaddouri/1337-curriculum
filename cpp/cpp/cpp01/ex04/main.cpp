/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaddour <akaddour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 07:35:38 by akaddour          #+#    #+#             */
/*   Updated: 2024/09/09 00:55:16 by akaddour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(const std::string input, const std::string s1, const std::string s2)
{
	std::string result;
	size_t pos = 0;
	size_t s1_len = s1.length();

	while (pos < input.length())
	{
		size_t found = input.find(s1, pos);
		if (found != std::string::npos)
		{
			result.append(input, pos, found - pos);
			result.append(s2);
			pos = found + s1_len;
		}
		else
		{
			result.append(input, pos, input.length() - pos);
			break ;	
		}
	}
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: Strings s1 and s2 cannot be empty." << std::endl;
		return (1);
	}

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (1);
	}

	std::string outFileName = filename + ".replace";
	std::ofstream outputFile(outFileName.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create output file " << filename << ".replace" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string newLine = replaceString(line, s1, s2);
		outputFile << newLine << std::endl;
	}

	inputFile.close();
	outputFile.close();
	
	return (0);
}