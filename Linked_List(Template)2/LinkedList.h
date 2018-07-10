#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename Type>
class Node
{
public:
	Type data; 
	Node* next; //다음 가리키는 노트 포인터변수

public:
	Node() //다음이 NULL
	{
		next = nullptr;
	};
	Node(Type _data)
	{
		data = _data;
		next = nullptr;
	};
	~Node() {};
};

template <typename Type>
class LinkedList
{
private:
	Node<Type>* Head; //맨 처음 노드 가리키는 노드포인터변수
	int len = 0;
public:
	LinkedList()
	{
		Head = new Node<Type>(); //빈 노드 
		len = 0;
	};
	~LinkedList() {};
public:
	int length();
	void Add(Type _data);
	bool Delete(Type _data);
	void Print();
	bool Delete_at(int idx);
};

template<typename Type>
inline int LinkedList<Type>::length()
{
	return len;
}

template<typename Type>
inline void LinkedList<Type>::Add(Type _data)
{
	Node<Type>* temp = Head; //temp 는 리스트? 맨처음노드 
	while (temp->next != nullptr) //temp 다음이 Null 아닐때까지
		temp = temp->next; //temp에 temp 다음 노드 대입
	temp->next = new Node<Type>(_data); //입력받은 data가진 노드 생성해서 temp 다음노드에 대입
	
	len++;
}

template<typename Type>
inline bool LinkedList<Type>::Delete(Type _data)
{
	if (len == 0)
		return false;

	Node<Type>* prev = Head;
	Node<Type>* temp = Head->next; // prev는 temp 전 노드포인터
	while (temp != nullptr) //temp가 nullptr아닐때까지
	{
		if (temp->data == _data) //temp의 data가 지우고자하는 data값과 같으면 탈출
			break;
		prev = temp; // 아니면 한칸씩 뒤로
		temp = temp->next;
	}

	if (temp == nullptr) return false; 
	if (temp->next == nullptr) //temp다음 노드가 nullptr일때(맨끝값 지울때)
	{
		prev->next = nullptr;
		return true;
	}
	else//(중간값 지울때)
	{
		prev->next = temp->next;
		return true;
	}
	return false;
}

template<typename Type>
bool LinkedList<Type>::Delete_at(int idx)
{
	if (len == 0)
		return false;

	if (idx > len || idx < 0)
		return false;
	if (idx == 0)
	{
		Node<Type>* temp = Head;
		Head = Head->next;
		delete temp;
		len--;
		return true;
	}

	Node<Type>* prev = Head;
	Node<Type>* curr = Head;
	for (int i = 0; i <= idx; i++)
	{
		prev = curr;
		curr = curr->next;

	}

	prev->next = curr->next;
	delete curr;
	curr = prev->next;
	len--;
	return true;
}

template<typename Type>
inline void LinkedList<Type>::Print()
{
	Node<Type>* temp = Head->next; //temp 는 리스트? 맨처음 다음노드
	while (temp!= nullptr) //temp(맨처음다음)가 Null 아닐때까지
	{
		cout << temp->data << "->";
		temp = temp->next; //temp에 temp 다음 노드 대입
	}
	cout << endl;
}

