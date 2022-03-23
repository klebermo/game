all: codec

Surface.o: src/Surface.cpp
	g++ -g -c src/Surface.cpp -o build/Surface.o -lSDL2 -lGL -lGLEW

Surface2d.o: src/Surface2d.cpp
	g++ -g -c src/Surface2d.cpp -o build/Surface2d.o -lSDL2 -lGL -lGLEW

Surface3d.o: src/Surface3d.cpp
	g++ -g -c src/Surface3d.cpp -o build/Surface3d.o -lSDL2 -lGL -lGLEW

Renderer.o: src/Renderer.cpp
	g++ -g -c src/Renderer.cpp -o build/Renderer.o

Renderer2d.o: src/Renderer2d.cpp
	g++ -g -c src/Renderer2d.cpp -o build/Renderer2d.o

Renderer3d.o: src/Renderer3d.cpp
	g++ -g -c src/Renderer3d.cpp -o build/Renderer3d.o

Input.o:
	g++ -g -c src/Input.cpp -o build/Input.o

Shape.o:
	g++ -g -c src/Shape.cpp -o build/Shape.o

World.o:
	g++ -g -c src/World.cpp -o build/World.o

Main.o: src/Main.cpp
	g++ -g -c src/Main.cpp -o build/Main.o -lSDL2 -lGL -lGLEW

codec: Main.o Surface.o Surface2d.o Surface3d.o Renderer.o Renderer2d.o Renderer3d.o Input.o Shape.o World.o
	g++ -g -o release/game build/Main.o build/Surface.o build/Surface2d.o build/Surface3d.o build/Renderer.o build/Renderer2d.o build/Renderer3d.o build/Input.o build/Shape.o build/World.o -lSDL2 -lGL -lGLEW

clean:
	rm build/*.o
	rm release/game
