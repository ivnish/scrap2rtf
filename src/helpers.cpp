#include "helpers.h"

/* Extract file extension */
const string ExtractFileExt(const string szFileName) {
  size_t found = szFileName.find_last_of(".");

  /* If extension exists */
  if ((int)found != -1) {
    return szFileName.substr(found+1);
  }
  else {
    return "";
  }
}
//========================================================================

/* Extract file name without extension */
const string ExtractFileNameNoExt(const string szFileName) {
  string szShortName = ExtractFileName(szFileName);

  if (szShortName.empty()) {
    return szFileName;
  }
  else {
    string szExt = ExtractFileExt(szShortName);

    if (szExt.empty()) {
      return szFileName;
    }

    return szShortName.substr(0, szShortName.length()-szExt.length()-1);
  }
}
//========================================================================

/* Extract file path */
const string ExtractFilePath(const string szFileName) {
  size_t found = szFileName.find_last_of("/\\");

  if ((int)found != -1) {
    return szFileName.substr(0,found);
  }
  else {
    return ".";
  }
}
//========================================================================

/* Extract file name */
const string ExtractFileName(const string szFileName) {
  size_t found = szFileName.find_last_of("/\\");

  if ((int)found != -1) {
    return szFileName.substr(found+1);
  }
  else {
    return szFileName;
  }
}
//========================================================================

/* Check if file exists */
bool FileExists(const string szFileName) {
  if (access(szFileName.c_str(),00) != 0) {
    return false;
  }
  else {
    return true;
  }
}
//========================================================================

/* Simple file copy */
void MyCopyFile(const string szSourceFile, const string szDestFile) {
  ifstream fSourceFile(szSourceFile.c_str(), fstream::binary);

  if ((!fSourceFile.is_open()) && (!fSourceFile.good())) {
    cerr << PROGRAM_NAME << ": " << szSourceFile << ": " << _("Cannot open file") << endl;
    exit (EXIT_FAILURE);
  }

  ofstream fDestFile(szDestFile.c_str(), fstream::trunc|fstream::binary);

  if ((!fDestFile.is_open()) && (!fDestFile.good())) {
    cerr << PROGRAM_NAME << ": " << fDestFile << ": " << _("Cannot create file") << endl;
    fSourceFile.close();
    exit (EXIT_FAILURE);
  }

  fDestFile << fSourceFile.rdbuf();

  fSourceFile.close();
  fDestFile.close();
}
//========================================================================
