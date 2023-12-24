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
	TNode() { pNext = nullptr; }
};
template <class T>
class TQueue
{
	TNode<T>* pFirst, * pLast;

public:
	TQueue() { pFirst = nullptr; pLast = nullptr; };
	TQueue(const TQueue& q);
	bool IsEmpty() { return pFirst == nullptr; };
	bool Full()
	{
		TNode<T>* p = new TNode<T>;
		bool res = p == nullptr;
		delete p;
		return res;

	}
	void Clear();
	void Push(const T& element);
	T Pop();
	T Back();
	T Front();
	~TQueue() { Clear(); }
	TQueue<T>& operator=(const TQueue<T>& q);
	bool operator==(const TQueue<T>& q);

};

template <class T>
 TQueue<T>::TQueue(const TQueue<T> & q)
{
	TNode<T>* tmp = q.pFirst, * curr;
	pFirst = pLast = nullptr;
	while (tmp != nullptr)
	{
		curr = new TNode<T>;
		curr->val = tmp->val;
		if (pFirst == nullptr)
		{
			pFirst = curr;
			pLast = curr;
		}
		else
		{
			pLast->pNext = curr;
			pLast = curr;
		}
		tmp = tmp->pNext;
	}
}
 template<class T>
 void TQueue<T>::Clear()
 {
	 while (!IsEmpty())
	 {
		 Pop();
	 }
	 pFirst = nullptr;
	 pLast = nullptr;
 }
 template<class T>
  T TQueue<T>::Pop()
 {
	 if (IsEmpty())
	 {
		 throw "Queue is IsEmpty, you can't pop";
	 }

	 TNode<T>* tmp = pFirst;
	 T result = pFirst->val;
	 pFirst = pFirst->pNext;
	 delete tmp;
	 return result;
 }

 template<class T>
 void TQueue<T>::Push(const T& element)
 {
	 TNode<T>* tmp = new TNode<T>;
	 tmp->val = element;
	 tmp->pNext = nullptr;
	 if (IsEmpty())
	 {
		 pFirst = tmp;
		 pLast = tmp;
	 }
	 else
	 {
		 pLast->pNext = tmp;
		 pLast = tmp;
	 }
 }
 template<class T>
 inline T TQueue<T>::Front()
 {
	 if (IsEmpty())
	 {
		 throw "IsEmpty.";
	 }
	 return pFirst->val;
 }

 template<class T>
  T TQueue<T>::Back()
 {
	 if (IsEmpty())
	 {
		 throw "IsEmpty.";
	 }
	 return pLast->val;
 }
  template<class T>
 TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
  {
	  if (q.pFirst == nullptr)
	  {
		  Clear();
	  }
	  else
	  {
		  Clear();
		  TNode<T>* tmp = q.pFirst, * current;
		  while (tmp != nullptr)
		  {
			  current = new TNode<T>;
			  current->val = tmp->val;
			  if (pFirst == nullptr)
			  {
				  pFirst = current;
				  pLast = current;
			  }
			  else
			  {
				  pLast->pNext = current;
				  pLast = current;
			  }
			  tmp = tmp->pNext;
		  }
	  }
	  return *this;
  }

  template<class T>
  inline bool TQueue<T>::operator==(const TQueue<T>& q)
  {
	  TNode<T>* pRight = q.pFirst, * pLeft = pFirst;
	  while (pRight != nullptr || pLeft != nullptr) {
		  if (pRight->val != pLeft->val) {
			  return false;
		  }
		  pRight = pRight->pNext;
		  pLeft = pLeft->pNext;
	  }
	  if ((pRight == nullptr && pLeft != nullptr)
		  || (pLeft == nullptr && pRight != nullptr)) {
		  return false;
	  }
	  return true;

  }