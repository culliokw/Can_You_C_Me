#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(){
	char str[MAX_SIZE];
	int i, j, bufferIndex=0;
	char *pBuffer = malloc(MAX_SIZE * sizeof(char));
	char decipheredMessage[100][100];
	int rowLength;
	int numRows;
	if (pBuffer == NULL) {
		printf("Error occurred.  Try again.\n");
		free(pBuffer);
		return 0;
	}
	
	// Accept message to decipher from stdin (up to 1000 characters) and properly assign to buffer array choosing fgets for the secure bounded check over a call to gets
	printf("Enter your string to Decipher: ");
	fgets(pBuffer,sizeof(str),stdin);
	pBuffer[strcspn(pBuffer,"\n")] = '\0';
	
	// Accept the row length parameter for performing the transposition and wrapping the message in the deciphered matrix
	printf("Enter your row length: ");
	scanf("%d",&rowLength);
	
	// We then need to perform a basic calculation to determine the number of rows to use for indexing purposes in our newly created deciphered message matrix at the start of our program
	numRows = strlen(pBuffer);
	if (numRows % rowLength == 0){
		numRows = numRows / rowLength;
	} else {
		numRows = (numRows/rowLength) +1;

	}

	// We then perform the main assignments
	for (j=0; j < rowLength; j++) {
		for (i=0; i < numRows; i++) {
				decipheredMessage[i][j] = pBuffer[bufferIndex++];
		}
	}		
	
	//Secrets are uncovered and shared and now we disappear
	printf("Our enciphered message is: ");
	for (i=0; i < numRows; i++) {
		for (j=0; j < rowLength; j++) {
			printf("%c",decipheredMessage[i][j]);
		}
	}
	printf("\n");

	free(pBuffer);
	printf("%",decipheredMessage);
	return 0;

}
