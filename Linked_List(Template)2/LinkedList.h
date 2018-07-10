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
	int len = 0;
public:
	LinkedList()
	{
		Head = new Node<Type>(); //�� ��� 
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
	Node<Type>* temp = Head; //temp �� ����Ʈ? ��ó����� 
	while (temp->next != nullptr) //temp ������ Null �ƴҶ�����
		temp = temp->next; //temp�� temp ���� ��� ����
	temp->next = new Node<Type>(_data); //�Է¹��� data���� ��� �����ؼ� temp ������忡 ����
	
	len++;
}

template<typename Type>
inline bool LinkedList<Type>::Delete(Type _data)
{
	if (len == 0)
		return false;

	Node<Type>* prev = Head;
	Node<Type>* temp = Head->next; // prev�� temp �� ���������
	while (temp != nullptr) //temp�� nullptr�ƴҶ�����
	{
		if (temp->data == _data) //temp�� data�� ��������ϴ� data���� ������ Ż��
			break;
		prev = temp; // �ƴϸ� ��ĭ�� �ڷ�
		temp = temp->next;
	}

	if (temp == nullptr) return false; 
	if (temp->next == nullptr) //temp���� ��尡 nullptr�϶�(�ǳ��� ���ﶧ)
	{
		prev->next = nullptr;
		return true;
	}
	else//(�߰��� ���ﶧ)
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
	Node<Type>* temp = Head->next; //temp �� ����Ʈ? ��ó�� �������
	while (temp!= nullptr) //temp(��ó������)�� Null �ƴҶ�����
	{
		cout << temp->data << "->";
		temp = temp->next; //temp�� temp ���� ��� ����
	}
	cout << endl;
}

