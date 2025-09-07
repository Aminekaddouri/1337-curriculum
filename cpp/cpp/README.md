# cpp

> My journey through the 1337 C++ modules — from classes to templates and the STL.

A collection of exercises that guided my transition from C to **modern C++**, covering core object-oriented programming concepts, memory management, polymorphism, templates, and the Standard Template Library (STL). This repository documents my progression through 10 intensive C++ modules.

---

### 📚 Modules Overview

#### 🔹 **cpp00: Introduction to C++**
- Learned the basics: `namespaces`, `classes`, `member functions`
- Used `std::cout`, `std::cin` for I/O
- Practiced `constructors`, `destructors`, `initialization lists`
- Explored `static` and `const` keywords

#### 🔹 **cpp01: Memory & Pointers**
- Deep dive into dynamic memory: `new` / `delete`
- Mastered **pointers to members** and **references**
- Used `switch` statements with classes
- Reinforced memory safety and RAII principles

#### 🔹 **cpp02: Orthodox Canonical Form & Overloading**
- Implemented the **Orthodox Canonical Class Form** (default, copy, assignment, destructor)
- Overloaded operators: `=`, `<<`, `[]`, `++`, `--`, `()`
- Learned the importance of const-correctness and deep copying

#### 🔹 **cpp03: Inheritance**
- Built class hierarchies using **public inheritance**
- Understood constructor/destructor order in derived classes
- Practiced composition and "is-a" relationships

#### 🔹 **cpp04: Polymorphism & Abstract Classes**
- Implemented **subtype polymorphism** with `virtual` functions
- Created **abstract classes** and pure virtual functions
- Used **interfaces** to define behavior without implementation

#### 🔹 **cpp05: Exceptions**
- Learned C++ exception handling: `try`, `catch`, `throw`
- Created custom exception classes
- Practiced writing exception-safe code

#### 🔹 **cpp06: C++ Casts**
- Replaced C-style casts with C++ alternatives:
  - `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`
- Understood when and why to use each cast
- Improved type safety and code clarity

#### 🔹 **cpp07: Templates**
- Wrote **function templates** and **class templates**
- Understood template instantiation and type deduction
- Created generic utilities (e.g., `::max`, `::min`, `::swap`)

#### 🔹 **cpp08: STL Fundamentals**
- Explored **templated containers**: `vector`, `list`, `stack`, `queue`
- Used **iterators** to traverse and modify containers
- Applied **algorithms** like `find`, `sort`, `for_each`

#### 🔹 **cpp09: The Standard Template Library (STL)**
- Mastered STL containers: `vector`, `map`, `set`, `stack`, `queue`, `deque`
- Used algorithms and iterators effectively
- Built applications leveraging STL for efficiency and clarity

---

### 🧰 Tech Stack
- **Language**: C++98 (strictly)
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror -std=c++98`
- **Standard**: No C++11 or later features
- **External Functions**: Only allowed functions (e.g., `std::cout`, `std::string`, `std::vector`)
