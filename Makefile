export sdl_header := /opt/include
export sdl_library := /opt/lib
export lib_netpbm_header := ../codec/Netpbm/include
export lib_netpbm_library := ../codec/release

all: game

Surface.o: src/2D/Surface.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -c src/2D/Surface.cpp -o build/Surface.o

Renderer.o: src/2D/Renderer.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -c src/2D/Renderer.cpp -o build/Renderer.o

Image.o: src/2D/Image.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -c src/2D/Image.cpp -o build/Image.o

Animation.o: src/2D/Animation.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -c src/2D/Animation.cpp -o build/Animation.o

Video.o: src/2D/Video.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -c src/2D/Video.cpp -o build/Video.o

Input.o: src/Input/Input.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -c src/Input/Input.cpp -o build/Input.o

Main.o: src/Main.cpp
	g++ -Wall -pedantic -g -I ${sdl_header} -I ${lib_netpbm_header} -c src/Main.cpp -o build/Main.o

game: Input.o Image.o Animation.o Video.o Renderer.o Surface.o Main.o
	g++ -Wall -pedantic -g -L ${sdl_library} -L ${lib_netpbm_library} -o release/game2d build/Input.o build/Image.o build/Animation.o build/Video.o build/Renderer.o build/Surface.o build/Main.o -l:libnetpbm.a -l:libSDL2.a -l:libSDL2main.a -lGL -lGLEW -lm

clean:
	rm build/*.o
	rm release/game2d
