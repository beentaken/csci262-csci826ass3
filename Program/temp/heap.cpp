/*-------------------------------------------------------------
Student's Name: Boyang YAN
Student's email address: by932@uowmail.edu.au
Last Modification: 014/10/2016
-------------------------------------------------------------*/
#include <iostream>
#include "heap.h"
//#include "event.h"
using namespace std;
template <class T>
Heap<T>::Heap()
{
	heap = NULL;
	heapSize = 0;
	maxHeapSize = 0;
}
template <class T>
Heap<T>::Heap(int heapMaxSize)
{
	heap = new T[heapMaxSize];
	heapSize = 0;
	maxHeapSize = heapMaxSize;
}
template <class T>
Heap<T>::Heap(const Heap& source)// Copy constructor
{
	heapSize = source.heapSize;
	maxHeapSize = source.maxHeapSize;
	heap = new T[source.heapSize];
	for (int i = 0; i < source.heapSize; i++)
		heap[i] = source.heap[i];
}
template <class T>
Heap<T>::~Heap()
{
	delete []heap;
	heapSize = 0;
	maxHeapSize = 0;
}
template <class T>
bool Heap<T>::isEmpty() const
{
	return (heapSize == 0);
}
template <class T>
int Heap<T>::parent(int index) const
{
	if (heapSize <= 1)//empty or root has no parent
		return -1;
	return static_cast<int>(index / 2);
}
template <class T>
int Heap<T>::child(int index) const
{
	if (heapSize <= 1 || 2 * index > heapSize )//empty or root has no child
		return -1;
	return (2 * index);
}
template <class T>
int Heap<T>::find(int serchStartIndex, T val) const	//find val is index
{
	if (serchStartIndex > heapSize)//index out of bounds
		return -1;
	if (val < heap[serchStartIndex])//value not in heap
		return -1;
	if (heap[serchStartIndex] == val)
		return serchStartIndex; //Found the value, return its index

	int childIndex = child(serchStartIndex);
	int i = -1;

	if (childIndex != -1)//find in left and right children
		i = max(find(childIndex, val), find(childIndex + 1, val));
	return i;
}
template <class T>
void Heap<T>::siftUp(int index)
{
	int parentIdx = parent(index);
	if (parentIdx == -1)//index is roof
		return;
	if (heap[index] < heap[parentIdx])
	{
		swap(parentIdx, index);
		siftUp(parentIdx);
	}
	return;
}
template <class T>
void Heap<T>::insert(T val)
{
	heapSize++;
	if (heapSize > maxHeapSize)
	{
		cout << "heap is full :(" << endl;
		return;
	}
	heap[heapSize] = val;
	siftUp(heapSize);
	return;
}
template <class T>
int Heap<T>::getMinIdx(int aIdx, int bIdx, int cIdx)//in this three find the minimum
{
	bool isLeftSmaller = heap[aIdx] < heap[bIdx];
	if (cIdx > static_cast<int>(heapSize))//the last right child doesnt exist
		return isLeftSmaller ? aIdx : bIdx;
	else if (isLeftSmaller)
		return (heap[aIdx] < heap[cIdx]) ? aIdx : cIdx;
	else
		return (heap[bIdx] < heap[cIdx]) ? bIdx : cIdx;
}
template <class T>
void Heap<T>::siftDown(int index)
{
	int childIndex = child(index);
	if (childIndex == -1)//no children left
		return;
  	int minIdx = getMinIdx(index, childIndex, childIndex + 1);
	if (minIdx != index)
	{
		swap(minIdx, index);
		siftDown(index);
	}
	return;
}
template <class T>
void Heap<T>::removeByValue(T val)
{
	int index = find(0, val);
	if (index == -1) return;
	swap(index, heapSize--); //swap current with last item
	siftDown(index);
	return;
}
template <class T>
void Heap<T>::removeByIndex(int index)
{
	if (index > heapSize)
	{
		cout << "Error: this index does not exist :(" << endl;
		return;
	}
	swap(index, heapSize--); //swap current with last item
	siftDown(index);
	return;

}
template <class T>
T Heap<T>::extractMin()
{
 	if (isEmpty())
 		throw "Empty Heap!";
	int min = heap[0];
	removeByIndex(0);
	return min;
}
template <class T>
void Heap<T>::makeHeap(T array[], int n)// Create the heap given an unsorted array
{
	heapSize = n;
	for (int i = 0; i < n; i++)
    		heap[i] = array[i];
	for (int i = 0; i < n; i++)
		siftUp(i);
	return;
}
template <class T>
T& Heap<T>::getHeapElement(int which) const
{
	return heap[which];
}
template <class T>
void Heap<T>::setHeapElement(T data, int which)
{
	heap[which] = data;
	return;
}
template <class T>
bool Heap<T>::judgeCustomerArriveOrServerFinish() const//if return is true, mean next event is arrive
{
	if (heap[0].getId() == 0)//event is arrive
		return true;
	else
		return false;
}
template <class T>
int Heap<T>::getHeapSize() const
{
	return heapSize;
}
template <class T>
void Heap<T>::heapSizeAddOne()
{
	heapSize++;
	return;
}
template <class T>
void Heap<T>::heapSizeMinusOne()
{
	if(heapSize != 0)
		heapSize--;
	return;
}
template <class T>
int &Heap<T>::getMaxHeapSize() const
{
	return maxHeapSize;
}
template <class T>
std::ostream & operator << (std::ostream &out,const Heap<T> & print)
{
	for (int i = 0; i < print.heapSize; i++)
		out << print.getHeapElement(i) << endl;
	out << endl;
	//out << *(print.heap);
	out << "heapSize = " << print.heapSize;
	out << "maxHeapSize = " << print.maxHeapSize << endl;
	return out;
}
template <class T>
void Heap<T>::swap(int indexA, int indexB)
{
	T temp = heap[indexA];
	heap[indexA] = heap[indexB];
	heap[indexB] = temp;
	return;
}
