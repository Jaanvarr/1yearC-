#pragma once
#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;                                                                 //одно из полей - структура узла.
                                                                                //поля структуры - указатели на прошлый.следующий элемент и данные
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}     //чисто консруткар
    };

    Node* head; //начало списка
    Node* tail; //конец списка

public:
    //конструктор без параметров
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    //конструктор с параметрами
    DoublyLinkedList(const T& value) {
        head = new Node(value);
        tail = head;
    }

    //деструктор (ого!)
    ~DoublyLinkedList() {
        clear();
    }

    //первый элемент!
    void initialize(const T& value) {
        if (head == nullptr) {
            head = new Node(value);
            tail = head;                //ну тип элемент один поэтому да
        }
    }

    //добавляем новый элемент
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

    //удаляем ненужное
    void remove(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next; //первый элемент
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev; //последний элемент
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    //ищем по значению
    Node* find(const T& value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; //не нашли :(
    }

    Node* getHead() const { return head; }

    Node* getTail() const { return tail; }

    //выводим чтобы посмотреть ::)
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    //затираем список
    void clear() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

    //констр копи
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

    //констр муве
    DoublyLinkedList(DoublyLinkedList&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    // оператор муве
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

