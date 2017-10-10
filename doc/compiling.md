# Building for Linux

## Install dependencies

### Debian

```
sudo apt-get install git make libqt5webkit5-dev libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler build-essential libboost-dev libboost-all-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libminiupnpc-dev libevent-dev libcurl4-openssl-dev git libpng-dev qrencode libqrencode-dev
```

### openSUSE

```
 sudo zypper install git gcc gcc-c++ libqt5-devel boost-devel libopenssl-devel libdb-4_8-devel libminiupnpc-devel libqrencode3
```

### Others

Find and install your distros development packages for the following:
QT5
openssl
libdb
boost
miniupnpc
qrencode

Alternatively, you may download and manually compile these packages and their many dependencies.

## Compile the Qt Wallet

```
git clone https://github.com/Beirdo/MudCoin.git
cd MudCoin
qmake
make -j4
```

## Compile the node daemon

```
cd MudCoin/src
make -j4 -f makefile.unix
```

# Building for Windows

## From Linux

### Gather your toolchain and dependencies

### Debian

``
sudo apt-get -yqq update
sudo apt-get -fyq install
sudo apt-get -m -y install autoconf automake bash bison bzip2 cmake flex gettext git g++ intltool libffi-dev libtool libltdl-dev
sudo apt-get -m -y install libssl-dev libxml-parser-perl make openssl patch perl pkg-config scons sed unzip wget xz-utils
sudo apt-get -m -y install autopoint gperf 
``

NOTE: replace make -j4 with your preference.

```
git clone https://github.com/mxe/mxe.git
cd mxe
make -j4 make gcc zlib qtbase qtimageformats qttools libpng miniupnpc
```
Check mxe/index.html#requirements-debian if you get errors.

### Build Boost using mxe

```
cd mxe
make -j4 boost
```

### Build Boost (Alternate Method)
i686-w64-mingw32.static-gcc -v should report gcc version 4.9.2 (GCC)

```
wget http://sourceforge.net/projects/boost/files/boost/1.57.0/boost_1_57_0.tar.bz2/download -O boost_1_57_0.tar.bz2
tar -xvf boost_1_57_0.tar.bz2
cd boost_1_57_0
./bootstrap.sh --prefix=/<to>/mxe/usr/i686-w64-mingw32.static
echo "using gcc : 4.9.2 : i686-w64-mingw32-g++
    :
    <rc>i686-w64-mingw32.static-windres
    <archiver>i686-w64-mingw32.static-ar
    <cxxflags>-frandom-seed=boost1
    <ranlib>i686-w64-mingw32.static-ranlib
;" > tools/build/v2/user-config.jam
./bjam --layout=system variant=release threading=multi link=static runtime-link=static toolset=gcc target-os=windows threadapi=win32 install

```
### Build Berkley DB 4.8

```
wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
tar -xvf db-4.8.30.NC.tar.gz
cd db-4.8.30.NC
mkdir build_mxe
cd build_mxe
../dist/configure --host=i686-w64-mingw32.static --prefix=/<to>/mxe/usr/i686-w64-mingw32.static --disable-shared --disable-replication --enable-cxx --enable-mingw
make -j4
make install
```

### Build qrencode
```
wget http://fukuchi.org/works/qrencode/qrencode-3.4.4.tar.gz
tar -xvf qrencode-3.4.4.tar.gz
cd qrencode-3.4.4
./configure --host=i686-w64-mingw32.static --prefix=/<to>/mxe/usr/i686-w64-mingw32.static --enable-static --disable-shared --without-tools
make -j4
make install
```

### Build miniupnpc (Alternate method)

```
wget https://codeload.github.com/miniupnp/miniupnp/tar.gz/master -O miniupnp.tar.gz
tar -xvf miniupnp.tar.gz
cd miniupnp-master/miniupnpc
DLLWRAP=i686-w64-mingw32.static-dllwrap CC=i686-w64-mingw32.static-gcc AR=i686-w64-mingw32.static-ar cmake . -DUPNPC_BUILD_STATIC=TRUE -DCMAKE_INSTALL_PREFIX=/<to>/mxe/usr/i686-w64-mingw32.static/
make install DLLWRAP=i686-w64-mingw32.static-dllwrap CC=i686-w64-mingw32.static-gcc AR=i686-w64-mingw32.static-ar CFLAGS+='-I/<to>/mxe/usr/i686-w64-mingw32.static/include'
```

### Build MudCoin Qt Wallet
```
export PATH=/<to>/mxe/usr/bin:$PATH
git clone https://github.com/Beirdo/MudCoin.git
cd MudCoin
i686-w64-mingw32.static-qmake-qt5 MudCoin-qt.pro
make -j4
```
