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
  
 ## 2. "pipe.c"
   This is a program illustrating the usage of pipes for interprocess communication. A pipe has 2 ends , a reading end and a 
   writing end. When a process has to write to it , it must close the reading end and when it has to read from it , it must 
   close the writing end.
 
 
 ## 2. "shared_memory.c"
   This is a program to illustrate usage of shared memory for interprocess communication. One must first create a shared 
   memory object and create a pointer to it .Then child processes may be forked and they all will share that memory created.
   They may read or write to it with the help of pointers to the shared memory.  
   Please make sure to compile with flag "-lrt".
 
 ## 4. "shell.c"
  This is the implementation of a linux shell that executes the basic linux shell commands like "pwd","ls","ps -el" , etc. 
  and also globally installed environment variables. It does not have the feature of change directories yet. 
  Basically everytime a command is entered it creates a child to execute the command . The parent awaits the child . 
  One added feature is the command "history" . It shows the last 10 executed commands . 
  
