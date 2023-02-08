#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main()
{
int pipe1[2],pipe2[2];
int fd1,fd2;
pipe(pipe1);
pipe(pipe2);
fd1=fork();
if(fd1==0)
{
close(pipe1[0]);
dup2(pipe1[1],1);
execlp("ls","ls",NULL);
}
else
{
fd2=fork();
if(fd2==0)
{
close(pipe1[1]);
close(pipe2[0]);
dup2(pipe1[0],0);
dup2(pipe2[1],1);
execlp("grep","grep","satheesh",NULL);
}
else
{
close(pipe1[1]);
close(pipe1[0]);
close(pipe2[1]);
dup2(pipe2[0],0);
execlp("wc","wc",NULL);
}
}
}
