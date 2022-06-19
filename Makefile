CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic -Wextra -std=c++17
LDFLAGS=-lGLEW -lSDL2 -lGL

donut.out: Display.o Main.o Shader.o Statics.o Mesh.o Vertex.o stb_image.o
	$(LD) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm donut.out
	rm *.o

