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

./prog: obj/prog.o obj/system.o obj/lacze.o obj/b_prost.o obj/b_dysk.o
	g++ -o ./prog obj/prog.o obj/system.o obj/lacze.o obj/b_prost.o obj/b_dysk.o

obj/prog.o: src/prog.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/prog.o src/prog.cpp

obj/lacze.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/lacze.o src/lacze_do_gnuplota.cpp 

obj/system.o: src/system.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/system.o src/system.cpp

obj/b_prost.o: src/b_prost.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/b_prost.o src/b_prost.cpp

obj/b_dysk.o: src/b_dysk.cpp inc/lib.hpp
	g++  -Iinc -W -Wall -pedantic -c -o obj/b_dysk.o src/b_dysk.cpp

clean:
	rm -f obj/* ./prog core.* core


help:
	@echo
	@echo " make        - tworzenie i uruchomienie aplikacji"
	@echo " make clean  - usuniecie produktow kompilacji i konsolidacji"
	@echo
