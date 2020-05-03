#include <iostream> 
#include <unistd.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
using namespace std;



int main()
{
    int s;
    cout<<"enter the size of matrix";
    cin >> s;

    
    // dynamically allocating the 2d array 
    int *mat[s]; 
    for (int i=0; i<s; i++) 
         mat[i] = (int *)malloc(s * sizeof(int)); 
    


    //read the matrix
    for(int i = 0;i< s;i++)
    {
        for(int j = 0;j < s;j++)
        {
            cin >> mat[i][j];
        }
    }

    
    
    int n1,n2=-1;
    pid_t cpid;
    //fork the parent 
    
    
    n1 = fork();// n1=0 for child and n1>0 for parent 


    // fork another only for the child 
    if(n1==0)
    {
        n2 = fork();
    }


    if(n1>0 && n2==-1)
    {
        cpid = wait(NULL);
        sleep(10);
        sleep(5);
        cout<<"In the parent now !Everything is done\n ALL good\n";
        
    }

    else if(n1==0 && n2>0)
    {
        cpid = wait(NULL);
        sleep(10);
        cout<<"IN THE FIRST CHILD NOW !!! \n";

        int sum = 0;
        bool possible = true;

        for(int i = 0;i < s; i++)
        {   sum = 0;
            for(int j = 0;j < s;j++)
            {
                sum += (mat[j][i]);
            }
            if(sum != (s*(s+1))/2)
            {
                possible = false;
                break;
            }
        }

        if(possible)
        {
            cout<<"The columns are alright!!\n";
        }
        else
        {
            cout<<"The columns are'nt correct!!\n";
        }
    }
    else if(n1==0 && n2==0)
    {
        //checking the rows in this child 
        int sum = 0;
        bool possible = true;
        sleep(10);
        cout<<"IN THE SECOND CHILD NOW !!! \n";

        for(int i = 0;i < s; i++)
        {   
            sum = 0;
            for(int j = 0;j < s;j++)
            {
                sum += (mat[i][j]);
            }
            if(sum != (s*(s+1))/2)
            {
                possible = false;
                break;
            }
        }

        if(possible)
        {
            cout<<"The rows are alright!!\n";
        }
        else
        {
            cout<<"The rows are'nt correct!!\n";
        }
    }
    


}