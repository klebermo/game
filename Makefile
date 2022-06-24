export lib_netpbm_header := ../codec/Netpbm/include
export lib_netpbm_library := ../codec/release

all: game

Surface.o: src/2D/Surface.cpp
	g++ -g -c src/2D/Surface.cpp -o build/Surface.o

Renderer.o: src/2D/Renderer.cpp
	g++ -g -c src/2D/Renderer.cpp -o build/Renderer.o

Image.o:
	g++ -g -c src/2D/Image.cpp -o build/Image.o

Input.o:
	g++ -g -c src/Input.cpp -o build/Input.o

Main.o: src/Main.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Main.cpp -o build/Main.o

game: Input.o Image.o Renderer.o Surface.o Main.o
	g++ -g -L ${lib_netpbm_library} -o release/game2d build/Image.o build/Input.o build/Renderer.o build/Surface.o build/Main.o -lX11 -lGL -lGLEW -Wl,-rpath="./" -lnetpbm

clean:
	rm build/*.o
	rm release/game2d
