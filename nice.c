#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char *argv[]){
	int priority, pid;
	
	(argc < 3) ? (printf(2, "Wrong Input!\nPlease provide input in the form: nice pid priority\n"), exit()) : printf(1, "");
	
	pid = atoi(argv[1]);
	priority = atoi(argv[2]);
	
	(priority < 0 || priority > 20) ? (printf(2, "Invalid priority! give the priority from (0-20)\n"), exit()) : printf(1, "");
	
	chpr(pid, priority);
	exit();
}
