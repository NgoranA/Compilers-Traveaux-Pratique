// open file in read mode and store its reference
// define word to be searched
// initialize a variable count to store the total occurence of the word.
// read line from reference and store phrase in a variable
// increment count by 1 each time the word is found in the string.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

// function delaration
int countOccurences(FILE *fileRead, const char *word);

int main()
{
	FILE *fileRead;
	char *word = "mur";
	char *path;		
	int wordCount;
	// opening the file
	  /* Input file path */
    	printf("Enter file path from which we will search the occurences of the  word 'Mur': ");
    	scanf("%s", path);

    	/* Input word to search in file */
    	//printf("Enter word to search in file: ");
    	//scanf("%s", word);	
	fileRead = fopen(path, "r");
	// be sure that the file has been read

	if (fileRead == NULL)
	{
		printf("unable to open the file.\n");
		exit(EXIT_FAILURE);
	}

	wordCount = countOccurences(fileRead, word);

	printf("'%s' is found %d times in the file\n", word, wordCount);

	fclose(fileRead);

	return 0;
}
int countOccurences(FILE *fileRead, const char  *word)
{

	char str[BUFFER_SIZE];
	char *position;
	int index, count;

	count = 0;

	// Read line in file till the end.
	while ((fgets(str, BUFFER_SIZE, fileRead)) != NULL)
	{
		index = 0;

		while ((position = strstr(str + index, word)) != NULL)
		{
			index = (position - str) + 1;
			count++;
		}
	}
	return count;
}


