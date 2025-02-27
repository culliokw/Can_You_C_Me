#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(){
	char str[MAX_SIZE];
	char *pBuffer = malloc(MAX_SIZE * sizeof(char));
	int numRails;
	if (pBuffer == NULL) {
		printf("Error occurred.  Try again.\n");
		free(pBuffer);
		return 0;
	}
	
	// Accept message to decipher from stdin (up to 1000 characters) and properly assign to buffer array choosing fgets for the secure bounded check over a call to gets
	printf("Enter your string to Decipher: ");
	fgets(pBuffer,sizeof(str),stdin);
	pBuffer[strcspn(pBuffer,"\n")] = '\0';

	// Accept the row length parameter for performing the transposition and wrapping the message in the enciphered matrix
	printf("Enter your number of rails: ");
	scanf("%d",&numRails);

	// Initialize deciphered text array to hold the deciphered output
	char plaintext[strlen(pBuffer)];

	// Fill the rail matrix with newline characters to resemble empty rail fence matrix
	char decryptRail[numRails][strlen(pBuffer)];
	for(int i = 0; i < numRails; i++){
		for (int j = 0; j < strlen(pBuffer); j++){
			decryptRail[i][j] = '\n';
	      	}
	}

	// Determine the direction of movement for moving across rails (rows) and fill the rail matrix accordingly 
	int move = -1;
	int row = 0;
        int col = 0;
	// Mark the appropriate places with placeholder '*'
	for(int i = 0; i < strlen(pBuffer); i++) {
		if (row == 0 || row == numRails - 1) {
			move = move * (-1);
	      	}
		decryptRail[row][col++] = '*';
	        row = row + move;
	}

	// Using the supplied enciphered text we can recreate the rail fence to be on our way to recovering the original message
	int index = 0;
	for(int i = 0; i < numRails; i++) {
		for(int j = 0; j < strlen(pBuffer); j++) {		 
			if (decryptRail[i][j] == '*' && index < strlen(pBuffer)) {
		        	decryptRail[i][j] = pBuffer[index++];
		 	}
	      	}
	}
	
	// We now traverse through the rail matrix and read out our characters in the appropriate order to reveal the plaintext
	move = -1;
	row = 0, col = 0;
	index=0;
	for(int i = 0; i < strlen(pBuffer); i++) {
		if (row == 0 || row == numRails - 1) { 
			move = move * (-1);
		}

	      	if (decryptRail[row][col] != '*') {
			printf("%c",decryptRail[row][col++]);
	      	}
	      	row = row + move;
	}

	// Free up our memory and voila we have our secret message in the clear
	free(pBuffer);
	return 0;
}
