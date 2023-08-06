dist/dark-souls-remastered-cheats : build/main.o build/cheat-invincibility.o build/cheat-lockitemcount.o
	mkdir -p dist
	clang++ -o dist/dark-souls-remastered-cheats build/main.o build/cheat-invincibility.o build/cheat-lockitemcount.o

build/main.o : src/main.cpp
	mkdir -p build
	clang++ -o build/main.o -c src/main.cpp

build/cheat-invincibility.o : src/cheat-invincibility.cpp
	mkdir -p build
	clang++ -o build/cheat-invincibility.o -c src/cheat-invincibility.cpp

build/cheat-lockitemcount.o : src/cheat-lockitemcount.cpp
	mkdir -p build
	clang++ -o build/cheat-lockitemcount.o -c src/cheat-lockitemcount.cpp

run : dist/dark-souls-remastered-cheats
	./dist/dark-souls-remastered-cheats

clean :
	rm -rf build dist
