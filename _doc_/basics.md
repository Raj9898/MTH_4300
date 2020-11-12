# Basics C++

### Installation 
We will be using [Microsoft Visual studio](https://visualstudio.microsoft.com/vs/features/cplusplus/) for our C++ IDE and compiler. All simple code will be written with 
the following prerequisites provided within each `.cpp` file. As we develop more complicated scripts, these prerequisites will become more lax.  
```
#include <iostream>

// comment code
// main function to run code
int main(){

  // body of execution code
  
}
```
Prior to executing our C++ code, we will need to compile each `.cpp` file, creating an `.exe` (executable) to run from the command line

```
**********************************************************************
** Visual Studio 2019 Developer Command Prompt v16.5.3
** Copyright (c) 2019 Microsoft Corporation
**********************************************************************

// To compile the .cpp file
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community> cl filename.cpp

// To run the .exe file
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community> filename.exe
```

### Syntax Basics
Since C++ is a statically typed language, the type of the variable is known at compile-time instead of at run-time as with dynamically typed langauges like Python. 
Advantages of this include:
- Improved debugging, being able to error check early on in development
- Increased efficiency, being able to more efficiently allocate memory

Lets create a variable x, and set it equal to 10. Notice that we end each line with a semi-colon (;) - this signifies a statement termination. 
```
int x; 
x = 5
```
