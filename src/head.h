#ifndef HEAD_H
#define HEAD_H

#define LINUX         /* The great and mighty */
//#define MUSTDIE       /* OS by Microsoft */

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
#include <unistd.h>
#define _(x) gettext(x)
#endif

/* Windows only headers */
#ifdef MUSTDIE
#include <windows.h>
#include <stdio.h>
#define _(x) x
#endif

using namespace std;

#define PROGRAM_NAME    "scrap2rtf"
#define AUTHORS         "Andrei Ivnitskii"
#define VERSION         "0.6"
#define EMAIL           "ivnish.dev@gmail.com"
#define URL             "https://github.com/ivnish/scrap2rtf"

#endif // HEAD_H
