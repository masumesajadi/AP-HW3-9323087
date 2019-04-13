/*FullName: Shamisa Kaspour
  StudentNum: 9423087*/
#ifndef Q3_VECTOR_H
#define Q3_VECTOR_H
#include <cmath>

class Vector {

public:
    Vector();
    ~Vector();
    Vector(Vector& copy);
    Vector( Vector&& v);
    void push_back(int);
    void pop_back();
    void Show();
    int capacity(){return elements;};
    Vector operator+(Vector&);
    Vector& operator=(const Vector&);
    bool operator<( Vector v);
    bool operator>( Vector v);
    int operator*(Vector v);
    void display(int);
    int max();
    int size();

private:
    int elements; //number of elements of a vector
    int* vecPointer;  //pointer to first element of a vector
  
};


#endif //Q3_VECTOR_H
