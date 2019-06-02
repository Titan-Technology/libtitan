g++ -v -c Titans.cpp
g++ -v -c Titans.h
mkdir sfml-audio
cd sfml-audio/
mv ../libsfml-audio.a .
ar -x libsfml-audio.a
cd ..
ar ru libtitans.a Titans.o Titans.h.gch sfml-audio/*.o
rm Titans.h.gch Titans.o
PAUSE
