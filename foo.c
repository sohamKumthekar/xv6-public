#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	int i = 0, n = 1, pid = 0;
	double m = 7.21, l;
	
	//if no arg is provided initialize n = 1
	n = (argc < 2) ? 1 : atoi(argv[1]);
	
	//check if 'n' is within (0-20)
	n = (n < 0 || n > 20) ? 2 : n;
	  
	int x = uptime();   
	while(i < n){
		pid = fork();
		if(pid < 0){
			printf(1, "%d failed in fork\n", getpid());
		}
		else if(pid == 0){
			//printf(1, "child %d is created\n", getpid());
			for(l = 0; l < 8000000000.0; l++)
			    m = m*m;   //calculation to consume cpu time
			break;
		}
		else{	//parent
			printf(1, "parent %d is creating child %d\n", getpid(), pid);
			wait();
		}
		i++;
		
	}	
	int y = uptime();
	
	int throughput = n/(y-x);
	printf(1,"Throughput: %d",throughput);
	
	exit();
}

