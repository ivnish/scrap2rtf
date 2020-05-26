#ifndef HELPERS_H
#define HELPERS_H

#include "head.h"

/* Extract file extension */
const string ExtractFileExt(const string szFileName);

/* Extract file name without extension */
const string ExtractFileNameNoExt(const string szFileName);

/* Extract file path */
const string ExtractFilePath(const string szFileName);

/* Extract file name */
const string ExtractFileName(const string szFileName);

/* Check if file exists */
bool FileExists(const string szFileName);

/* Simple file copy */
void MyCopyFile(const string szSourceFile, const string szDestFile);

#endif // HELPERS_H
