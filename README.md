# OS-Concepts-
A repository illustrating the usage of thread libraries and system calls using C

## Process Concepts folder : 
## 1. "matrix.cpp" (ILLUSTRATING FORK SYSTEM CALL AND WAIT SYSTEM CALL) 
  This is a program that illustrated the usage of the fork system call. It takes in a square matrix of any dimension as input 
  and creates 2 child processes . 1 child checks if each row has sum = n(n+1)/2 (SUM OF FIRST N NUMBERS) and another child 
  checks the same for the columns. 
  What is important to note here is the parent must wait for the children to finish . 
  
  Summary : <br/>
  Parent creates - >  child 1 <br/>
  child 1 creates - > child 2 <br/>
  parent waiting for child 1 <br/>
  child 1 waiting for child2 <br/>
  child 2 finishes checking rows <br/>
  child 1 finishes checking columns <br/>
  parents ends <br/>
  
  Whenever a fork system call is made another child is created and a copy of the parents data is created for the child.<break>
  
  Here in this example all processes are merely reading the matrix , hence no form of communictaion needed betweeen the 
  processes.
  
