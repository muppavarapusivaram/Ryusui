#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "builtins.h"
// REMOVE: #include "path_utils.h" - this file doesn't exist anymore


char **parse_input(char *input, int *arg_count) {
    static char *args[64];
    int count = 0;
    char *token = strtok(input, " ");


    while(token != NULL && count < 63) {
        args[count++] = token;
        token = strtok(NULL, " ");
    }
    args[count] = NULL;
    *arg_count = count;

    return args;
}

int execute_builtin(char **args, int arg_count) {
    if(arg_count == 0) return -1;

    if(strcmp(args[0], "exit") == 0) {
        return -2;
    }

    for(int i = 0; i < num_builtins(); i++) {
        if(strcmp(args[0], builtins[i].name) == 0) {
            return builtins[i].func(args);
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    char input[100];

    while(1) {
        printf("$ ");

        if(fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if(strlen(input) == 0) {
            continue;
        }

        int arg_count = 0;
        char input_copy[100];
        strcpy(input_copy, input);
        char **args = parse_input(input_copy, &arg_count);

        if(arg_count ==0) {
            continue;
        }

        int result = execute_builtin(args, arg_count);

        if(result == -2) {
            break;
        }
        else if(result == -1) {
            printf("%s: command not found\n", args[0]);
        }
    }

    return 0;
}
