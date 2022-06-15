CXX=g++
LD=g++
CXXFLAGS=-Wall -pedantic -Wextra
LDFLAGS=-lGLEW -lSDL2 -lGL

donut.out: Display.o Main.o
	$(LD) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm donut.out
	rm *.o

