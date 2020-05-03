// To illustrate how to use pipes for ipc

#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

// create a buffer size for pipe
#define BUFFER 40
#define READ_END 0
#define WRITE_END 1

int main()
{
    // create any message that you wish to send
    char message[BUFFER] = "Message successfully recieved";

    char read_message[BUFFER];
    
    char history[]
    // file descriptors for the read and write ends
    int fd[2];

    pid_t pid;

    // fd[0] => read end fd[1]=>write end
    int x = pipe(fd);
    
    if(x==-1)
    {
        printf("PIPE FAILED\n");
        return 1;
    }

    // fork a child now 
    pid = fork();

    if(pid < 0)
    {
        printf("Error creating child\n");
        return 0;
    }
    else if(pid>0)
    {
        pid_t pid1;
        
        // wait for the child to finish beacuse reading can happen only after something is written
        pid1 = wait(NULL);

        //close the unused end
        close(fd[WRITE_END]);

        //read the message from the read end of the pipe
        read(fd[READ_END],read_message,BUFFER);

        //print what we read
        printf("%s",read_message);
    }
    else 
    {
        //close the unused end
        close(fd[READ_END]);

        //write the message 
        write(fd[WRITE_END],message,strlen(message)+1);
        
        printf("Message has been written \n");
        
    }



}