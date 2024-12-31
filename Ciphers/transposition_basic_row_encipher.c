#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(){
	char str[MAX_SIZE];
	int i, j, bufferIndex=0;
	char *pBuffer = malloc(MAX_SIZE * sizeof(char));
	char encipheredMessage[100][100];
	int rowLength;
	int numRows;
	if (pBuffer == NULL) {
		printf("Error occurred.  Try again.\n");
		free(pBuffer);
		return 0;
	}
	
	// Accept message to encipher from stdin (up to 1000 characters) and properly assign to buffer array choosing fgets for the secure bounded check over a call to gets
	printf("Enter your string to Encipher: ");
	fgets(pBuffer,sizeof(str),stdin);
	pBuffer[strcspn(pBuffer,"\n")] = '\0';

	// Accept the row length parameter for performing the transposition and wrapping the message in the enciphered matrix
	printf("Enter your row length: ");
	scanf("%d",&rowLength);

	// We then need to perform a basic calculation to determine the number of rows to use for indexing purposes in our newly created enciphered message matrix at the start of our program
	numRows = strlen(pBuffer);
	if (numRows % rowLength == 0){
		numRows = numRows / rowLength;
	} else {
		numRows = (numRows/rowLength) +1;

	}

		
	// We then perform the main assignments 
	for (i=0; i < numRows; i++) {
		for (j=0; j < rowLength; j++) {
			if (pBuffer[bufferIndex] == '\0') {
				encipheredMessage[i][j] = '*';
			} else {
				encipheredMessage[i][j] = pBuffer[bufferIndex++];
			
			}
		}
	}		

	//Secrets are shared and now we disappear
	printf("Our enciphered message is: BEGIN:");
	for (j=0; j < rowLength; j++) {
		for (i=0; i < numRows; i++) {
			printf("%c",encipheredMessage[i][j]);
		}
	}
	printf(":END\n");
	
	free(pBuffer);
	return 0;

}
