#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
const int n=100;
int main() {
	char str[n], *space, argv1[n][n], *argv[n];
	int i=0,k=0,z=0,j=0, error=0;
	pid_t pid;
	printf("Welcome Back, Commander\n");
	gets(str);
	while(strcmp(str,"exit")!=0)
	{
	pid=fork();
	if (pid < 0) {
		printf("fork() error\n");
		return -1;
	}
	if (pid != 0) {
		int status;
		waitpid(pid, &status, 0);
		printf("Ret code: %d\n", WEXITSTATUS(status));
	}
       	else{ 	
		char *pch= strtok (str, " ");
		while(pch!=NULL)
		{
			argv[i]=pch;
			i++;
			pch=strtok(NULL," ");
		}
		i=0;
		error = execvp(argv[0],argv);	
		if (error==-1)
		{
			printf("error\n");	
			exit(42);
		}	
	}
	printf("Welcome Back, Commander\n");
	gets(str);
	}
	return 0;
}

