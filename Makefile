build:
	cd server && jbuilder build main.exe

run: build
	./server/_build/default/main.exe

clean:
	rm -rf server/_build

install_dependencies:
	opam install jbuilder