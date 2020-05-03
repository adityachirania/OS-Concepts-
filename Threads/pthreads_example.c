#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int sum;// this data is shared by the thread
void *runner(void *param);// function that thread will call

int main(int argc,char *argv[])
{
    pthread_t tid;// create a thread id
    pthread_attr_t attr;//attributes of thread

    if(argc!=2)     
    {
        printf("Integer needed to get sum");
        return -1;
    }
    if(atoi(argv[1]) < 0)
    {
        printf("Non negative integer needed");
        return -1;
    }
    
    //setting default parameters
    pthread_attr_init(&attr);

    //create the thread
    pthread_create(&tid,&attr,runner,argv[1]);

    //wait for thread to exit
    pthread_join(tid,NULL);

    printf("sum = %d\n",sum);
}

void *runner(void *param)
{
    int i = 0;
    int upper = atoi(param);

    for(i = 1;i <= upper;i++)
        sum+=i;
    
    pthread_exit(0);
}
