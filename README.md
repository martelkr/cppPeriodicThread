# C++ client/server with SSL/TLS support (header file only)
[![MIT license](https://img.shields.io/badge/license-MIT-blue.svg)](http://opensource.org/licenses/MIT)
![cmake Build](https://github.com/martelkr/cppPeriodicThread/actions/workflows/cmake.yml/badge.svg)
![clang Build](https://github.com/martelkr/cppPeriodicThread/actions/workflows/clang.yml/badge.svg)
![profile Build](https://github.com/martelkr/cppPeriodicThread/actions/workflows/profile.yml/badge.svg)
![cppcheck Build](https://github.com/martelkr/cppPeriodicThread/actions/workflows/cppcheck.yml/badge.svg)
[![Coverage Status](https://coveralls.io/repos/github/martelkr/cppPeriodicThread/badge.svg?branch=main)](https://coveralls.io/github/martelkr/cppPeriodicThread?branch=main)
![cpp-linter](https://github.com/martelkr/cppPeriodicThread/actions/workflows/linter.yml/badge.svg)

## About
This is a header file only implementation of a C++20 periodic jthread.

Compilation has been tested with:
- GCC 11.3.0 (GNU/Linux Ubuntu 22.04.1 LTS)
	- cmake 3.22.1
	- googletest 1.11.0-3
	- clang 14.0.0-1ubuntu1
- Visual Studio Community 2022 17.4.4 (64-bit) (Windows 11)
	- cmake 3.26.0-rc1
	- googletest 1.13.0

## Usage

### Periodic Thread

Create a CPeriodicThread object for executing a function periodically. 

```cpp
// assuming "myPeriodicThread" is a valid void return function to call periodically
std::function<void()> f = myPeriodicThread;
// call "f" every 1000 millliseconds or 1 second
CPeriodicThread p(f, 1000);
```

The periodicity of the called function doesn not subtract out for the execution of the
user provided function. For example, if a periodicity of 1 second is requested and the
called user function takes 0.5 seconds to execute, the function will be called the
second time at start time + 1.5 seconds and second function call will be called at
start time + 3 seconds and so forth.

## Thread Safety

Each periodic thread is its own instance and thread safe by itself. 

## Installation

Use the `CPeriodicThread.hpp` file in your source tree and include it in the file that need to use it.

## Run Unit Tests

Unit tests run with ctest:
```
ctest -C debug
```

## Contribute
All contributions are highly appreciated.
