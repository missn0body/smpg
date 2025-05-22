#include "../lib/include.h"
#include "../lib/fops.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "%s: too few arguments, try \"--help\"\n", argv[0]);
		return EXIT_FAILURE;
	}

	char *programname = argv[0];
	for(int i = 1; i < argc; i++)
	{
		printf("%s: %s %s ", programname, argv[i], fileexist(argv[i]) ? "exists" : "does not exist");

		if(fileexist(argv[i])) printf("(%s), reported at %lu bytes", fileext(argv[i]), filesize(argv[i]));
		putchar('\n');
	}

	return EXIT_SUCCESS;
}
