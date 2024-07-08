# Pipex
This project is about understanding and recreating two mechanisms:
**pipes** and **redirections**

## Mandatory part

### Authorized functions:
	- open, close, read, write,
	malloc, free, perror,
	strerror, access, dup, dup2,
	execve, exit, fork, pipe,
	unlink, wait, waitpid

	- ft_printf and any equivalent
	you coded

### Objectives:

The program will be executed as follows:
```
./pipex file1 cmd1 cmd2 file2
```

It must take 4 arguments:
- *file1* and *file2* are file names.
- *cmd1* and *cmd2* are shell commands with their parameters.

It must behave exactly the same as the shell command below:
```
< file1 cmd1 | cmd2 > file2
```

## Bonus part

- Handle multiple pipes:
```
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
should behave like:
```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

- Support `<<` and `>>` when the first parameter is "here_doc":
```
./pipex here_doc LIMITER cmd1 cmd2 file
```
should behave like:
```
cmd1 << LIMITER | cmd2 >> file
```
