# Maintainer: Ivan Lazeev <tannhauserus@gmail.com>
pkgname=keystroked
pkgver=0.1.3
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
md5sums=('837c15ca033d7cbe92d730077be19d76')

build() {
	cd $srcdir
	make VERSION=$pkgver
}

package() {
	cd $srcdir
	make VERSION=$pkgver DESTDIR=$pkgdir PREFIX=/usr install
}
