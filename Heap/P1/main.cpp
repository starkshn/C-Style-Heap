#include <iostream>
#include "Heap.h"
using namespace std;

// 참고 자료
// https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html

int MinHeapPriorityData(char c1, char c2)
{
	return c2 - c1;
}

int MaxHeapPriorityData(char c1, char c2)
{
	return c1 - c2;
}

int main()
{
	HEAP heap;
	HeapInit(&heap, MinHeapPriorityData);
	HeapInsert(&heap, 'B');
	HeapInsert(&heap, 'C');
	HeapInsert(&heap, 'D');
	HeapInsert(&heap, 'A');

	while (HeapEmpty(&heap) != true)
	{
		cout << HeapDelete(&heap) << endl;
	}

	return 0;
}