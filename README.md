# Synthesys Practical Work – ENSEA in the Shell (FRANCILLONNE Radji/GAMIETTE David)
Objectives : Develop a tiny shell, that displays exit codes and execution times of launched
programs.

## Q1) Display a welcome message, followed by a simple prompt
We want to display a welcome message in the console without using `printf()`. Therefore, we will use the `write(int output, "message to display", int message length)` function. We will assign the value of the message length to L for readability and understanding.

Note: If L does not match the length of the "message to display," then we will either display the first L characters if L is less than `strlen("message to display")`, or display ASCII characters if L is greater than `strlen("message to display")`.

_`strlen()` is used to return the length of a string passed as an argument to this function._

## Q2) Execution of the entered command and return to the prompt (REPL : read–eval–print-loop)
- read the command entered by user

We use the `scanf("%s", char* buff)` function to read the entered command. In our case, buff points to the entered command.

- execute this command (simple command for the moment, without argument)

The `execvp(char* buff, NULL)` function is employed to execute the command pointed to by buff. The argument is utilized to handle situations where the command is not part of a predefined list of commands provided as the second argument to the `execvp()` function.

- print the prompt enseash % and waits for a new command

The waiting for the new entered command is achieved through the successive creation of new child processes using the `fork()` function.

Note: When `pid_t=0`, it indicates that the process is currently in the child. Therefore, the `wait()` function can be used to make the parent wait for the completion of the child process.

## Q3) Management of the shell output with the command ”exit” or with <ctrl>+d
To answer the question, we will compare the entered command with "exit" using the `strcmp(command, "exit")` function and return 0 if the command is equal to "exit". In this case, we use the `exit(1)` function.

## Q4) Display the return code (or signal) of the previous command in the prompt
By strategically using the `write()` function in the code, we display the desired return code.

## Q5) Measurement of the command execution time using the call clock_gettime
To determine the execution time of the entered command, we will use the `clock_gettime(CLOCK_MONOTONIC, &start)` function, which will store the clock value at the time of its execution in the variable `start`. Therefore, it is sufficient to execute this function twice, once just before our command and the other time just after.
