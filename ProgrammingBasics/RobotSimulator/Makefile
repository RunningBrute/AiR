#=========================== CVS =======================================
# $Author: Piotr Basinski$
# $Revision: $
# $State: $
# $Date: $
#=======================================================================


__start__: obj ./prog
	rm -f core.* core; ./prog

# Tworzy katalog "obj" gdy go nie ma
# 
obj:
	mkdir -p obj

./prog: obj/prog.o obj/lacze.o obj/scena.o obj/sciezka.o obj/obiekt.o obj/wektor.o
	g++ -o ./prog obj/prog.o obj lacze.o obj/scena.o obj/sciezka.o obj/obiekt.o obj/wektor.o

obj/prog.o: src/prog.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/prog.o src/prog.cpp

obj/lacze.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze.o src/lacze_do_gnuplota.cpp

obj/scena.o: src/scena.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/scena.o src/scena.cpp

obj/sciezka.o: src/sciezka.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/sciezka.o src/sciezka.cpp 

obj/obiekt.o: src/obiekt.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/obiekt.o src/obiekt.cpp

obj/wektor.o: src/wektor.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/wektor.o src/wektor.cpp

clean:
	rm -f obj/* ./prog core.* core


help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo
