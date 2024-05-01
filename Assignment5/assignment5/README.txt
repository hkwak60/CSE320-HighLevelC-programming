The following code is a simple mock version of a client and server behavior. 
Make sure you have the following files:
'client.c','server.c', 'util.c' and 'util.h' for the program to be compiled and executed. 
Below are steps for execution.

1. The Makefile contains the command for compiling and creating two runnable files
2. Compile and create run files for both server.c and client.c
3. Run the server file first, then the client file on seperate terminals
  -since the server will create a socket first and listen
4. Both terminals will allow to take input multiple times, but it will have to receive some input for it to display
other inputed text
5. Enter 'exit' on either server or client to terminate the connection
6. Wait for some time(10seconds) before the next activation of server
7. The progarm will automatically shut down when the length is over 50 characters long