#include<stdio.h>
#include<string.h>

int echo_builtin(char **args) {
	for(int i = 1; args[i] != NULL; i++) {
		printf("%s", args[i]);
		if(args[i + 1] != NULL) {
			printf(" ");
}
}
	printf("\n");
	return 0;
}
