g++ -v -c Titans.cpp
g++ -v -c Titans.h
ar ru libtitans.a Titans.o Titans.h.gch
rm Titans.h.gch Titans.o
