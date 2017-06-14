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

/* Extract file extension */
const string ExtractFileExt(const string szFileName)
{
    size_t found = szFileName.find_last_of(".");
    /* If extension exists */
    if ((int)found != -1)
        return szFileName.substr(found+1);
    else
        return "";
}
//========================================================================

/* Extract file name without extension */
const string ExtractFileNameNoExt(const string szFileName)
{
    string szShortName = ExtractFileName(szFileName);
    if (szShortName.empty())
        return szFileName;
    else
    {
        string szExt = ExtractFileExt(szShortName);
        if (szExt.empty())
            return szFileName;
        return szShortName.substr(0, szShortName.length()-szExt.length()-1);
    }
}
//========================================================================

/* Extract file path */
const string ExtractFilePath(const string szFileName)
{
    size_t found = szFileName.find_last_of("/\\");
    if ((int)found != -1)
        return szFileName.substr(0,found);
    else
        return ".";
}
//========================================================================

/* Extract file name */
const string ExtractFileName(const string szFileName)
{
    size_t found = szFileName.find_last_of("/\\");
    if ((int)found != -1)
        return szFileName.substr(found+1);
    else
        return szFileName;
}
//========================================================================

/* Check if file exists */
bool FileExists(const string szFileName)
{
    if (access(szFileName.c_str(),00) != 0)
        return false;
    else
        return true;
}
//========================================================================

/* Simple file copy */
void MyCopyFile(const string szSourceFile, const string szDestFile)
{
    ifstream fSourceFile(szSourceFile.c_str(), fstream::binary);
    if ((! fSourceFile.is_open()) && (! fSourceFile.good()))
    {
        cerr << PROGRAM_NAME << ": " << szSourceFile << ": " << _("Cannot open file") << endl;
        exit (EXIT_FAILURE);
    }

    ofstream fDestFile(szDestFile.c_str(), fstream::trunc|fstream::binary);
    if ((! fDestFile.is_open()) && (! fDestFile.good()))
    {
        cerr << PROGRAM_NAME << ": " << fDestFile << ": " << _("Cannot create file") << endl;
        fSourceFile.close();
        exit (EXIT_FAILURE);
    }

    fDestFile << fSourceFile.rdbuf();

    fSourceFile.close();
    fDestFile.close();
}
//========================================================================
