.PHONY: all debug release test clean tree docs

all: debug release docs

clean:
	echo "Removing all files in build and docs repos"
	rm -rf ./build ./*/build ./docs/ ./*/docs

release:

	mkdir -p build/release; cd build/release; cmake -DCMAKE_BUILD_TYPE=Release ../../; make

debug:

	mkdir -p build/debug; cd build/debug; cmake -DCMAKE_BUILD_TYPE=Debug ../../; make

test: debug

	cd build/debug; ctest ../..

tree:
	tree --dirsfirst -I 'build|resources|docs' .

docs:
	doxygen ./Doxygen
