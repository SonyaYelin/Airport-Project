#ifndef __LinkedList_H
#define __LinkedList_H

#include <iostream>
using namespace std;

// all types must implement operator<<

template<class T>
class LinkedList
{
	class Node;

private:
	class Node
	{
		friend class LinkedList<T>;
	public:
		Node(const T& info);
		const T& getInfo() const;
		const Node* getNext() const;

	private:
		T*		info;
		Node*	next;

	};

	Node* head;
	Node* tail;

public:
	LinkedList();
	~LinkedList();

	LinkedList(const LinkedList<T>& list) = delete;
	const LinkedList<T> operator=(const LinkedList<T>& list) = delete;

	void addToTail(const T& t);
	void remove(const T& t);
	bool contains(const T& item) const;
	
	template<class T>
	friend ostream& operator<<(ostream& os, const LinkedList<T>& list);
};

template<class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr)
{
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node* temp1 = head;
	Node* temp2;
	if (!head) // head is null
		return;
	
	temp2 = head->next;
	
	while (temp1 != nullptr)
	{
		delete temp1;
		temp1 = temp2;
		if (temp1)
			temp2 = temp2->next;
	}
}

template<class T>
void LinkedList<T>::addToTail(const T& info)
{
	if (head == nullptr)
	{
		head = new Node(info);
		tail = head;
	}
	else
	{
		tail->next = new Node(info);
		tail = tail->next;
	}
}

template<class T>
void LinkedList<T>::remove(const T& info)
{
	Node* ptr1 = head;
	Node* ptr2 = head->next;

	if (head->info == &info)
	{
		ptr1 = head;
		head = head->next;
		delete ptr1;
		return;
	}

	while (ptr2 != nullptr)
	{
		if (ptr2->info == &info)
		{
			if (ptr2 == tail)
				tail = ptr1;
			
			ptr1->next = ptr2->next;
			delete ptr2;
			return;
		}
	}
}

template<class T>
bool LinkedList<T>::contains(const T& item) const
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->info == &item)
			return true;
		
		temp = temp->next;
	}
	return false;
}

template<class T>
LinkedList<T>::Node::Node(const T& t) 
{
	info = (T*)&t;
	next = nullptr;
}

template<class T>
const T& LinkedList<T>::Node::getInfo() const
{
	return *(LinkedList<T>::Node::info);
}

template<class T>
const typename LinkedList<T>::Node* LinkedList<T>::Node::getNext() const
{
	return LinkedList<T>::Node::next;
}

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& list)
{
	const typename LinkedList<T>::Node* temp = list.head;
	while (temp != nullptr)
	{
		os << temp->getInfo() << endl;
		temp = temp->getNext();
		os << endl;
	}
	return os;
}
#endif