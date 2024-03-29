#include "Heap.h"

// idx�� �������� ���� �ڽ� ��ȯ
int GetLeftChild(int idx)
{
	return idx * 2;
}

// idx�� �������� ������ �ڽ� ��ȯ
int GetRightChild(int idx)
{
	return GetLeftChild(idx) + 1;
}

// idx�� �������� �θ� �ε����� ��ȯ
int GetParentIdx(int idx)
{
	return int(idx / 2);
}

// idx�� �������� ��/�� �ڽ��� �켱������ �����ϴ� �Լ�
int GetPriorityDataIdx(HEAP* pHeap, int idx)
{
	// 1. �ڽ��� �Ѵ� ���� ���
	if (GetLeftChild(idx) > pHeap->numOfData)
	{
		// Delete�Լ����� whileŻ�� �������� Ȱ���ϱ� ���� 0�� return �ϵ��� ���ش�.
		return 0;
	}
	// 2. ���� �ڽĸ� �ִ� ���
	else if (GetLeftChild(idx) == pHeap->numOfData)
	{
		return GetLeftChild(idx);
	}
	// 3. �ڽ��� �Ѵ� �ִ� ���
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
	// ���� ���� Ʈ���̱� ������ ������ ���� + 1�� ���� ������ ��ġ�� ����Ų��.
	int idx = pHeap->numOfData + 1;
	
	// ���� �ؿ��� ���� �θ�� ��¯�� �߸� �ö󰣴�.
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
	// while ���������� ���� childIdx�� �ʿ��ϴ�.
	// GetPriorityDataIdx���� �ڽ��� ������ 0�� ��ȯ�ϸ鼭 while�� ���� ���� ����� �� �ִ�.
	int childIdx = 0;

	// startIdx�������� �켱������ ���� �ڽ� idx�� �����´�.
	while (childIdx = GetPriorityDataIdx(pHeap, startIdx))
	{
		// lastData�� pHeap->heapArr[childIdx]���� �켱������ ���ų� ���� ��� break
		// (�켱������ ���ų� ���ٴ� ���� ���� ��ġ�� lastData�� �����Ѵٴ� ���̱⵵ ��.)
		if (pHeap->comp(lastData, pHeap->heapArr[childIdx]) >= 0)
			break;
		
		// lastData�� pHeap->heapArr[childIdx]���� �켱������ �������
		pHeap->heapArr[startIdx] = pHeap->heapArr[childIdx];
		startIdx = childIdx;
	}

	pHeap->heapArr[startIdx] = lastData;
	pHeap->numOfData--;
	return removeData;
}
