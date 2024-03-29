#pragma once

#define MAX 100
typedef char DATA;
typedef int (*PriorityComp)(DATA d1, DATA d2); // 함수 포인터

typedef struct _heap
{
	PriorityComp comp;
	int numOfData;
	DATA heapArr[MAX];
} HEAP;

void HeapInit(HEAP* pHeap, PriorityComp comp);  // HEAP초기화
bool HeapEmpty(HEAP* pHeap);					// HEAP empty여부
void HeapInsert(HEAP* pHeap, DATA data);		// HEAP 데이터 추가
DATA HeapDelete(HEAP* pHeap);					// HEAP 데이터 삭제 (삭제후 삭제한 데이터 반환)
