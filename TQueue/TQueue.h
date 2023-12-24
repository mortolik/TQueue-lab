#pragma once
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;
template <class T>
struct TNode
{
	T val;
	TNode <T>* pNext;
};
template <class T>
class TQueue
{
	TNode<T>* pFirst, * pLast;
	T* pMem;
	int size, start, finish, count;

public:
	int GetStart() { return start; }
	int GetFinish() { return finish; }
	int GetCount() { return count; }
	TQueue(int _size) {
		pMem = new T[_size];
		size = _size;
		count = 0;
		start = 0;
		finish = -1;
	}

	TQueue(const TQueue& s) {
		size = s.size;
		pMem = new T[size];
		for (int i = 0; i < size; i++)
			pMem[i] = s.pMem[i];
		count = s.count;
		start = s.start;
		finish = s.finish;
	}
	~TQueue() { delete[] pMem; }

	int Size() { return size; }

	void Clear() {
		delete[] pMem;
		count = 0;
		start = 0;
		finish = -1;
	}

	bool operator == (const TQueue& s) {			//operator ==
		if (size != s.size) return false;
		else {
			if (start != s.start) return false;
			else {
				if (finish != s.finish) return false;
				else {
					for (int i = 0; i < size; i++) {
						if (pMem[i] != s.pMem[i]) return false;
					}
				}
			}
		}
		return true;
	}

	bool operator != (const TQueue& s) {			//operator != 
		if (*this == s) return false;
		else return true;
	}

	bool IsEmpty() {									//check of empty queue: if count = 0 -> queue is empty
		if (count == 0) return true;
		else return false;
	}

	bool IsFull() {									//check of full queue: if count = size -> queue is full
		if (count == size) return true;
		else return false;
	}
	TQueue& operator = (const TQueue& q)
	{
		if (*this == q)
		{
			return *this;
		}
		delete[] pMem;
		size = q.size;
		count = q.count;
		start = q.start;
		pMem = new T[size];
		std::copy(q.pMem, q.pMem + size, pMem);
		return *this;
	}
	void Push(const T& el) {
		if (count == size) throw("Full.");
		finish++;
		if (finish == size) finish = 0;
				pMem[finish] = el;				
		count++;
	}

	T Pop() {
		if (count == 0) throw ("Empty.");
		T el = pMem[start];
		start++;
		if (start == size) start = 0;
		count--;
		return el;
	}

	T Front() { return pMem[start]; }			
	T Back() { return pMem[finish]; }			

};