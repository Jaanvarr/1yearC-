#pragma once
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;                                                                 //���� �� ����� - ��������� ����.
                                                                                //���� ��������� - ��������� �� �������.��������� ������� � ������
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}     //����� ����������
    };

    Node* head; //������ ������
    Node* tail; //����� ������

public:
    //����������� ��� ����������
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    //����������� � �����������
    DoublyLinkedList(const T& value) {
        head = new Node(value);
        tail = head;
    }

    //���������� (���!)
    ~DoublyLinkedList() {
        clear();
    }

    //������ �������!
    void initialize(const T& value) {
        if (head == nullptr) {
            head = new Node(value);
            tail = head;                //�� ��� ������� ���� ������� ��
        }
    }

    //��������� ����� �������
    void insert(const T& value) {
        Node* newNode = new Node(value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
    }

    //������� ��������
    void remove(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next; //������ �������
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev; //��������� �������
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    //���� �� ��������
    Node* find(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; //�� ����� :(
    }

    Node* getHead() const { return head; }

    Node* getTail() const { return tail; }

    //������� ����� ���������� ::)
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    //�������� ������
    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

    //������ ����
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;
        while (current) {
            insert(current->data);
            current = current->next;
        }
    }

    
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                insert(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    //������ ����
    DoublyLinkedList(DoublyLinkedList&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    // �������� ����
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }
};

