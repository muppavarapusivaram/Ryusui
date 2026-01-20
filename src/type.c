#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
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
    
    // 1. Check if it's a builtin
    if(is_builtin_command(args[1])) {
        printf("%s is a shell builtin\n", args[1]);
        return 0;
    }
    
    // 2. Check if it's an executable in PATH
    char *path_env = getenv("PATH");
    if (path_env != NULL) {
        char *path_copy = strdup(path_env);
        if (path_copy != NULL) {
            char *dir = strtok(path_copy, ":");
            
            while (dir != NULL) {
                // Build full path: dir + "/" + command
                char full_path[1024];
                snprintf(full_path, sizeof(full_path), "%s/%s", dir, args[1]);
                
                // Check if file exists and is executable
                if (access(full_path, X_OK) == 0) {
                    printf("%s is %s\n", args[1], full_path);
                    free(path_copy);
                    return 0;
                }
                
                dir = strtok(NULL, ":");
            }
            
            free(path_copy);
        }
    }
    
    // 3. Not found
    printf("%s: not found\n", args[1]);
    return 0;
}
