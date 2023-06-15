export netpbm_header := ../codec/Netpbm/include
export netpbm_library := ../codec/release

export jpeg_header := ../codec/JPEG/include
export jpeg_library := ../codec/release

export cpp_flags := -Wall -pedantic -g -fsanitize=address  -I ${netpbm_header} -I ${jpeg_header}
export ld_flags := -L ${netpbm_library} -L ${jpeg_library} -Wl,-rpath '../../codec/release' -lnetpbm -Wl,-rpath '../../codec/release' -ljpeg -lSDL2 -lSDL2main -lGL -lGLEW -lX11 -lm

all: game2d game3d

Surface2d.o: src/2D/Surface.cpp
	g++ ${cpp_flags} -c src/2D/Surface.cpp -o build/Surface2d.o

Renderer2d.o: src/2D/Renderer.cpp
	g++ ${cpp_flags} -c src/2D/Renderer.cpp -o build/Renderer2d.o

Surface3d.o: src/3D/Surface.cpp
	g++ ${cpp_flags} -c src/3D/Surface.cpp -o build/Surface3d.o

Renderer3d.o: src/3D/Renderer.cpp
	g++ ${cpp_flags} -c src/3D/Renderer.cpp -o build/Renderer3d.o

Image.o: src/2D/Image.cpp
	g++ ${cpp_flags} -c src/2D/Image.cpp -o build/Image.o

Shape.o: src/3D/Shape.cpp
	g++ ${cpp_flags} -c src/3D/Shape.cpp -o build/Shape.o

Input.o: src/Input/Input.cpp
	g++ ${cpp_flags} -c src/Input/Input.cpp -o build/Input.o

main2d.o: src/main2d.cpp
	g++ ${cpp_flags} -c src/main2d.cpp -o build/main2d.o

main3d.o: src/main3d.cpp
	g++ ${cpp_flags} -c src/main3d.cpp -o build/main3d.o

game2d: Input.o Image.o Renderer2d.o Surface2d.o main2d.o
	g++ ${cpp_flags} -o release/game2d build/Input.o build/Image.o build/Renderer2d.o build/Surface2d.o build/main2d.o ${ld_flags}

game3d: Input.o Image.o Renderer3d.o Surface3d.o main3d.o
	g++ ${cpp_flags} -o release/game3d build/Input.o build/Image.o build/Renderer3d.o build/Surface3d.o build/main3d.o ${ld_flags}

clean:
	rm build/*.o
	rm release/game2d
	rm release/game3d
