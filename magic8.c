#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (argv[argc-1][strlen(argv[argc-1])-1] != '?')	// Check if the last character is not equals '?'
	{
		fprintf(stderr, "You need to ask first!\n");
		return -1;
	}

	srand(time(NULL));

	char *result = malloc(27);

	uint8_t answer = rand() % 20;
	uint8_t *pAnswer = &answer;

	switch(*pAnswer)
	{
		case 0:
			strcpy(result, "It is certain.");
			break;
		case 1:
			strcpy(result, "It is decidedly so.");
			break;
		case 2:
			strcpy(result, "Without a doubt.");
			break;
		case 3:
			strcpy(result, "Yes definitely.");
			break;
		case 4:
			strcpy(result, "You may rely on it.");
			break;
		case 5:
			strcpy(result, "As I see it, yes.");
			break;
		case 6:
			strcpy(result, "Most likely.");
			break;
		case 7:
			strcpy(result, "Outlook good.");
			break;
		case 8:
			strcpy(result, "Yes.");
			break;
		case 9:
			strcpy(result, "Signs point to yes.");
			break;
		case 10:
			strcpy(result, "Reply hazy, try again.");
			break;
		case 11:
			strcpy(result, "Ask again later.");
			break;
		case 12:
			strcpy(result, "Better not tell you now.");
			break;
		case 13:
			strcpy(result, "Cannot predict now.");
			break;
		case 14:
			strcpy(result, "Concentrate and ask again.");
			break;
		case 15:
			strcpy(result, "Don't count on it.");
			break;
		case 16:
			strcpy(result, "My reply is no.");
			break;
		case 17:
			strcpy(result, "My sources say no.");
			break;
		case 18:
			strcpy(result, "Outlook not so good.");
			break;
		case 19:
			strcpy(result, "Very doubtful.");
			break;
	}
	printf("%s\n", result);
	free(result);
	return 0;
}
