#pragma once

#define MAX 100
typedef char DATA;
typedef int (*PriorityComp)(DATA d1, DATA d2); // �Լ� ������

typedef struct _heap
{
	PriorityComp comp;
	int numOfData;
	DATA heapArr[MAX];
} HEAP;

void HeapInit(HEAP* pHeap, PriorityComp comp);  // HEAP�ʱ�ȭ
bool HeapEmpty(HEAP* pHeap);					// HEAP empty����
void HeapInsert(HEAP* pHeap, DATA data);		// HEAP ������ �߰�
DATA HeapDelete(HEAP* pHeap);					// HEAP ������ ���� (������ ������ ������ ��ȯ)
