# Installation
### UNIX / POSIX (such as Linux and Mac OSX)
##### Dependencies
* Arch Linux Developer Toolkit: ```pacman -S --needed base-devel```
* Developer Toolkit for Debian-based Linux Distribution: ```sudo apt-get install build-essential```

Required Packages:
- gcc (>= 4:4.9)
- g++ (>= 4:4.9)
- libc-dev
- autoconf (>=2:2.69)
- libtool
- make
- m4
- automake

In the project directory:
```
$ autoreconf -vif
```
Then, in build directory, ```cd build```:
```
$ cd build
$ ../configure --prefix="/usr"
$ make
# make install
```

### Windows
With Windows Platform you need to install the folowing required packages from Ported GNU Projects, like [MinGW](http://www.mingw.org/) and [GnuWin](http://gnuwin32.sourceforge.net/):
- [AutoMake](http://gnuwin32.sourceforge.net/packages/automake.htm) ([Setup Executable](http://gnuwin32.sourceforge.net/downlinks/automake.php))
- [AutoConf](http://gnuwin32.sourceforge.net/packages/autoconf.htm) ([Setup Executable](http://gnuwin32.sourceforge.net/downlinks/autoconf-bin.php))
- [LibTool](http://gnuwin32.sourceforge.net/packages/libtool.htm) ([Setup Executable](http://gnuwin32.sourceforge.net/downlinks/libtool.php))
- [Make](http://gnuwin32.sourceforge.net/packages/make.htm) ([Setup Executable](http://gnuwin32.sourceforge.net/downlinks/make.php))
- [M4](http://gnuwin32.sourceforge.net/packages/m4.htm) ([Setup Executable](http://gnuwin32.sourceforge.net/downlinks/m4.php))
- [MinGW](http://www.mingw.org/) ([Setup Executable](https://sourceforge.net/projects/mingw/files/latest/download?source=files))
