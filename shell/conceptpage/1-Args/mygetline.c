#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 *main - delimited string input
 *Return: copy of string input
 */
int main(void)
{
	unsigned int len_max = 128;
	unsigned int current_size = len_max;
	char *input = malloc(len_max);

	printf("\nEnter a very very very long string value:");

	if (input != NULL)
	{
		int c = EOF;
		unsigned int i = 0;
		/*accept user input until hit enter or end of file*/
		while ((c = getchar()) != '\n' && c != EOF)
		{
			input[i++] = (char)c;

			/*if i reached maximize size then realloc size*/
			if (i == current_size)
			{
				current_size = i + len_max;
				input = realloc(input, current_size);
			}
		}
		input[i] = '\0';
		printf("\nLong String value:%s\n\n", input);
		free(input);
		input = NULL;
	}
	return (0);
}
