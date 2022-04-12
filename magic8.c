#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (argv[argc-1][strlen(argv[argc-1])-1] != '?')	// This was not a problem
	{
		fprintf(stderr, "You need to ask first!\n");
		return 1;
	}

	char *result = malloc(27);
	char **pResult = &result;
	short answer = rand() % 20;
	short *pAnswer = &answer;

	switch(*pAnswer)
	{
		case 0:
			strcpy(*pResult, "It is certain.");
			break;
		case 1:
			strcpy(*pResult, "It is decidedly so.");
			break;
		case 2:
			strcpy(*pResult, "Without a doubt.");
			break;
		case 3:
			strcpy(*pResult, "Yes definitely.");
			break;
		case 4:
			strcpy(*pResult, "You may rely on it.");
			break;
		case 5:
			strcpy(*pResult, "As I see it, yes.");
			break;
		case 6:
			strcpy(*pResult, "Most likely.");
			break;
		case 7:
			strcpy(*pResult, "Outlook good.");
			break;
		case 8:
			strcpy(*pResult, "Yes.");
			break;
		case 9:
			strcpy(*pResult, "Signs point to yes.");
			break;
		case 10:
			strcpy(*pResult, "Reply hazy, try again.");
			break;
		case 11:
			strcpy(*pResult, "Ask again later.");
			break;
		case 12:
			strcpy(*pResult, "Better not tell you now.");
			break;
		case 13:
			strcpy(*pResult, "Cannot predict now.");
			break;
		case 14:
			strcpy(*pResult, "Concentrate and ask again.");
			break;
		case 15:
			strcpy(*pResult, "Don't count on it.");
			break;
		case 16:
			strcpy(*pResult, "My reply is no.");
			break;
		case 17:
			strcpy(*pResult, "My sources say no.");
			break;
		case 18:
			strcpy(*pResult, "Outlook not so good.");
			break;
		case 19:
			strcpy(*pResult, "Very doubtful.");
			break;
	}

	printf("%s\n", *pResult);
	free(*pResult);
	short karma = *pAnswer < 10 ? 5 : *pAnswer > 14 ? 0 : -10;
	short *pKarma = &karma;

	FILE *fp = fopen("karma.txt", "a+");
	double n;
	fscanf(fp, "%lf", &n);
	*pKarma += n;

	fprintf(fp, "%d\n", *pKarma);
	fclose(fp);
	printf("Your karma is %d\n", *pKarma);
	return 0;
}
