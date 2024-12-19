#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000


int main()
{

	char str[MAX_SIZE];
	int i, j;
	char *buffer = malloc(MAX_SIZE * sizeof(char));
	char revChar;
	
	if (buffer == NULL) {
		return 0;
	}
	
	//We need to obtain the message to reverse from stdin and properly assign to our newly allocated buffer as well as cast end of line to null-terminated char for reversal purposes
	printf("Enter your string to reverse: ");
	fgets(buffer,sizeof(str),stdin);

	
	buffer[strcspn(buffer, "\n")] = '\0';
	
	//Perform the reversal by stepping through the string array of our initial message and swapping the characters based upon index vars traversing the pointer
	j = strlen(buffer)-1;
	i=0;

	while(j>i){
		revChar = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = revChar;
		i++;
		j--;	
	}
	
	// Voila, we (kind of) have our secret message now and we can clean up.
	printf("Reversed string is: BEGIN:%s:END\n",buffer);
	free(buffer);
	return 0;

}
