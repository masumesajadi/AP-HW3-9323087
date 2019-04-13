CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = Q1main.o Maxheap.o
TARGET = Q1main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: Q1main.cpp  Maxheap.h
	$(CXX) $(CXXFLAGS) Q1main.cpp
Vector.o: Maxheap.cpp
	$(CXX) $(CXXFLAGS) Maxheap.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
