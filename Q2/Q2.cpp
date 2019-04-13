
#include <iostream>
#include "vector.h"

int main() {
    Vector v{};
    Vector v1{};
    Vector v2{};
    Vector v3{ v1 };
    Vector v4{ v1 + v1 };
    v.push_back(4); //v=4
    //v.push_back(5);
    //v.push_back(6);
    v3.push_back(2);//v3=2
    v.display(2);
    v3.capacity();
    v1 = v;
    v.pop_back();
    v2 = v1 + v;
    v2.Show();
   
    std::cout << v2*v1 << std::endl;
   


    
     if(v < v3)
      std::cout<<"v is smaller"<<std::endl;
    else
      std::cout<<"v3 is smaller"<<std::endl;
    
    std::cout << "size: " << v.size() << "\n";
    std::cout << "max_size: " << v2.max() << "\n";
    v.Show();

    return 0;
}
