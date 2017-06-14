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

#define LINUX		/* The great and mighty */
//#define MUSTDIE		/* OS by Microsoft */

/* Common headers */
#include <iostream>
#include <string>
#include <fstream>
#include <getopt.h>
#include <limits.h>
#include <fcntl.h>

/* Linux only headers */
#ifdef LINUX
#include <libintl.h>
#include <string.h>
#include <stdlib.h>
#define _(x) gettext(x)
#endif

/* Windows only headers */
#ifdef MUSTDIE
#include <windows.h>
#include <stdio.h>
#define _(x) x
#endif

using namespace std;

#define PROGRAM_NAME	"scrap2rtf"
#define AUTHORS			"Andrey Ivnitsky"
#define	VERSION			"0.5"
