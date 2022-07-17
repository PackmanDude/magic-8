#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

void KarmaHandle(int answer);

int main(int argc, char *argv[])
{
	srand(time(NULL));

	// Check if the last character is not equals to '?'
	if (argv[argc-1][strlen(argv[argc-1])-1] != '?')
	{
		fprintf(stderr, "You need to ask first!\n");
		return 5; // EIO
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

	KarmaHandle(*pAnswer);
	return 0;
}

void KarmaHandle(int answer)
{// Answers meaning:
//	0..9 — affirmative; 10..14 — non-committal; 15..19 — negative

	int karmaPer = answer < 10 ? 5 : answer > 14 ? 0 : -10;
//	int karma = karmaPer;
	int *pKarma = *karmaPer;

	FILE *fp = fopen("score.txt", "r");

	// Create a file, if it doesn't exists
	if (fp == NULL)
	{
		fp = fopen("score.txt", "w+");
		fputs("0\n", fp);
	}

	rewind(fp);
	int temp;
	fscanf(fp, "%d", &temp);
	*pKarma += temp;

	fp = fopen("score.txt", "w");
	fprintf(fp, "%d\n", *pKarma);
	fclose(fp);
}

void Handler(int sig)
{
	printf("Your karma is %d\n", *pKarma);
	exit(0);
}

signal (SIGINT, Handler);
