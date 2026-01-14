#include<stdio.h>
#include<string.h>
#include "builtins.h"

int is_builtin_command(const char *cmd_name) {
    for(int i = 0; i < num_builtins(); i++) {
        if(strcmp(cmd_name, builtins[i].name) == 0) {
            return 1;
        }
    }
    
    if(strcmp(cmd_name, "exit") == 0) {
        return 1;
    }
    
    return 0;
}

int type_builtin(char **args) {
    if(args[1] == NULL) {
        printf("type: missing argument\n");
        return 1;
    }
    
    if(is_builtin_command(args[1])) {  // FIXED: Added closing parenthesis
        printf("%s is a shell builtin\n", args[1]);  // FIXED: Correct message
    } else {
        printf("%s: not found\n", args[1]);  // FIXED: Correct message for not found
    }
    
    return 0;
}
