
# Simple Shell Project

It is known as Command Line Interpreter, program that accepts commands from the keyboard and then executes either by itself or by passing it on to the operating system.

![](https://raw.githubusercontent.com/Edigi12Hbtn/simple_shell/master/Shell.png)

#### Clone Repository with HTTPS

Use Git or checkout with SVN using the web URL.
```
git clone https://github.com/Edigi12Hbtn/simple_shell.git
```
#### Requeriments
* All files will be compiled on Ubuntu 14.04 LTS
* The C programs and functions will be compiled with gcc 4.8.4 

#### Compile (Install)

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

#### Syntax
```
#cisfun$ command [-flag or -option] [arguments,  files or  directories]
```

### How to use
shell should work like this in interactive mode:
```
$ ./hsh
#cisfun$ echo "Hello World"
"Hello World"
#cisfun$
```


But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
#cisfun$ echo "Hello World"
"Hello World"
#cisfun$
```

### Files and Functions

| Name  | Description |
| ------------- | ------------- |
| **Env.c** | Function that prints system environment variables on standard output  | 
| **Exit.c** |Function to produce the termination of the current process. |
| **Holberton.h** |  It's a file which contains all the constants, macros, system wide global variables, and function prototypes | 
| **PATH_dirs.c	** | Function that gets the paths where executable files might be. | 
| **_atoi.c	** | Function that converts the character string  to an integer.| 
| **_getenv.c** | Function that gets the value of an environment variable, in this case the PATH variable. | 
| **_realloc.c** | Funtion to resize a block of memory that was previously allocated and and copies the contents of the old block to the new block of memory, if necessary. | 
| **_strdup.c	** | Function allocates memory and copies into it the string addressed by argument, including the terminating null character. | 
| **_strlen.c	** | Function calculates the length of a given string.  Takes a string as an argument and returns its length.  | 
| **call_command.c	** | Function that executes the command with the indicated arguments, also responsible for creating child processes.  | 
|**int_str.c**|Function that Converts an integer value to a null-terminated string|
| **look_for_built_in.c** | Function that according to the reserved word (command) calls a specific function. | 
| **look_for_path.c** | Function that looks for the directory where the program is located. For example / bin, / sbin,  / usr / local / bin... etc.| 
| **man_1_simple_shell** |  The file is a documentation manual that serves as a reference, details what is given and what is required, explains how to put the presented information into practice.  | 
| **print_prompt.c** | Function that display prompt "#cisfun$ "  of shell in terminal"  | 
| **split_arguments.c** | Function that divides the string into tokens. i.e. starting from any one of the delimiter to next .  | 
| **strings_concat.c	** | Function appends a copy of the string pointed to by second string to the end of the string pointed to by first string. It returns a pointer to first string where the resulting concatenated string resides.|

## Authors
Edison Giraldo Aristizabal [![alt text][1.1]][2]
Sergio Steben Arias Quintero [![alt text][1.1]][1]
<!-- links to social media icon -->
[1.1]: http://i.imgur.com/0o48UoR.png (Github)
<!-- links to your social media accounts -->
<!-- update these accordingly -->
[1]: https://github.com/sarias12
[2]: https://github.com/Edigi12Hbtn
