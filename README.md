English description is below.

**scrap2rtf** - простая программа для преобразования фрагментов файлов 
(Shell Scrap Object File) в Rich Text Format

Использование: scrap2rtf [ОПЦИИ]... [ФАЙЛ]...

-r, --remove-original    удалить оригинал файла-фрагмента
-v, --verbose            предоставлять расширенную информацию о процессе преобразования
-o, --output-directory   указать директорию куда складывать преобразованные файлы
-s, --same-directory     складывать преобразованные файлы в тот же каталог, где и файлы-фрагменты
    --help               отобразить информацию о ключах и выйти
    --version            отобразить информацию о версии и выйти

Если вы хотите собрать сами из исходников:

* qmake scrap2rtf.pro -r -spec linux-g++-64
* make
* sudo make install

English description:

**scrap2rtf** is a simple program to convert Shell Scrap Object File to Rich 
Text Format

Usage: scrap2rtf [OPTION]... [FILE]...

-r, --remove-original    remove original scrap file
-v, --verbose            verbosely list files processed
-o, --output-directory   output directory
-s, --same-directory     convert files into the same directory where the scrap
    --help               display this help and exit
    --version            output version information and exit

If you want to install from sources:

* qmake scrap2rtf.pro -r -spec linux-g++-64
* make
* sudo make install

Copyright (C) 2009-2020 Andrei Ivnitskii <ivnish.dev@gmail.com>
