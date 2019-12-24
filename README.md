# Chainsaw
A powerful C utilities library

## Modules
Chainsaw implements multiple submodules, which can be utilized for various purposes:
* [unittest.h](include/unittest/unittest.h)
  
  Unittest is a small module which is used to test the whole **Chainsaw library**. 
  Nevertheless, it's header is public (since it's located in *public `include/` folder*), therefore
  anyone can import this module in order to test his own application.
  
* [chain.h](include/chain/chain.h)

  Chain is an implementation of a *linked list*, which carefully operates with memory using low-level
  functions. The main feature of chain is that it can operate with any data type! You
  can think of it as a substitute for **C++ template container**, for example - `Vector<T>`.
  
## Project structure
In general case project structure looks like this:
```
chainsaw
├── bin
│   └── submodule1.test
├── include
│   ├── submodule1
│   │   └── submodule1.h
│   └── submodule2
│       └── submodule2.h
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

### src/
**Only `.c` files**. Contains source code for each submodule, which can be found in the corresponding folder `src/submodule_name/`.

### include/
**Only `.h` files**. Duplicates the hierarchy of `src/`, except it's purpose is storing *public headers*.

### test/
Contains source code for tests: `submodule_name.test.c` for each `src/submodule_name/`.

### bin/
**Appears after compilation**. Contains all compiled binaries, including executable test files - `submodule_name.test`.

### log/
**Appears after running**. Contains log files for each submodule.

