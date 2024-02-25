#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (!argc) return EXIT_FAILURE;
	if (argc < 2) goto fail;
	{
		const size_t last_argument_length = strlen(argv[argc - 1]);
		// Check if the last character does not equal '?'
		if (!last_argument_length || argv[argc - 1][last_argument_length  - 1] != '?')
			goto fail;
	}

	{
		struct timespec ts;
		if (clock_gettime(CLOCK_MONOTONIC, &ts) == -1)
		{
			perror("clock_gettime");
			return EXIT_FAILURE;
		}
		srand(ts.tv_nsec);
	}

	{
		const char * const answers[20] =
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

		printf("%s.\n", answers[rand() % 20]);
	}
	return EXIT_SUCCESS;

fail:
	fprintf(stderr, "You need to ask first! (add a question mark at the end)\n");
	return EXIT_FAILURE;
}
