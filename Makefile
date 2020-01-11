bin/geom/3d/shape.o : src/geom/3d/shape.hpp src/geom/3d/shape_impl.hpp src/geom/3d/shape.cc
	g++ -g -c -o bin/geom/3d/shape.o src/geom/3d/shape.cc

bin/opengl/util.o : src/opengl/util.cc src/opengl/util.hpp
	g++ -g -c -o bin/opengl/util.o src/opengl/util.cc

bin/opengl/mesh.o : src/opengl/mesh.cc src/opengl/mesh.hpp
	g++ -g -c -o bin/opengl/mesh.o src/opengl/mesh.cc

bin/opengl/program.o : src/opengl/program.cc src/opengl/program.hpp
	g++ -g -c -o bin/opengl/program.o src/opengl/program.cc

bin/test/opengl/window : bin/test/opengl/window.o bin/opengl/util.o
	g++ -g -o bin/test/opengl/window -lGL -lglfw -lGLEW bin/test/opengl/window.o bin/opengl/util.o

bin/test/opengl/window.o : test/opengl/window.cc
	g++ -g -c -o bin/test/opengl/window.o test/opengl/window.cc

bin/test/opengl/triangle : test/opengl/triangle.o bin/opengl/util.o
	g++ -g -o bin/test/opengl/triangle -lGL -lglfw -lGLEW bin/test/opengl/triangle.o bin/opengl/util.o

bin/test/opengl/triangle.o : test/opengl/triangle.cc
	g++ -g -c -o bin/test/opengl/triangle.o test/opengl/triangle.cc

bin/test/opengl/cube : bin/test/opengl/cube.o bin/opengl/util.o bin/opengl/mesh.o bin/opengl/program.o
	g++ -g -o bin/test/opengl/cube -lGL -lglfw -lGLEW bin/test/opengl/cube.o bin/opengl/util.o bin/opengl/mesh.o bin/opengl/program.o

bin/test/opengl/cube.o : test/opengl/cube.cc
	g++ -g -c -o tbin/est/opengl/cube.o test/opengl/cube.cc
