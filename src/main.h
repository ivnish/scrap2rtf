/* scrap2rtf - a simple program to convert Shell Scrap Object File to Rich Text Format
   Copyright (C) 2009-2014 Andrey Ivnitsky.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Andrey Ivnitsky <ivnitsky.a@gmail.com> */

#include "common_func.h"
#include "common_head.h"

int bVerbose = 0;		            /* Verbose output */
int bRemOrig = 0;		            /* Remove original scrap */
string szOutputDir;                 /* Directory for output files */
string szTempDir;                   /* Temp directory */
int bSameDir = 0;                   /* Convert files to same dir where the scrap */
#define NOTSCRAP 0                  /* Scrap type */
#define DOC_DOCX 1                  /* Scrap type */
#define XLS 2                       /* Scrap type */
#define XLSX 3                      /* Scrap type */

#ifdef MUSTDIE
string szPathToExe;					/* Only for windows: path to exe */
#endif

/* Factor out some of the common --help and --version processing code.  */
/* These enum values cannot possibly conflict with the option values
   ordinarily used by commands, including CHAR_MAX + 1, etc. Avoid
   CHAR_MIN - 1, as it may equal -1, the getopt end-of-options value.  */
enum
{
  GETOPT_HELP_CHAR = (CHAR_MIN - 2),
  GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
};
