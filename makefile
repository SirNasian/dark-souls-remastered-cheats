dist/dark-souls-remastered-cheats : build/main.o build/cheat-invincibility.o build/cheat-lockitemcount.o build/cheat-lockspellcount.o
	@mkdir -p dist
	clang++ -o $@ $^

build/main.o : src/main.cpp
	@mkdir -p build
	clang++ -o $@ -c $<

build/cheat-invincibility.o : src/cheat-invincibility.cpp
	@mkdir -p build
	clang++ -o $@ -c $<

build/cheat-lockitemcount.o : src/cheat-lockitemcount.cpp
	@mkdir -p build
	clang++ -o $@ -c $<

build/cheat-lockspellcount.o : src/cheat-lockspellcount.cpp
	@mkdir -p build
	clang++ -o $@ -c $<

run : dist/dark-souls-remastered-cheats
	./dist/dark-souls-remastered-cheats

clean :
	rm -rf build dist
