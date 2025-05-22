#ifndef smpg__fops__h
#define smpg__fops__h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
	(potentially) Common file operations, may be used for future projects.
	Made by anson in 2025, see LICENSE for related details
*/

#include "include.h"

int 		fileexist	(const char *);
off_t		filesize	(const char *);
const char *	fileext		(const char *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* smpg__fops__h */
