#ifndef BUILTINS_H
#define BUILTINS_H

typedef struct{
	char *name;
	int (*func)(char **);
} BuiltinCommand;

int echo_builtin(char **args);
int type_builtin(char **args);


extern BuiltinCommand builtins[];
extern int num_builtins();

#endif
