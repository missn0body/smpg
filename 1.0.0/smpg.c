#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Standard size for allocating memory
static constexpr short BUFSIZE = 256;

// These are the two places we can expect the Unix dictionary to be
static const char *trypath_first  = "/usr/share/dict/words";
static const char *trypath_second = "/usr/dict/words";

int main(int argc, char *argv[])
{
	if(argc < 2) { fprintf(stderr, "%s: too few arguments, try \"--help\"\n", argv[0]); return EXIT_FAILURE; }

	// To flag if user wants to submit their own dictionary
	bool userdict = false;

	printf("Hello world!\n");
	return EXIT_SUCCESS;
}
