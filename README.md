# C++ Module 09 – STL

Implementation of exercises using C++ Standard Template Library (STL).

## Exercises

- **00 – Bitcoin Exchange**: Parse a CSV database and evaluate bitcoin values at given dates.
- **01 – RPN**: Evaluate arithmetic expressions in Reverse Polish Notation.
- **02 – PmergeMe**: Sort positive integers using the merge-insert (Ford-Johnson) algorithm with two different containers.

## Requirements

- Compiled with `c++ -Wall -Wextra -Werror -std=c++98`
- Proper error handling on standard error
- No external libraries

## Usage
```sh
# Exercise 00
./btc input.txt

# Exercise 01
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

# Exercise 02
./PmergeMe 3 5 9 7 4
```

## Build
```sh
make        # compile
make clean  # remove objects
make fclean # remove all
make re     # rebuild
```