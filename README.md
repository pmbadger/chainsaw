# Chainsaw
A powerful C utilities library

## Prerequisites
* [gcc](https://gcc.gnu.org/) - compiler for C
* [GNU Make](https://www.gnu.org/software/make/) - **must-have** tool for development automation

## Modules
Chainsaw implements multiple submodules, which can be utilized for various purposes:
* [unittest.h](include/unittest.h)
  
  Unittest is a small module which is used to test the whole **Chainsaw library**. 
  Nevertheless, it's header is public (since it's located in *public `include/` folder*), therefore
  anyone can import this module in order to test his own application.
  
* [chain.h](include/chain.h)

  Chain is an implementation of a *linked list*, which carefully operates with memory using low-level
  functions. The main feature of chain is that it can operate with any data type! You
  can think of it as a substitute for **C++ template container**, for example - `Vector<T>`.
  
* [math.h](include/math.h)

  Math module includes the most important math functions and definitions. Currently available
  functions allow to operate in the scope of number theory: rapidly factorize numbers, 
  perform primality tests, etc.

## Usage
In order to run all existing tests, execute `make all`, or simply `make`. This will produce an
output with summary for each submodule.

To test a specific submodule, execute `make submodule_name`, for example: 
```shell
$ make math
gcc test/math.test.c src/**/*.c -I include -o bin/math.test -Wall
bin/math.test:
1. Prime factorization of 1 is an empty product: PASS!
2. Product of multiple primes is factorized successfully: PASS!
3. But adding duplicate prime doesn't change the nubmer of unique factors: PASS!
4. There are exactly 168 primes up to 1000: PASS!
5. And each of these primes has only one factor of itself: PASS!
6. 44491 is prime: PASS!
7. 2729*3 is not prime: PASS!
All checks successful! [7 / 7]
Total coverage: 100.00%
```
If you are testing fresh repository, all tests should pass.

Similarly, you can write your own tests, not necessarily associated with submodules.
To run a custom test, place it to `test/custom_name.test.c` and then run `make custom_name`.
Generated binary file will be located at `bin/custom_name.test`, and its logs will be
written to `log/custom_name/***.log`.

In order to clear the project, use `make clean`, which will also give you cleanup summary.


## Project structure
In general case project structure looks like this:
```
chainsaw
├── bin
│   └── submodule1.test
├── include
│   ├── submodule1.h
│   └── submodule2.h
├── src
│   ├── submodule1
│   │   └── submodule1.c
│   └── submodule2
│       └── submodule2.c
│       └── some_extra_file.c
├── test
|   ├── submodule1.test.c
|   └── submodule2.test.c
├── log
│   └── submodule1
│       └── 1999-12-31_23:59:59.log
│       └── 2000-01-01_00:00:00.log
├── Makefile
├── README.md
```

