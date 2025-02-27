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
	
	// Accept message to encipher from stdin (up to 1000 characters) and properly assign to buffer array choosing fgets for the secure bounded check over a call to gets
	printf("Enter your string to Encipher: ");
	fgets(pBuffer,sizeof(str),stdin);
	pBuffer[strcspn(pBuffer,"\n")] = '\0';

	// Accept the row length parameter for performing the transposition and wrapping the message in the enciphered matrix
	printf("Enter your number of rails: ");
	scanf("%d",&numRails);

	// Initialize ciphertext array to hold our enciphered output
	char ciphertext[strlen(pBuffer)];
	
	// Create our rail fence matrix
	char rail[numRails][strlen(pBuffer)];

	// Fill the rail matrix with newline characters to resemble empty initial array before characters placed
	for(int i = 0; i < numRails; i++) {
		for (int j = 0; j < strlen(pBuffer); j++){
			rail[i][j] = '\n';
	      	}
	}

        // Determine the direction of movement for moving across rails (rows) during enciphering and fill the rail matrix accordingly
	int moveDown = -1;
	int row = 0;
       	int col = 0;
	for(int i = 0; i < strlen(pBuffer); i++) {
		if (row == 0 || row == numRails - 1) {
			moveDown = moveDown * (-1);
	      	}
	      	rail[row][col++] = pBuffer[i];
	      	row = row + moveDown;
	}
	
	// Using the zigzag character placement, we now compose our enciphered text
	int index = 0;
	for(int i = 0; i < numRails; i++) {
		for(int j = 0; j < strlen(pBuffer); j++){
			if (rail[i][j] != '\n') {
		    		ciphertext[index++] = rail[i][j];
		 	}
	      	}
	}

        // Print out our enciphered text for the user
	printf("BEGIN:");
	for(int i = 0; i < sizeof(ciphertext); i++){
		printf("%c",ciphertext[i]);
	}
	printf(":END\n");

	// Free up our memory and voila we return with our secret message
	free(pBuffer);
	return 0;
}
