# Lexical Analyzer
A lexical analyzer, also known as a lexer or scanner, is a crucial component of a compiler. It takes in the source code of a program as input and outputs a sequence of tokens, which are individual units of meaning in the code.

This repository contains a simple implementation of a lexical analyzer in C++. It uses a finite automaton to identify and categorize tokens in a given program.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

## Prerequisites
 - A C++ compiler (e.g. GCC or Clang)
 - CMake (optional)

## Installing

Clone the repository to your local machine:

```
$ git clone https://github.com/ehsan-a-kian/lexical-analyzer.git
```

Navigate to the cloned repository:

```
$ cd lexical-analyzer
```

If you're using CMake, run the following commands to build the project:

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Alternatively, you can compile the project manually by running the following command in the root directory of the repository:
```
$ g++ -std=c++11 -o lexer lexer.cpp
```

## Usage

To use the lexical analyzer, run the following command in your terminal:

```
$ ./lexer [file-name]
```

Replace [file-name] with the name of the program you want to analyze. The output will be a list of tokens and their corresponding categories.

## Contributing
If you'd like to contribute to the repository, please fork the repository and make your changes in a separate branch. Then, submit a pull request for review.

## License
This project is licensed under the MIT License.
