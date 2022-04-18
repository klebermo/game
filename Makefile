export lib_netpbm_header := ../codec/Netpbm/include
export lib_netpbm_library := ../codec/release

all: game

Surface.o: src/Surface.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Surface.cpp -o build/Surface.o

Surface2d.o: src/Surface2d.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Surface2d.cpp -o build/Surface2d.o

Surface3d.o: src/Surface3d.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Surface3d.cpp -o build/Surface3d.o

Renderer.o: src/Renderer.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Renderer.cpp -o build/Renderer.o

Renderer2d.o: src/Renderer2d.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Renderer2d.cpp -o build/Renderer2d.o

Renderer3d.o: src/Renderer3d.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Renderer3d.cpp -o build/Renderer3d.o

Input.o:
	g++ -g -I ${lib_netpbm_header} -c src/Input.cpp -o build/Input.o

Shape2d.o:
	g++ -g -I ${lib_netpbm_header} -c src/Shape2d.cpp -o build/Shape2d.o

Shape3d.o:
	g++ -g -I ${lib_netpbm_header} -c src/Shape3d.cpp -o build/Shape3d.o

Image.o:
	g++ -g -I ${lib_netpbm_header} -c src/Image.cpp -o build/Image.o

Main.o: src/Main.cpp
	g++ -g -I ${lib_netpbm_header} -c src/Main.cpp -o build/Main.o

game: Main.o Surface.o Surface2d.o Surface3d.o Renderer.o Renderer2d.o Renderer3d.o Image.o Shape2d.o Shape3d.o Input.o
	g++ -g -L ${lib_netpbm_library} -o release/game build/Main.o build/Surface.o build/Surface2d.o build/Surface3d.o build/Renderer.o build/Renderer2d.o build/Renderer3d.o build/Image.o build/Shape2d.o build/Shape3d.o build/Input.o -lSDL2 -lGL -lGLEW -Wl,-rpath="./" -lnetpbm

clean:
	rm build/*.o
	rm release/game
