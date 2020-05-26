#include "main.h"

/* Short options */
static char const short_options[] = "vrso:";

/* Long options */
static struct option const long_options[] = {
  {"verbose", no_argument, NULL, 'v'},
  {"remove-original", no_argument, NULL, 'r'},
  {"output-directory", required_argument , NULL, 'o'},
  {"same-directory", no_argument , NULL, 's'},
  {"help", no_argument, 0, GETOPT_HELP_CHAR},
  {"version", no_argument, 0, GETOPT_VERSION_CHAR},
  {NULL, 0, NULL, 0}
};
//========================================================================

/* "Usage" function */
void usage (int status) {
  if (status != EXIT_SUCCESS) {
    cout << _("Try '"PROGRAM_NAME" --help' for more information.") << endl;
  }
  else {
    cout << _("Usage: "PROGRAM_NAME" [OPTION]... [FILE]...") << endl << endl;
    cout << _("Convert Shell Scrap Object File to Rich Text Format.") << endl << endl;
    cout << _("  -r, --remove-original       remove original scrap file") << endl;
    cout << _("  -v, --verbose               verbosely list files processed") << endl;
    cout << _("  -o, --output-directory      output directory") << endl;
    cout << _("  -s, --same-directory        convert files into the same directory where the scrap") << endl;
    cout << _("      --help                  display this help and exit") << endl;
    cout << _("      --version               output version information and exit") << endl << endl;
    cout << _("Report "PROGRAM_NAME" bugs to "EMAIL) << endl;
    cout << _(PROGRAM_NAME" home page: <"URL">") << endl;
    cout << _("General help using GNU software: <http://www.gnu.org/gethelp/>") << endl;
  }

  exit (status);
}
//========================================================================

/* Analyze the type of scrap:
   Check for extracting it does not do, if the file is not scrap and not
   archive, the function returns NOTSCRAP */
int scrapAnalize(const string szFileName) {
  #ifdef LINUX
    string szSystem = "/usr/bin/7z x -o" + szTempDir + " -y \"" + szFileName + "\" > /dev/null";
  #elif defined MUSTDIE
    string szSystem = "if 1==1 \"" + szPathToExe + "\\7z.exe\" x -o\"" + szTempDir + "\" -y \"" + szFileName + "\" > NUL";
  #endif

  system(szSystem.c_str());

  /* If [3]ITEM000FMTRich Text Format exists, then
     it is word 2003 or 2007 or 2010 */
  if (FileExists(szTempDir + "/[3]ITEM000FMTRich Text Format")) {
    if (bVerbose) {
      cout << _(PROGRAM_NAME": File ") << szFileName << _(" was created in the MS Word 2003/2007/2010") << endl;
    }

    return DOC_DOCX;
  }
  /* Else if Workbook exists, then it is Excel 2003  */
  else if (FileExists(szTempDir+"/[3]ITEM000/Workbook")) {
    if (bVerbose) {
      cout << _(PROGRAM_NAME": File ") << szFileName << _(" was created in the MS Excel 2003") << endl;
    }

    return XLS;
  }
  /* Else if Package exists, then it is Excel 2007/2010  */
  else if (FileExists(szTempDir+"/[3]ITEM000/Package")) {
    if (bVerbose) {
      cout << _(PROGRAM_NAME": File ") << szFileName << _(" was created in the MS Excel 2007/2010") << endl;
    }

    return XLSX;
  }
  /* Sorry, it is not scrap */
  else {
    cerr << PROGRAM_NAME": " << szFileName << _(": File is not a scrap") << endl;

    return NOTSCRAP;
  }
}
//========================================================================

/* Convert to RTF */
void Convert2RTF(const string szFileName) {
  /* Set a path for the future RTF */
  string szRTFfileName = szOutputDir + "/" + ExtractFileNameNoExt(szFileName) + ".rtf";

  ifstream InputFile((szTempDir + "/[3]ITEM000FMTRich Text Format").c_str(), ios::in | ios::binary);
  ofstream OutputFile(szRTFfileName.c_str(), ios::binary | ios::out);
  InputFile.seekg(4);
  OutputFile << InputFile.rdbuf();

  if (bVerbose) {
    cout << PROGRAM_NAME": " << _("File ") << szFileName << _(" was successfully converted to file ") << szRTFfileName << endl;
  }

  return;
}
//========================================================================

/* Convert to XLS */
void Convert2XLS(const string szFileName) {
  /* Set a path for the future XLS */
  string szXLSfileName = szOutputDir + "/" + ExtractFileNameNoExt(szFileName) + ".xls";

  MyCopyFile(szTempDir+"/[3]ITEM000/Workbook", szXLSfileName.c_str());

  if (bVerbose) {
    cout << PROGRAM_NAME": " << _("File ") << szFileName << _(" was successfully converted to file ") << szXLSfileName << endl;
  }

  return;
}
//========================================================================

/* Convert to XLSX */
void Convert2XLSX(const string szFileName) {
  /* Set a path for the future XLSX */
  string szXLSXfileName = szOutputDir + "/" + ExtractFileNameNoExt(szFileName) + ".xlsx";

  MyCopyFile(szTempDir+"/[3]ITEM000/Package", szXLSXfileName.c_str());

  if (bVerbose) {
    cout << PROGRAM_NAME": " << _("File ") << szFileName << _(" was successfully converted to file ") << szXLSXfileName << endl;
  }

  return;
}
//========================================================================

/* Selecting a particular conversion method based on the scrap type */
void scrapConvert(const string szFileName, int nScrapFormat) {
  switch (nScrapFormat) {
    case DOC_DOCX:
      Convert2RTF(szFileName);
      break;
    case XLS:
      Convert2XLS(szFileName);
      break;
    case XLSX:
      Convert2XLSX(szFileName);
      break;
  }

  return;
}
//========================================================================

/* Process files function */
void processFiles(const string szFileName) {
  /* Create temp directory */
  #ifdef LINUX
    szTempDir = mkdtemp(strdup("/tmp/scrap2rtf-XXXXXX"));
  #elif defined MUSTDIE
    /* What a pair of crutches. Windows - sludge %) */
    char buf[MAX_PATH];
    GetTempPathA(MAX_PATH, buf);
    szTempDir = buf;
    szTempDir += tmpnam(NULL);
    szTempDir += "scrap2rtf";
    CreateDirectoryA(szTempDir.c_str(), NULL);
  #endif

  /* Scrap analize */
  int nScrapFormat = scrapAnalize(szFileName);

  /* Convert */
  if (nScrapFormat != NOTSCRAP) {
    /* Convert files in same dir where scraps */
    if (bSameDir == 1) {
      szOutputDir = ExtractFilePath(szFileName);
    }

    scrapConvert(szFileName, nScrapFormat);

    /* Delete the original, if you specify the appropriate option */
    if (bRemOrig) {
      if (remove(szFileName.c_str()) != 0) {
        cerr << PROGRAM_NAME << ": " << _("Cannot remove original scrap ") << szFileName << endl;
      }
      else if (bVerbose) {
        cout << PROGRAM_NAME": " << _("File ") << szFileName << _(" was successfully removed") << endl;
      }
    }
  }
}
//========================================================================

/* SUDDENLY! The main function :) */
int main (int argc, char **argv) {
  /* Set up a locale. Only for Linux, since Windows console
    is ugly and non-Unicode out of box */
  #ifdef LINUX
    setlocale (LC_ALL, "");
    bindtextdomain (PROGRAM_NAME, "/usr/share/locale");
    textdomain (PROGRAM_NAME);
  #endif

  szOutputDir = ".";   /* The default directory for the processed scraps - this is the current */
  int optc = 0;        /* Option code */

  /* Process long options */
  while ((optc = getopt_long (argc, argv, short_options, long_options, NULL)) != -1) {
    switch (optc) {
      case 'v':
        bVerbose = 1;
        break;
      case 'r':
        bRemOrig = 1;
        break;
      case 'o':
        szOutputDir = optarg;
        break;
      case 's':
        bSameDir = 1;
        break;
      case GETOPT_HELP_CHAR:
        usage (EXIT_SUCCESS);
        break;
      case GETOPT_VERSION_CHAR:
        cout << PROGRAM_NAME << " " << VERSION << endl;
        cout << "Copyright (C) 2009-2020 "AUTHORS << endl;
        cout << _("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.") << endl;
        cout << _("This is free software: you are free to change and redistribute it.") << endl;
        cout << _("There is NO WARRANTY, to the extent permitted by law.") << endl << endl;
        cout << _("Written by ") << AUTHORS << endl; exit(EXIT_SUCCESS);
        break;
      default:
        usage (EXIT_FAILURE);
        break;
    }
  }

  /* If the directory for the processed scraps was specified */
  if (szOutputDir != ".") {
    /* If the directory for the processed scraps not exists */
    if (FileExists(szOutputDir) == false) {
      cerr << PROGRAM_NAME << ": " << _("Output directory not found, use current directory") << endl;
      szOutputDir = ".";
    }
  }

  /* if 7z not found */
  #ifdef LINUX
    if (FileExists("/usr/bin/7z") == false) {
      cerr << PROGRAM_NAME << ": " << _("7z not found, please run \"sudo apt-get install p7zip-full\"") << endl;
      exit (EXIT_FAILURE);
    }
  #elif defined MUSTDIE
    szPathToExe = ExtractFilePath(argv[0]);

    if (FileExists(szPathToExe+"\\7z.exe") == false) {
      cerr << PROGRAM_NAME << ": " << _("7z not found, please reinstall application") << endl;
      exit (EXIT_FAILURE);
    }
  #endif

  string infile = "-";

  do {
    /* If the files are */
    if (optind < argc) {
      infile = argv[optind];
      processFiles(infile);
    }
    /* If no files are */
    else if (infile == "-") {
      #ifdef LINUX
        /* Temp file name*/
        string szFilename = "/tmp/";
        szFilename += mkdtemp(strdup("scrapXXXXXX"));
        szFilename += ".shs";
        /* Create temp file*/
        ofstream OutputFile(szFilename.c_str(), ios::out | ios::binary);
        char ch;
        /* Read from stdin */
        while ( cin.get(ch) ) {
          OutputFile.put(ch);
        }
        /* Save file */
        OutputFile.close();
        /* and process it */
        processFiles(szFilename);
      #elif defined MUSTDIE
        cout << _("Sorry, but in the windows version streams processing is not yet implemented") << endl;
      #endif
    }
  }

  while (++optind < argc);

  return EXIT_SUCCESS;
}
//========================================================================
