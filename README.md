# Project-1-Unix-Linux-Command-Line-Interpreter
A command-line interpreter was written in C to be compiled and run in a Linux terminal. It displays in the terminal that the user has switched over to the interpreter. Then based on what command the user enters the interpreter executes it and shows the results. The code is run using the gcc compiler, then the first thing that is processed is the users entered command, if the input is empty it will be sent to the system then the prompt will return, if the input is an actual command or value it will be broken into tokens separated by the delimetier space using the c function strtok(). A child is then made with the fork() command, in the terminal if a commands correct binary is found then the command will be executed, if not then the an error message will appear. 
To compile and run:
1. Have the commandline.c code 
2. In the terminal: gcc commandline.c then ./a.out
3. Now the command line should be running
4. To create and run a batch:
5.  emacs (or other text editor) batch1.sh
6.  chmod +x batch1.sh
7.  ./batch1.sh
8.  To exit the program ctrl+c
