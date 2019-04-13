#include<iostream>
#ifndef MAXHEAP_H
#define MAXHEAP_H


class Maxheap
{
   public : //constructors
        Maxheap();
	    Maxheap(int arr[] , int n);
	    Maxheap(const Maxheap& Maxheap);
	    void Heapify(int arr[], int i);
	    void BuildHeap(int arr[]);
        void add(int key);
	    void HeapSort(int arr[]);
	     int max();
	     int getHeight();
	     int Parent(int i);
	     int RightChild(int i);
	     int LeftChild(int i);
	     void show();
	     void Delete();
	     int top();
	     int operator[](size_t i);
	    
};

#endif






  /*

            int arr[MAX] ;
	    int count ;
	    
	    // void add ( int num ) ;
	    // void makeheap(int ) ;
	    //  void heapsort( ) ;
	    //  void display( ) ;
} ;
MaxHeap :: Maxheap( )
{
   count = 0 ;
   for ( int i = 0 ; i < MAX ; i++ )
	   arr[MAX] = 0 ;
}

void Maxheap :: add ( int num )
{
      	arr[count] = num ;
	count++ ;

}
void Maxheap :: makeheap(int c)
{
 
        for ( int i = 1 ; i < c ; i++ )
	{
		int val = arr[i] ;
		int s = i ;
		int f = ( s - 1 ) / 2 ;
		while ( s > 0 && arr[f] < val )
		{
			arr[s] = arr[f] ;
			s = f ;
			f = ( s - 1 ) / 2 ;
		}
		arr[s] = val ;
	}
}
void array :: heapsort( )
{
	for ( int i = count - 1 ; i > 0 ; i-- )
	{
		int ivalue = arr[i] ;
		arr[i] = arr[0] ;
		arr[0]=ivalue;
		makeheap(i);
 
	}
}
void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "\t" ;
	cout << endl ;
}
*/
