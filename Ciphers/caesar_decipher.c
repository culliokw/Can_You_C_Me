#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main()
{

	// Initialize our extended symbol list for all characters that can be deciphered
	const char *SYMBOLS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 !?.";
	char str[MAX_SIZE];

	char *pStrBuffer = malloc(MAX_SIZE * sizeof(char));
	int pKey;
	char *pCheckedKey;
	char *pOriginalBuffer;
	char *pCheckedSymbol;
        int newSymbolIndex;


	if (pStrBuffer==NULL) {
    		free(pStrBuffer);
        	printf("Error occurred.  Try again.\n");
        	return 0;
        }

	// Accept message to decipher from stdin (up to 1000 characters) and properly assign to buffer array choosing fgets for the secure bounded check over a call to gets
	printf("Enter the String to Decrypt: ");
	fgets(pStrBuffer,sizeof(str),stdin);
	
	
	// Allow user to see the extended symbol list as well as obtain the key being used in the decipher step.  We terminate if key less than 0 or greater than the number of available symbols to adhere to proper Caesar Cipher methodology
	printf("KEY SYMBOL LIST (EXTENDED): %s\n", SYMBOLS);
	printf("Enter the symbol key you want to use for Decryption: ");
	scanf("%d",&pKey);
	if (pKey < 0 || pKey > strlen(SYMBOLS)){
		free(pStrBuffer);
		printf("Not a valid key.\n");
		return 0;
	}
	
	//Cast the end of line character obtained from stdin to null-terminated character to allow proper usage of symbol comparisons.  Also need to assign the message to another char pointer for memory deallocation cleanup if error encountered or successful enciphering
	pStrBuffer[strcspn(pStrBuffer,"\n")] = '\0';

	pOriginalBuffer = ptrStrbuffer;

	while(*pStrBuffer != '\0'){
		
		pCheckedSymbol = strchr(SYMBOLS, *pStrBuffer); 
		
		if (pCheckedSymbol == NULL){
			printf("Symbol not found");
			free(pOriginalBuffer);

			return 0;
		}

		newSymbolIndex = ((((pCheckedSymbol-SYMBOLS)-(pKey)))+strlen(SYMBOLS))%(strlen(SYMBOLS));
		
		*pStrBuffer=SYMBOLS[newSymbolIndex];

		pStrBuffer++;
	}

	// Voila, we now have uncovered secrets and we also clean up
	printf("Final Message: BEGIN:%s:END\n",pOriginalBuffer);
	free(pOriginalBuffer);
	return 0;

}
