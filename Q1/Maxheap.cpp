#include <iostream>
#include"Maxheap.h"


Maxheap:: Maxheap(){
    std::cout<<"defult constructor created"<<std::endl;
    arr.push_back(0);
    }

Maxheap:: Maxheap(int arr[] , int n){
     std::cout<<"array condtructor created"<<std::endl;
     arr.push_back(0);
     arr.insert(arr.end(), input.begin(), input.end());
     for(int i =heapsize() / 2; i > 0; --i)
            Heapify(i);
    }

Maxheap:: Maxheap(const Maxheap& Maxheap){
      std::cout<<"copy condtructor created"<<std::endl;
      for(size_t i = 0; i < Maxheap.heapsize(); i++)
         arr.push_back(Maxheap.arr[i]);

    }

void Maxheap::Heapify(int arr[], int i){
    int largest = i; // setting largest to i first time
    int L = LeftChild(i);
    int R = RightChild(i);
    if (L <= heapSize && arr[L] > arr[i]) // compare with arr[i] is not wrong but doesn't express the intent.
        largest = L;
    else{
        largest = i; // setting largest to i second time
    }

    if (R <= heapSize && arr[R] > arr[largest]){
        largest = R;
    }
    if(largest != i){
        int temp = arr[i];      // these 3 lines are the std::swap
        arr[i] = arr[largest];  // or you could roll your own function that does the same.
        arr[largest] = temp;    // better expressing the intent.
        Heapify(arr, largest);
    }
}

void Maxheap::BuildHeap(int arr[]){
    for(int i = (heapSize/2)-1; i >= 0; i--){
        Heapify(arr, i);
    }
}


void MaxHeap::show(){
        for(size_t i = 1; i < heapsize(); i++)
        {
            std::cout<<arr[i]<<"  ";
        }
        std::cout<<std::endl;
}


void Maxheap::add( int key){
    heapSize++;
    int i = heapSize - 1;

    while(i > 0 && arr[Parent(i)] <= key){
        arr[i] = arr[Parent(i)];
        i = Parent(i);
    }

    arr[i] = key;
}

void Maxheap::HeapSort(int arr[]){
    for(int i = heapSize - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapSize = heapSize - 1;
        Heapify(arr, 0);
    }
}

 int MaxHeap::operator[](size_t i){
        if(i < heapsize() - 1) 
            return arr[i + 1];
        else{
            std::cout<< "full" << std::endl;
            return 0;
        }
 }


int MaxHeap::getHeight(){
        return floor(log2(heapsize() - 1));
    }

int MaxHeap::Parent(int i){
        if(i > 1)
            return arr[i / 2];
        else
            return 0;
    }


int MaxHeap::RightChild(int i){
        return arr[(i << 2) + 1];
    }
int MaxHeap::LeftChild(int i){
        return arr[i << 2];
    }
int Maxheap::max(){
        return arr[1];
    }
 int MaxHeap::top(){
        return arr[1];
    }

 void MaxHeap::Delete(){
        if(heapsize() == 1) return; //just zero is existed
        std::swap(arr[1], arr[heapsize() - 1]);
        arr.pop_back();
        size_t current = 1;
        while(current < heapsize())
        {
            size_t largest = current;
            if((current << 1) < heapsize() && arr[current << 1] > arr[largest])
            {
                largest = current << 1;
            }
            if((current << 1) + 1 < heapsize() && arr[(current << 1) + 1] > arr[largest])
            {
                largest = (current << 1) + 1;
            }
            if(largest != current)
            {
                std::swap(arr[current], arr[largest]);
                current = largest;
            }
            else break;
        }
    }


/*
std::ostream& operator<<(std::ostream& os, const Maxheap& h){
   os<< h. printArray();
   //std::cout<<"cout"<<std::endl;
  return os;
}
