/*
Example to illustrate usage of shared memory
*/
#include <unistd.h> 
#include <sys/mman.h>
#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h> 
#include<string.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/wait.h>


int main()
{
    //The size of the shared memory in bytes
    const int SIZE = 4096;

    //name of the shared memory
    const char *shared_name = "ANSWER";

    // shared memory file descriptor
    int shm_fd;

    //pointer to shared memory 
    void *ptr;

    //create the object
    shm_fd = shm_open(shared_name,O_CREAT | O_RDWR ,0666);

    //configure memory size
    ftruncate(shm_fd,SIZE);

    // map the memory to a pointer
    void *ptr1;
    ptr1 = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0);
    // producer consumer work
    int n1;
    n1 = fork(); // fork is created  n1 = 0 for child and n1 = 1 for parent

    if(n1<0)
    {
        printf("FORK WAS UNSUCCESSFUL");
    }
    else if(n1 > 0)
    {
        // reading from memory
        pid_t pid;

        // waiting to read memory only after child finishes
        pid = wait(NULL);

        void *ptr2;

        //memory map to the shared object
        ptr2 = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);

        //reading string from shared memory 
        printf("\nI am the parent!  Hello %s!",(char *)ptr2);
        
        // unlink the object
        shm_unlink(shared_name);
        

    }
    else 
    {
        // writing his name to shared memory 
        char *name;
        printf("Please let me know your name!\n");
        scanf("%s",name);


        // accessing the shared memory by writing to it 
        sprintf((char *)ptr1,"%s",name);
    
    }






    
    
}