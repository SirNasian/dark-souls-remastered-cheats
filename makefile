dist/dark-souls-remastered-cheats : dist build/main.o
	clang++ -o dist/dark-souls-remastered-cheats src/main.cpp

build/main.o : build src/main.cpp
	clang++ -o build/main.o -c src/main.cpp

run : dist/dark-souls-remastered-cheats
	./dist/dark-souls-remastered-cheats

build :
	mkdir build

dist :
	mkdir dist

clean :
	rm -rf build dist
