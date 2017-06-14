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

#include "common_head.h"

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
