SRC = keystroked.c
all: keystroked
FLAGS = -std=c99
keystroked:
	${CC} ${SRC} ${CFLAGS} ${FLAGS} -o keystroked

clean:
	@rm -f keystroked keystroked-${VERSION}.tar.gz 

dist: clean all
	@mkdir -p keystroked-${VERSION}
	@cp -t keystroked-${VERSION} Makefile ${SRC}
	@tar -cf keystroked-${VERSION}.tar keystroked-${VERSION}
	@gzip keystroked-${VERSION}.tar
	@cp keystroked-${VERSION}.tar.gz ../
	@rm -rf keystroked-${VERSION}
	@rm -f keystroked keystroked-${VERSION}.tar.gz

install: all
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f keystroked ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/keystroked
uninstall:
	@rm -f ${DESTDIR}${PREFIX}/bin/keystroked 
