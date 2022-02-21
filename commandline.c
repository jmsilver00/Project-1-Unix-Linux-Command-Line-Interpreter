//Jacob Silveira and Jose Castillo 
//Jacob Silveira
//CST-315
//Project 1: Improved Unix/Linux Command Line Interpreter
//The function of this program is to be a command line interpreter,after running the program the user should see text promting them for a command such as "ls"
//total of 10 commands that can be run one at a time or all in a batch
/*
To compile:
gcc newCML.c
./a.out
*/

//includes 
#include <stdio.h>
#include <string.h> //for string functions
#include <stdlib.h> //general purpose standard library
#include <unistd.h> //for using fork() and execve()
#include <errno.h> //include for handling errors
#include <sys/wait.h> //def for wait() function

//for getline() used for reading strings of text where a buffer is made to hold the contents of a string and return a new line, number of characters and size of new buffer
char *input = NULL;
size_t cap = 0; //the capacity
//the declaration for strtok() which will take non-blank inputs and break them into tokens separated by the delimiter space, the strtok() function is also able to split a string and specify delimiter to use	
int i;
char *token; 
char *array[512]; 

//Prompting the user for an input command	
void createCml(){ //starting the commandline
printf("COMMAND LINE INTERPETER FOR LINUX ubuntu TERMINAL\n");
printf("TO EXECUTE A COMMAND TYPE IN A COMMAND AND PRESS ENTER\n");
printf("*EXAMPLE: ls\n");
printf("*TO EXIT TYPE 'e' THEN ENTER\n");
printf("AVAILABE 10 COMMANDS ARE: \n");
printf("ls\n");
printf("ls-a\n");
printf("id\n");
printf("pwd\n");
printf("cat\n");
printf("exit\n");
printf("clear\n");
printf("echo\n");
printf("df\n");
printf("whoami\n");
}
//to show that a new shell is in use
void usrPrmt(){
printf("NEW_SHELL: ");
}
//here the input line is divided into tokens
void makeToke(char *input){
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
	createCml(); //starting command line
	while(1){
		usrPrmt(); // Display a user prompt
		getline(&input, &cap, stdin); // Read the user input
		/* Check if input is empty */
			if(strcmp(input,"\n")==0){
				perror("Please type in a command"); //lets the user know that the input was left blank and asks for a correct command
				continue;
	}
	makeToke(input); // Divide line into tokens 
  //this checks if the user input is e, if so then the shell is closed
	if (strcmp(array[0], "e") == 0) {
		printf("SYSTEM: Shell has been exited\n"); //tells user they have exited 
		return 0;
	}
	execute(); //calling execvp()

 }
		
}
