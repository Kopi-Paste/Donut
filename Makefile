CXX=g++
LD=g++
CXXFLAGS=-std=c++17
LDFLAGS=-lGLEW -lSDL2 -lGL

donut.out: Camera.o Display.o Main.o Shader.o Statics.o Mesh.o obj_loader.o Vertex.o stb_image.o Texture.o Transform.o
	$(LD) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm donut.out
	rm *.o

