#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argv[argc - 1][strlen(argv[argc - 1]) - 1] != '?')	// Check if the last character is not equals '?'
	{
		fprintf(stderr, "You need to ask first! (add a question mark at the end)\n");
		return EXIT_FAILURE;
	}

	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
	// Using nanoseconds instead of seconds.
	srand((time_t)ts.tv_nsec);

	int guess = rand() % 20;
	const char *answers[] =
	{
		"It is certain",
		"It is decidedly so",
		"Without a doubt",
		"Yes definitely",
		"You may rely on it",
		"As I see it, yes",
		"Most likely",
		"Outlook good",
		"Yes",
		"Signs point to yes",
		"Reply hazy, try again",
		"Ask again later",
		"Better not tell you now",
		"Cannot predict now",
		"Concentrate and ask again",
		"Don't count on it",
		"My reply is no",
		"My sources say no",
		"Outlook not so good",
		"Very doubtful"
	};

	printf("%s.\n", answers[guess]);
	return EXIT_SUCCESS;
}
