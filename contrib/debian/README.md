
Debian
====================
This directory contains files used to package fixd/fix-qt
for Debian-based Linux systems. If you compile fixd/fix-qt yourself, there are some useful files here.

## fix: URI support ##


fix-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install fix-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your fixqt binary to `/usr/bin`
and the `../../share/pixmaps/fix128.png` to `/usr/share/pixmaps`

fix-qt.protocol (KDE)

