Notes on Homework 2:

* General Notes
  - Solutions to Questions 1, 6 are located in hw2.txt
  
  - Solutions to Question 3 is located in problem3 folder
  
  - Solutions to Question 4 is located in problem4 folder
  
  - Solutions to Question 5 is located in problem5 folder
  
  - Solutions to Question 7 is located in problem7 folder
  
* Running the programs
  - After cloning the hw2 repository, cd into any problem_ folder and call 
        $ make clean
        $ make

  - All implementation files compile to the corresponding test files for Questions 3, 4, 5. Calling make runs the executable file to test out each respective class implementation. 

  - For Question 7, calling make runs the postfix.cpp file which is linked to both the stackdbl.h and llistdbl.h files within the makefile. 
  
  - For Question 7, before running the executable, please make sure to include both a postfix.in and postfix.out within the same working directory as the makefile will be searching for these files to include when preparing and running the executable file. 
  
* Special Note
  - For problem4/alistint.cpp and problem5/stackdbl.cpp, for the AListInt::get() functions (both) and the StackDbl::top() function, I return a value that corresponds the absolute minimum value that a 4-byte integer value could be by incorporating the standard <limits> library. I return this value when my AListInt implementation tries to return a value from an empty list or a position that is out of bounds when .get() is called and when my StackDbl implementation tries to return a value on a stack that is empty. When you run this program, you will get a warning saying that: 
    - (for int& AListInt::get(int)) warning: reference to local variable ‘defaultVal’ returned [-Wreturn-local-addr]
    - (for const int& AListInt::get(int) const) warning: reference to local variable ‘defaultVal’ returned [-Wreturn-local-addr]
    - (for const double& StackDbl::top() const) warning: returning reference to temporary [-Wreturn-local-addr]

