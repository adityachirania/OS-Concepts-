/*
A shell implemented in C
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<sys/wait.h>

#define MAX_LINE 80 // maximum length of a command
#define MAX_LENGTH 40




int main(void)
{
    char *args[MAX_LINE+1]; // Command line argumements 
    int should_run = 1;
    int last = 0;
    int top1 = 0;
    while(should_run)
    {
        printf("SHELL :>");
        fflush(stdout);
        
        char line[MAX_LENGTH];
        if(top1>last)last = top1;
        // contains history
        char history[10][30];
        
        //read in the command and args
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] = '\0';
        if(strcmp(line,"history")!=0)
        {
            strcpy(history[top1],line);
            top1 = (top1 + 1)%10;
        }

        char *token = strtok(line, " ");
        // loop through the string to extract all other tokens
        
        int index = 0;

        // parse the string 
        while( token != NULL ) {
            args[index] = token;
            token = strtok(NULL, " ");
            index++;
        }
        args[index] = '\0';
        
        int n1 = fork();
        if(n1==0)
        {
            if(strcmp(args[0],"history")==0)
            {
                for(int i = 0;i <last;i++ )
                {
                    printf("%s \n",history[i]);
                }
            }
            else
            {
                int s = execvp(args[0],args);
            }
            break;
        }        
        else
        {
            pid_t pid;
            pid  =  wait(NULL);
        }

    }

    return 0;
}

