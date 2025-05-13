#pragma once

#include <iostream>

template <typename T> class List
{
public:
	List()							//constr no param
	{
		start = nullptr;
		size = 0;
	}


	List(T Data)					//constr param
	{
		start = new node(Data);
		start->next = nullptr;
		size = 1;
	}

	List(const List& other) {
		if (other.start == nullptr) {
			start = nullptr;
			size = 0;
			return;
		}
		start = new node(other.start->data);
		node* current = start;
		node* temp = other.start->next;
		while (temp != nullptr) {
			current->next = new node(temp->data);
			current = current->next;
			temp = temp->next;
		}
		current->next = nullptr; 
		size = other.size;
	}


	List& operator=(const List& other) {
		if (this == &other) return *this; //самоприсваивание
		this->~List();					  //освобождение
		size = other.size;
		if (other.start == nullptr) {
			start = nullptr;
			return *this;
		}
		start = new node(other.start->data);
		node* current = start;
		node* temp = other.start->next;
		while (temp != nullptr) {
			current->next = new node(temp->data);
			current = current->next;
			temp = temp->next;
		}
		current->next = nullptr; 
		return *this;
	}


	List(List&& other)
	{
		start = nullptr;
		size = other.size;
		other.size = 0;
		std::swap(start, other.start);
	}

	List operator=(List&& other) {}


	~List() {
		while (start != nullptr) {
			node* tempNode = start;
			start = start->next;
			delete tempNode;
		}
	}


	List& add(T data) {
		node* newNode = new node(data);
		if (start == nullptr) {
			start = newNode;
		}
		else {
			node* tempNode = start;
			while (tempNode->next != nullptr) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
		size++;
		return *this;
	}


	bool find(T dadta)
	{
		node* tempNode = start;
		while (tempNode->next != nullptr || tempNode->data != dadta)
		{
			if (tempNode->data == dadta)
				return true;
			tempNode = tempNode->next;
		}
		return false;

	}

	friend std::ostream& operator<<(std::ostream& out, const List& list) {
		typename List<T>::node* tempNode = list.start;
		while (tempNode != nullptr) {
			out << tempNode->data << " ";
			tempNode = tempNode->next;
		}
		return out;
	}




	T getData()
	{
		return start.data;
	}

	size_t Size()
	{
		return size;
	}

	T& operator[](size_t index)
	{

		if (index < size) 
		{
			node* tempNode = start;
			for (int i = 0; i < index; i++)
			{
				tempNode = tempNode->next;
			}
			return tempNode->data;
		}
		

	}

	
	List& deleting(size_t index) {
		if (index >= size) {
			throw std::out_of_range("Index out of range"); 
		}

		// Если удаляем первый элемент
		if (index == 0) {
			node* tempNode = start; 
			start = start->next; 
			delete tempNode; 
		}
		else {
			node* current = start;
			
			for (size_t i = 0; i < index - 1; ++i) {
				current = current->next;
			}
			// Удаляем узел
			node* tempNode = current->next; 
			current->next = tempNode->next;
			delete tempNode; 
		}

		size--; 
		return *this; 
	}



private:
	class node
	{
	public:
		T data;
		node* next;
		node(T papa) {
			data = papa;
			next = nullptr;
		}
		~node() {}

	private:

	};

	node* start;
	size_t size;

};



