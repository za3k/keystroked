# Maintainer: Ivan Lazeev <tannhauserus@gmail.com>
pkgname=keystroked
pkgver=0.1.2
pkgrel=1
pkginfo="Keystrokes counter daemon"
arch=('i686' 'x86_64')
url=""
license=('GPL')
groups=()
depends=()
makedepends=()
checkdepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=($pkgname-$pkgver.tar.gz)
noextract=()
md5sums=('775c127980a72076449345854373de90') 

build() {
	cd $srcdir
	make VERSION=$pkgver
}

package() {
	cd $srcdir
	make VERSION=$pkgver DESTDIR=$pkgdir PREFIX=/usr install
}
