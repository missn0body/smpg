#include "../lib/fops.h"

int fileexist(const char *filename)
{
	if(filename == NULL) return -1;
	return (access(filename, F_OK) == 0);
}

off_t filesize(const char *filename)
{
	struct stat sobj;

	if(filename == NULL) return -1;
	if(stat(filename, &sobj) == 0) return sobj.st_size;

	perror("fops_filesize: cannot determine size of file");
	return -1;
}

const char *fileext(const char *filename)
{
	if(filename == NULL) return "";

	const char *retval = strrchr(filename, '.');
	return (retval == NULL) ? "" : retval + 1;
}
