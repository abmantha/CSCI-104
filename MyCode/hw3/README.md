Notes on Homework 3:

* General Notes
  - The solution to Problem 2 lives in the problem2 folder
   
  - The solution to Problem 3 lives in the problem3 folder
  
  - The solution to Problem 4 lives in the problem4 folder
  
  - Every problem_ folder has the following structure:
      - makefile
      - __test.cpp or pgindex.cpp
      - lib/
      - src/
      
    Where makefile is the problem folder's makefile, __test.cpp is the programs test file, lib/ contains that     
    particular classes .h file, and src/ contains that particular classes .cpp file.
    NOTE: problem4 does not have a __test.cpp file --> instead, it has a pgindex.cpp file

* Running the programs
  -  (For problem2 and problem3) After cloning the hw3 repository, cd into working directory and call
    -  $ make clean
    -  $ make

  - (For problem4) cd into working directory and call
    -  $ make clean
    -  $ make pgindex
    -  $ ./bin/pgindex pages.txt output.txt query1 query2 query3
    
    Where you may specify any file name in place of pages.txt and output.txt. Please make sure these files live in the working directory before running the executable. Otherwise, the program will terminate with an error message. It is up to you to decide how many queries you would like and which to call. 
