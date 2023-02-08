#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
int pipe1fd [2];
int fd;
pipe(pipe1fd);
fd=fork();
switch(fd)
{
case 0:
dup2(pipe1fd[1],1);
close(pipe1fd[0]);
execlp("pwd","pwd",NULL);
default:
dup2(pipe1fd[0],0);
close(pipe1fd[1]);
execlp("wc","wc",NULL);
}
return 0;
}

