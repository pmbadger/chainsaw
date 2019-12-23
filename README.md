# Chainsaw
A powerful C utilities library

## Modules
Chainsaw implements multiple submodules, which can be utilized for various purposes:
* [unittest.h](https://github.com/Eug-VS/chainsaw/blob/master/include/chain/chain.h)
  
  Unittest is a small module which is used to test the whole **Chainsaw library**. 
  Nevertheless, it's header is public (since it's located in *public `include/` folder*), therefore
  anyone can import this module in order to test his own application.
  
* [chain.h](https://github.com/Eug-VS/chainsaw/blob/master/include/chain/chain.h)

  Chain is an implementation of a *linked list*, which carefully operates with memory using low-level
  functions. The main feature of chain is that it can operate with any data type! You
  can think of it as a substitute for **C++ template container**, for example - `Vector<T>`

## 
