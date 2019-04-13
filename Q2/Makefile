CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = Q2.o vector.o
TARGET = Q2


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: Q2.cpp  vector.h
	$(CXX) $(CXXFLAGS) Q2.cpp
Vector.o: vector.cpp
	$(CXX) $(CXXFLAGS) vector.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
