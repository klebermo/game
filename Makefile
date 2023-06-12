export netpbm_header := ../codec/Netpbm/include
export netpbm_library := ../codec/release

export jpeg_header := ../codec/JPEG/include
export jpeg_library := ../codec/release

export cpp_flags := -Wall -pedantic -g -fsanitize=address  -I ${netpbm_header} -I ${jpeg_header}
export ld_flags := -L ${netpbm_library} -L ${jpeg_library} -Wl,-rpath '../../codec/release' -lnetpbm -Wl,-rpath '../../codec/release' -ljpeg -lSDL2 -lSDL2main -lGL -lGLEW -lX11 -lm

all: game

Surface.o: src/2D/Surface.cpp
	g++ ${cpp_flags} -c src/2D/Surface.cpp -o build/Surface.o

Renderer.o: src/2D/Renderer.cpp
	g++ ${cpp_flags} -c src/2D/Renderer.cpp -o build/Renderer.o

Image.o: src/2D/Image.cpp
	g++ ${cpp_flags} -c src/2D/Image.cpp -o build/Image.o

Input.o: src/Input/Input.cpp
	g++ ${cpp_flags} -c src/Input/Input.cpp -o build/Input.o

Main.o: src/Main.cpp
	g++ ${cpp_flags} -c src/Main.cpp -o build/Main.o

game: Input.o Image.o Animation.o Video.o Renderer.o Surface.o Main.o
	g++ ${cpp_flags} -o release/game2d build/Input.o build/Image.o build/Renderer.o build/Surface.o build/Main.o ${ld_flags}

clean:
	rm build/*.o
	rm release/game2d
