#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc , char* argv[])
{
    int source;
    int dest;
    char buffer;
    int n1 = atoi(argv[3]);
    int n = atoi(argv[4]);

    source = open(argv[1],O_RDWR );
    dest = open(argv[2],O_RDWR | O_CREAT ,0644);

    if (source == -1 || dest == -1)
    {
        printf("error");
    }

    lseek(source,n1,SEEK_END);

    int i=0;
    while (i<n)
    {
        lseek(source , n1 - i , SEEK_SET);
        read(source,&buffer,1);
        write(dest,&buffer,1);  
        i++;
    }



}
