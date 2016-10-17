/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 14/10/2016
-------------------------------------------------------------*/
#ifndef HEAP_H
#define HEAP_H
#include <string>
#include <iostream>
//#include "event.h"
template <class T >class Heap;
template <class T>
std::ostream &operator<<(std::ostream &out,const Heap<T> &print);

template <class T>
class Heap
{
	friend std::ostream &operator<< <T>(std::ostream &out,const Heap<T> & print);
	private:
		T * heap;
		int heapSize;
		int maxHeapSize;
	public:
		Heap();
		Heap(int);
		Heap(const Heap&);// Copy constructor
		~Heap();
		bool isEmpty() const;
		int parent(int) const;
		int child(int) const;
		int find(int, T) const;
		void insert(T);
		void removeByValue(T);
		void removeByIndex(int);
		void makeHeap(T array[], int size);
		T extractMin(); //Removes and returns min value
		void siftUp(int);
		void siftDown(int);
		int getMinIdx(int, int, int);
		T& getHeapElement(int) const;
		void setHeapElement(T, int);
		int getHeapSize()const;
		void heapSizeAddOne();
		void heapSizeMinusOne();
		int &getMaxHeapSize() const;
		bool judgeCustomerArriveOrServerFinish() const;//if return is true, mean next event is arrive
		void swap(int, int);
};
#endif
