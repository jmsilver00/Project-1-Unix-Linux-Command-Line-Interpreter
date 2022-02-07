//Jacob Silveira and Jose Castillo
//CST-315
//Project 1: Unix/Linux Command Line Interpreter
//The function of this program is to be a command line interpreter,after running the program the user should see text promting them for a command such as "ls"

//includes 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //for using fork() and execve()
#include <errno.h> //include for handling errors
#include <sys/wait.h> //def for wait() function

//for getline()
char *input = NULL;
size_t cap = 0; //the capacity
//the declaration for strtok() which will take non-blank inputs and break them into tokens separated by the delimiter space	
int i;
char *token;
char *array[512]; 

//Prompting the user for an input command	
void startCML(){
printf("COMMAND LINE INTERPETER FOR UNIX/LINUX TERMINAL\n");
printf("TO EXECUTE A COMMAND TYPE IN A COMMAND AND PRESS ENTER\n");
printf("*EXAMPLE: ls\n");
printf("*TO EXIT TYPE 'e' THEN ENTER\n");
	
}
//to show that a new shell is in use
void userPrompt(){
printf("NEW_SHELL: ");
}
//here the input line is divided into tokens
void makeTokens(char *input){
	i = 0;
	token = strtok(input, "\n "); //the input
		while (token != NULL) { 
			array[i++] = token; //adding tokens to the array
			token = strtok(NULL, "\n ");
		}
	array[i] = NULL;
}

//command execution
void execute(){
	int pid = fork(); //creating a new child process
		if (pid != 0) { //if process was not completed
			int s;
			waitpid(-1, &s, 0); //wait for process termination
		} 
    else {
			if(execvp(array[0], array) == -1){ //here of -1 is returned then we know something went wrong, if not then we know that the command has completed successfully
			perror("Wrong command"); //shows error
			exit(errno);
		}				
	}
}
   
//main
int main(){
	startCML(); //starting command line
	while(1){
		userPrompt(); // Display a user prompt
		getline(&input, &cap, stdin); // Read the user input
		/* Check if input is empty */
			if(strcmp(input,"\n")==0){
				perror("Please type in a command");
				continue;
	}
	
	makeTokens(input); // Divide line into tokens 
  //this checks if the user input is e, if so then the shell is closed
	if (strcmp(array[0], "e") == 0) {
		printf("SYSTEM: Shell has been left\n"); //tells user they have exited 
		return 0;
	}
	execute(); //calling execvp()

 }
		
}
