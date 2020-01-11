opengl/window : opengl/window.o ../bin/opengl/util.o
	g++ -g -o opengl/window -lGL -lglfw -lGLEW opengl/window.o ../bin/opengl/util.o

opengl/window.o : opengl/window.cc
	g++ -g -c -o opengl/window.o opengl/window.cc

opengl/triangle : opengl/triangle.o ../bin/opengl/util.o
	g++ -g -o opengl/triangle -lGL -lglfw -lGLEW opengl/triangle.o ../bin/opengl/util.o

opengl/triangle.o : opengl/triangle.cc
	g++ -g -c -o opengl/triangle.o opengl/triangle.cc
