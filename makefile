dist/dark-souls-remastered-cheats : dist build/main.o build/cheat-lockitemcount.o
	clang++ -o dist/dark-souls-remastered-cheats build/main.o build/cheat-lockitemcount.o

build/main.o : build src/main.cpp
	clang++ -o build/main.o -c src/main.cpp

build/cheat-lockitemcount.o : build src/cheat-lockitemcount.cpp
	clang++ -o build/cheat-lockitemcount.o -c src/cheat-lockitemcount.cpp

run : dist/dark-souls-remastered-cheats
	./dist/dark-souls-remastered-cheats

build :
	mkdir build

dist :
	mkdir dist

clean :
	rm -rf build dist
