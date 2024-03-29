#include "Heap.h"

// idx를 기준으로 왼쪽 자식 반환
int GetLeftChild(int idx)
{
	return idx * 2;
}

// idx를 기준으로 오른쪽 자식 반환
int GetRightChild(int idx)
{
	return GetLeftChild(idx) + 1;
}

// idx를 기준으로 부모 인덱스를 반환
int GetParentIdx(int idx)
{
	return int(idx / 2);
}

// idx를 기준으로 왼/오 자식중 우선순위를 결정하는 함수
int GetPriorityDataIdx(HEAP* pHeap, int idx)
{
	// 1. 자식이 둘다 없는 경우
	if (GetLeftChild(idx) > pHeap->numOfData)
	{
		// Delete함수에서 while탈출 조건으로 활용하기 위해 0을 return 하도록 해준다.
		return 0;
	}
	// 2. 왼쪽 자식만 있는 경우
	else if (GetLeftChild(idx) == pHeap->numOfData)
	{
		return GetLeftChild(idx);
	}
	// 3. 자식이 둘다 있는 경우
	else
	{
		if (pHeap->comp(pHeap->heapArr[GetLeftChild(idx)], pHeap->heapArr[GetRightChild(idx)]) > 0)
		{
			return GetLeftChild(idx);
		}
		else return GetRightChild(idx);
	}
}

void HeapInit(HEAP* pHeap, PriorityComp comp)
{
    pHeap->numOfData = 0;
	pHeap->comp = comp;
	for (size_t i = 0; i < MAX; i++)
	{
		pHeap->heapArr[i] = ' ';
	}
}

bool HeapEmpty(HEAP* pHeap)
{
	if (pHeap->numOfData == 0) 
		return true;
	else 
		return false;
}

void HeapInsert(HEAP* pHeap, DATA data)
{
	// 완전 이진 트리이기 때문에 데이터 개수 + 1이 가장 마지막 위치를 가리킨다.
	int idx = pHeap->numOfData + 1;
	
	// 가장 밑에서 부터 부모와 맞짱을 뜨며 올라간다.
	while (idx != 0)
	{
		if (pHeap->comp(data, pHeap->heapArr[GetParentIdx(idx)]) >= 0)
		{
			pHeap->heapArr[idx] = pHeap->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}

	pHeap->heapArr[idx] = data;
	pHeap->numOfData++;
}

DATA HeapDelete(HEAP* pHeap)
{
	DATA removeData = pHeap->heapArr[1];
	DATA lastData = pHeap->heapArr[pHeap->numOfData];
	
	int startIdx = 1;
	// while 빠져나가기 위한 childIdx가 필요하다.
	// GetPriorityDataIdx에서 자식이 없으면 0을 반환하면서 while문 끝날 것을 기대할 수 있다.
	int childIdx = 0;

	// startIdx기준으로 우선순위가 높은 자식 idx를 가져온다.
	while (childIdx = GetPriorityDataIdx(pHeap, startIdx))
	{
		// lastData가 pHeap->heapArr[childIdx]보다 우선순위가 같거나 높은 경우 break
		// (우선순위가 같거나 높다는 말은 현재 위치에 lastData가 들어가야한다는 뜻이기도 함.)
		if (pHeap->comp(lastData, pHeap->heapArr[childIdx]) >= 0)
			break;
		
		// lastData가 pHeap->heapArr[childIdx]보다 우선순위가 낮은경우
		pHeap->heapArr[startIdx] = pHeap->heapArr[childIdx];
		startIdx = childIdx;
	}

	pHeap->heapArr[startIdx] = lastData;
	pHeap->numOfData--;
	return removeData;
}
