#pragma once
#include <iostream>

template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};

template <class T>
class Stack
{
	TLink<T>* pFirst;
public:
	Stack()
	{
		pFirst = NULL;
	}

	Stack(const Stack <T>& m) //конструктор копирования
	{
		if (m.pFirst!=NULL)
		{
			TLink<T>* tmp = m.pFirst;
			TLink<T>* prev = new TLink<T>;
			prev->val = tmp->val;
			pFirst = prev;
			tmp = tmp->pNext;
			while (tmp != NULL)
			{
				TLink<T>* p = new TLink<T>;
				p->val = tmp->val;
				prev->pNext = p;
				prev = prev->pNext;
				tmp = tmp->pNext;
				prev->pNext = NULL;
			}
		}
		else
		{
			pFirst = NULL;
		}
	}

	~Stack() //деструктор
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}

	Stack& operator=(const Stack <T>& m)
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		TLink<T>* prev = new TLink<T>;
		TLink<T>* tmp = m.pFirst;
		pFirst = prev;
		prev->val = m.pFirst->val;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			TLink<T>* p = new TLink<T>;
			p->val = tmp->val;
			prev->pNext = p;
			prev = prev->pNext;
			tmp = tmp->pNext;
			prev->pNext = NULL;
		}
		return *this;
	}

	bool Empty()
	{
		if (pFirst == NULL)
		{
			return true;
		}
		return false;
	}

	bool Full()
	{
		try
		{
			Pop();
			if (!Pop())
			{
				throw 0;
			}
		}
		catch (...)
		{
			return "Stack is full";
		}
	}

	void Push(T a)
	{
		TLink<T>* tmp = new TLink<T>;
		tmp->val = a;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}

	T Pop()
	{
		if (Empty())
		{
			throw 0;
		}
		T tmp = pFirst->val;
		TLink<T>* t = pFirst;
		pFirst = pFirst->pNext;
		delete t;
		return tmp;
	}

	T Top()
	{
		if (Empty())
		{
			throw 0;
		}
		return pFirst->val;;
	}

	bool operator==(const Stack<T>& m) const
	{
		TLink<T>* tmp = pFirst;
		TLink<T>* p = m.pFirst;
		do
		{
			if (p == NULL && tmp == NULL)
			{
				return true;
			}
			if (p->val != tmp->val)
			{
				return false;
			}
			tmp = tmp->pNext;
			p = p->pNext;
		} while (true);
	}

	bool operator!=(const Stack<T>& m) const
	{
		return !(*this == m);
	}
};
