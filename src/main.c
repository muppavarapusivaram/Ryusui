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

char input[100];
if(fgets(input, sizeof(input), stdin) == NULL)
{
printf("\n");
break;
}

input[strcspn(input, "\n")] = '\0';
if(strlen(input) == 0)
{
continue;
}
printf("%s: command not found\n", input);
}
  return 0;
}
