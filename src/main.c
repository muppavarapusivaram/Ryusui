#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
char input[100];
  // TODO: Uncomment the code below to pass the first stage

while(1)
{
   printf("$ ");

if(fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}

input[strcspn(input, "\n")] = '\0';

if(strcmp(input, "exit") == 0)
break;

if(strlen(input) == 0)
{
continue;
}


//The implementation of echo
if(strncmp(input, "echo", 4) == 0)
{
		char *echo_args = input + 4;

while(*echo_args == ' ')
	echo_args++;

printf("%s\n", echo_args);

	}

else
{
	printf("%s: command not found\n", input);
}
}
  return 0;
}
