#ifndef MAIN_H
#define MAIN_H

#include "head.h"
#include "helpers.h"

int bVerbose = 0;     /* Verbose output */
int bRemOrig = 0;     /* Remove original scrap */
string szOutputDir;   /* Directory for output files */
string szTempDir;     /* Temp directory */
int bSameDir = 0;     /* Convert files to same dir where the scrap */
#define NOTSCRAP 0    /* Scrap type */
#define DOC_DOCX 1    /* Scrap type */
#define XLS 2         /* Scrap type */
#define XLSX 3        /* Scrap type */

#ifdef MUSTDIE
string szPathToExe;   /* Only for windows: path to exe */
#endif

/* Factor out some of the common --help and --version processing code.  */
/* These enum values cannot possibly conflict with the option values
   ordinarily used by commands, including CHAR_MAX + 1, etc. Avoid
   CHAR_MIN - 1, as it may equal -1, the getopt end-of-options value.  */
enum {
  GETOPT_HELP_CHAR = (CHAR_MIN - 2),
  GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
};

#endif // MAIN_H
