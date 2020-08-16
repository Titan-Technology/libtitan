output: Titans.o Titans.h.gch
	ar ru libtitans.a Titans.o Titans.h.gch
	rm Titans.h.gch Titans.o

Titans.h.gch: Titans.h
	g++ -c Titans.h

Titans.o: Titans.cpp
	g++ -c Titans.cpp

clean:
	rm libtitans.a *.o *.h.gch

install:
	cp Titans.h /usrl/local/include/
	cp libtitans.a /usrl/local/lib/

install-bow:
	tar cvfz libtitans-BOW.tar.gz BagOfWords\(BOW\)/
	mkdir /usr/local/share/libtitans-bow/
	cp libtitans-BOW.tar.gz /usr/local/share/libtitans-bow/
