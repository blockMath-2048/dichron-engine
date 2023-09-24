


dichron-core: main.cpp vector.o matrix.o
	$(CXX) main.cpp vector.o matrix.o -o main -lm $(shell pkg-config glfw3 glew --cflags --libs --static)

vector.o: vector.cpp
	$(CXX) -c vector.cpp

matrix.o: matrix.cpp
	$(CXX) -c matrix.cpp
