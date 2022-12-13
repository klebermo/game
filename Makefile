export sdl_header := /opt/include
export sdl_library := /opt/lib
export lib_netpbm_header := ../codec/Netpbm/include
export lib_netpbm_library := ../codec/release

export cpp_flags := -Wall -pedantic -g -fsanitize=address -I ${sdl_header} -I ${lib_netpbm_header}
export ld_flags := -L ${sdl_library} -L ${lib_netpbm_library} -l:libnetpbm.a -l:libSDL2.a -l:libSDL2main.a -lGL -lGLEW -lm

all: game

Surface.o: src/2D/Surface.cpp
	g++ ${cpp_flags} -c src/2D/Surface.cpp -o build/Surface.o

Renderer.o: src/2D/Renderer.cpp
	g++ ${cpp_flags} -c src/2D/Renderer.cpp -o build/Renderer.o

Image.o: src/2D/Image.cpp
	g++ ${cpp_flags} -c src/2D/Image.cpp -o build/Image.o

Animation.o: src/2D/Animation.cpp
	g++ ${cpp_flags} -c src/2D/Animation.cpp -o build/Animation.o

Video.o: src/2D/Video.cpp
	g++ ${cpp_flags} -c src/2D/Video.cpp -o build/Video.o

Input.o: src/Input/Input.cpp
	g++ ${cpp_flags} -c src/Input/Input.cpp -o build/Input.o

Main.o: src/Main.cpp
	g++ ${cpp_flags} -c src/Main.cpp -o build/Main.o

game: Input.o Image.o Animation.o Video.o Renderer.o Surface.o Main.o
	g++ ${cpp_flags} -o release/game2d build/Input.o build/Image.o build/Animation.o build/Video.o build/Renderer.o build/Surface.o build/Main.o ${ld_flags}

clean:
	rm build/*.o
	rm release/game2d
