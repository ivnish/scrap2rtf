#! /bin/sh

cd '/home/ivnish/Develop/Release/scrap2rtf'

cd po

echo "Rename ru.po to old.po"
mv ru.po old.po

echo "Get strings from files"
xgettext -C ../src/main.cpp -k_ -o ru.pot

echo "Merge old strings and new strings"
msgmerge old.po ru.pot -o ru.po

echo "Translate it..."
gedit ru.po

echo "Compile MO file"
msgfmt --output-file=scrap2rtf.mo ru.po

echo "Remove temp files"
rm ru.pot
