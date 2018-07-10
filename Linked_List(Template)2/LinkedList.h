#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename Type>
class Node
{
public:
	Type data; 
	Node* next; //���� ����Ű�� ��Ʈ �����ͺ���

public:
	Node() //������ NULL
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
	Node<Type>* Head; //�� ó�� ��� ����Ű�� ��������ͺ���

public:
	LinkedList()
	{
		Head = new Node<Type>(); //�� ��� 
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
	Node<Type>* temp = Head; //temp �� ����Ʈ? ��ó����� 
	while (temp->next != nullptr) //temp ������ Null �ƴҶ�����
		temp = temp->next; //temp�� temp ���� ��� ����
	temp->next = new Node<Type>(_data); //�Է¹��� data���� ��� �����ؼ� temp ������忡 ����
	
}

template<typename Type>
inline void LinkedList<Type>::Delete(Type _data)
{
	Node<Type>* prev = Head;
	Node<Type>* temp = Head->next; // prev�� temp �� ���������
	while (temp != nullptr) //temp�� nullptr�ƴҶ�����
	{
		if (temp->data == _data) //temp�� data�� ��������ϴ� data���� ������ Ż��
			break;
		prev = temp; // �ƴϸ� ��ĭ�� �ڷ�
		temp = temp->next;
	}

	if (temp == nullptr) return; //
	if (temp->next == nullptr) //temp���� ��尡 nullptr�϶�(�ǳ��� ���ﶧ)
	{
		prev->next = nullptr;
	}
	else//(�߰��� ���ﶧ)
	{
		prev->next = temp->next;
	}

}

template<typename Type>
inline void LinkedList<Type>::Print()
{
	Node<Type>* temp = Head->next; //temp �� ����Ʈ? ��ó�� �������
	while (temp!= nullptr) //temp(��ó������)�� Null �ƴҶ�����
	{
		cout << temp->data << "->";
		temp = temp->next; //temp�� temp ���� ��� ����
	}
	cout << endl;
}
