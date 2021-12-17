#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    
    pid_t pid;
    int ppid = getpid();
    
    for(int i=0; i<5;i++){
        pid = fork();
        
        if(pid<0){
		  printf("Fallo la instruccion fork()\n");
		  return 2;
            
	   }else if(pid == 0){
            printf("Soy hijo con PID %d y mi padre tiene PID %d \n", getpid(), ppid);
	   }else{
            wait(NULL); 
            return 0;
        } 
    }
}
