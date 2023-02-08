
#include<unistd.h>
#include<stdio.h>
int main()
{
int fd1,fd2;
int pfd1[2],pfd2[2];
pipe(pfd1);
pipe(pfd2);
fd1=fork();
if(fd1==0)
{
close(pfd1[0]);
dup2(pfd1[1],1);
execlp("ls","ls",NULL);
}
else
{
fd2=fork();
if(fd2==0)
{
close(pfd1[1]);
close(pfd2[0]);
dup2(pfd1[0],0);
dup2(pfd2[1],1);
execlp("grep","grep","b",NULL);
}
else
{
close(pfd1[1]);
close(pfd1[0]);
close(pfd2[1]);
dup2(pfd2[0],0);
execlp("wc","wc","-l",NULL);
}
}
}
