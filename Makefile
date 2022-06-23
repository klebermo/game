export lib_netpbm_header := ../codec/Netpbm/include
export lib_netpbm_library := ../codec/release

all: game

Surface2d.o: src/2D/Surface.cpp
	g++ -g -c src/2D/Surface.cpp -o build/Surface2D.o

Renderer2d.o: src/2D/Renderer.cpp
	g++ -g -c src/2D/Renderer.cpp -o build/Renderer2d.o

Image.o:
	g++ -g -c src/2D/Image.cpp -o build/Image.o

Surface3d.o: src/3D/Surface.cpp
	g++ -g -c src/3D/Surface.cpp -o build/Surface3d.o

Renderer3d.o: src/3D/Renderer.cpp
	g++ -g -c src/3D/Renderer.cpp -o build/Renderer3d.o

Input.o:
	g++ -g -c src/Input.cpp -o build/Input.o

Main.o: src/Main.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Main.cpp -o build/Main.o

game: Main.o Surface2d.o Renderer2d.o Image.o Surface3d.o Renderer3d.o Input.o
	g++ -g -L ${lib_netpbm_library} -o release/game build/Main.o build/Surface2d.o build/Renderer2d.o build/Image.o build/Surface3d.o build/Renderer3d.o build/Input.o -lSDL2 -lGL -lGLEW -Wl,-rpath="./" -lnetpbm

clean:
	rm build/*.o
	rm release/game
