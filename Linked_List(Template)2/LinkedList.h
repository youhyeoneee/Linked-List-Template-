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

public:
	LinkedList()
	{
		Head = new Node<Type>(); //빈 노드 
	};
	~LinkedList() {};
public:
	void Add(Type _data);
	void Delete(Type _data);
	void Print();
};

template<typename Type>
inline void LinkedList<Type>::Add(Type _data)
{
	Node<Type>* temp = Head; //temp 는 리스트? 맨처음노드 
	while (temp->next != nullptr) //temp 다음이 Null 아닐때까지
		temp = temp->next; //temp에 temp 다음 노드 대입
	temp->next = new Node<Type>(_data); //입력받은 data가진 노드 생성해서 temp 다음노드에 대입
	
}

template<typename Type>
inline void LinkedList<Type>::Delete(Type _data)
{
	Node<Type>* prev = Head;
	Node<Type>* temp = Head->next; // prev는 temp 전 노드포인터
	while (temp != nullptr) //temp가 nullptr아닐때까지
	{
		if (temp->data == _data) //temp의 data가 지우고자하는 data값과 같으면 탈출
			break;
		prev = temp; // 아니면 한칸씩 뒤로
		temp = temp->next;
	}

	if (temp == nullptr) return; //
	if (temp->next == nullptr) //temp다음 노드가 nullptr일때(맨끝값 지울때)
	{
		prev->next = nullptr;
	}
	else//(중간값 지울때)
	{
		prev->next = temp->next;
	}

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
