#include "vector.h"
#include <iostream>

/* constructor definition */
Vector::Vector() {
    std::cout << "vector constructor created" <<std::endl;
    elements = 0;
    vecPointer = nullptr;
};

/* copy constructor definition */
Vector::Vector(Vector &copy) {
    std::cout << "vector copy constructor created" <<std::endl;
    elements = copy.elements;
    vecPointer = new int[elements];
    for (int i{0}; i < elements; i++)
        vecPointer[i] = copy.vecPointer[i];

}
/* move constructor definition */
Vector::Vector(Vector&& v) {
    std::cout << " move constructor created" <<std::endl;
     elements = v.elements;
     vecPointer=v.vecPointer;
    v.vecPointer=nullptr;

}




/* destructor definition */
Vector::~Vector() {
    std::cout << "vector distructor" <<std::endl;
    delete[] vecPointer;
    // vecPointer = nullptr;
}
/* function to push back */
void Vector::push_back(int value) {
    elements++; //now element is increased
    int* pointer{new int[elements - 1]};  //pointer to store elements of vecpointer
    for (int i = 0; i < elements - 1  ; ++i) {
        pointer[i] = vecPointer[i];  //copy elements of vecpointer in pointer
    }
    vecPointer = new int[elements];
    vecPointer[elements - 1] = value; //store new value
    for (int j{0}; j < elements - 1 ; j++) {
        vecPointer[j] = pointer[j];  //restore elements to vecpointer
    }
    delete[] pointer;
    std::cout << "push back" <<std::endl;
}

/* function to display elements */
void Vector::Show() {
    std::cout << "show elements of Vector:[";
    
        for (int i{0}; i < elements; i++)
	  std::cout <<  *(vecPointer + i) << " ";
	 std::cout << "]" << std::endl;
}

/* function to pop back */
void Vector::pop_back() {
    --elements;
    std::cout << "pop back" <<std::endl;
}

/* function to display an element of a vector */
void Vector::display(int sv) {
  std::cout<<"display element " <<sv<<"  of a vector_" << "v" << ": " << *(vecPointer + (sv - 1)) << std::endl;
}


/* capacity function
void Vector::capacity(int  elements){
  for(int c{2} ; c<=1029 ;c++)
    {
      if(elements > c)
       c = c*2;
    }
  std::cout<< c << std::endl;
}
*/

/* operator + */
Vector Vector::operator+(Vector& v) {
    Vector newV{};  //a temporary vector to store all elements
    newV.vecPointer = new int[elements + v.elements];
    newV.elements = elements + v.elements;
        for (int i{0}; i < elements; i++) {
            *(newV.vecPointer + i) = *(this->vecPointer + i);
        }
        for (int j{elements}; j < elements + v.elements ;j++) {
            *(newV.vecPointer + j) = *(v.vecPointer + (j - elements));
        }
        return newV;
    }

/* operator = */
Vector& Vector::operator=(const Vector& v) {
    if(this == &v) {
        return *this;
    }
    else {
        delete[] this->vecPointer;
        this->vecPointer = new int[v.elements];
        this->elements = v.elements;
        for (int i{0}; i < v.elements; i++) {
            *(this->vecPointer + i) = *(v.vecPointer + i);
        }
        return *this;
    }
}
/* operator < */
 bool Vector:: operator<( Vector v){
   return elements < v.elements;
   
    }
/* operator > */
 bool Vector:: operator>( Vector v){
   return elements > v.elements;
   
    }
/* operator * */
int Vector::operator*(Vector v){
    int result{};
    if(this  == &v)
    {
        for(size_t i = 0; i < elements; i++)
        {
            result +=vecPointer[i] * v.vecPointer[i];
        }
    }
    else
        std::cout << "the lenght of arrays are not equal" << std::endl;
    return result;
}

/* function to return size of a vector */
int Vector::size() {
    return elements;
}

/* function to return max element of a vector */
int Vector::max() {
    int max{};
    max = vecPointer[0];
    for (int i{0}; i < elements ; i++) {
        if(max < vecPointer[i])
            max = vecPointer[i];
    }
    return max;
}

