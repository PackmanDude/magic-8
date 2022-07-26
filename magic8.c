#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void karmaHandle(int answer);

int main(int argc, char *argv[])
{
	srand(time(NULL));

	if (argv[argc-1][strlen(argv[argc-1])-1] != '?')	// Check if the last character is not equals '?'
	{
		fprintf(stderr, "You need to ask first!\n");
		return -1;
	}

	char *result = malloc(27);
	char **pRes = &result;

	short answer = rand() % 20;
	short *pAnswer = &answer;

	switch(*pAnswer)
	{
		case 0:
			strcpy(*pRes, "It is certain.");
			break;
		case 1:
			strcpy(*pRes, "It is decidedly so.");
			break;
		case 2:
			strcpy(*pRes, "Without a doubt.");
			break;
		case 3:
			strcpy(*pRes, "Yes definitely.");
			break;
		case 4:
			strcpy(*pRes, "You may rely on it.");
			break;
		case 5:
			strcpy(*pRes, "As I see it, yes.");
			break;
		case 6:
			strcpy(*pRes, "Most likely.");
			break;
		case 7:
			strcpy(*pRes, "Outlook good.");
			break;
		case 8:
			strcpy(*pRes, "Yes.");
			break;
		case 9:
			strcpy(*pRes, "Signs point to yes.");
			break;
		case 10:
			strcpy(*pRes, "Reply hazy, try again.");
			break;
		case 11:
			strcpy(*pRes, "Ask again later.");
			break;
		case 12:
			strcpy(*pRes, "Better not tell you now.");
			break;
		case 13:
			strcpy(*pRes, "Cannot predict now.");
			break;
		case 14:
			strcpy(*pRes, "Concentrate and ask again.");
			break;
		case 15:
			strcpy(*pRes, "Don't count on it.");
			break;
		case 16:
			strcpy(*pRes, "My reply is no.");
			break;
		case 17:
			strcpy(*pRes, "My sources say no.");
			break;
		case 18:
			strcpy(*pRes, "Outlook not so good.");
			break;
		case 19:
			strcpy(*pRes, "Very doubtful.");
			break;
	}

	printf("%s\n", *pRes);
	free(*pRes);

	karmaHandle(*pAnswer);
	return 0;
}

void karmaHandle(int answer)
{// answers meaning:
//	0..9 — affirmative, 10..14 — non-committal, 15..19 — negative

	int karmaPer = answer < 10 ? 5 : answer > 14 ? 0 : -10;
	int karma = karmaPer;
	int *pKarma = &karma;

	FILE *fp = fopen("karma.txt", "r");

	if (fp == NULL)
	{
		fp = fopen("karma.txt", "w+");
		fputs("0\n", fp);
	}

	rewind(fp);
	int temp;
	fscanf(fp, "%d", &temp);
	*pKarma += temp;

	fp = fopen("karma.txt", "w");
	fprintf(fp, "%d\n", *pKarma);
	fclose(fp);
	printf("Your karma is %d\n", *pKarma);
}
