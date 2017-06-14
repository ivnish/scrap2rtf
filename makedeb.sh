#! /bin/sh

cd '/home/ivnish/Develop/Release/scrap2rtf'

echo "Create description-pak file"
echo "A simple program to convert Shell Scrap Object File to Rich Text Format" > description-pak

echo "Run checkinstall"
sudo checkinstall --install=no --pkgversion=0.5 --maintainer=ivnitsky.a@gmail.com --nodoc --requires=p7zip-full --deldesc=yes --backup=no

echo "Change owner"
sudo chown ivnish:ivnish *.deb

echo "Copy DEB to Redistr directory"
mv *.deb '/home/ivnish/Develop/Redistr/scrap2rtf'

rm description-pak
