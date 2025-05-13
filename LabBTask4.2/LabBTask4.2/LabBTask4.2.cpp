// LabBTask4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node
{
    Node() : next(nullptr) {}

    Node(int d) : data(d), next(nullptr) {}
    int data;
    Node* next;
};

class List
{
public:
    List() : start(nullptr), size(0) {}                           //конструктор без параметров


    List(int d)                         //конструктор по параметру
    {
        start = new Node(d);
        size = 1;
        start->next = nullptr;
    }

    List(List&& other)                  //конструктор перемещения
    {
        size = other.size;
        other.size = 0;
        start = other.start;
        other.start = nullptr;
    }

    List(const List& other)                    //оператор копирования
    {
        Node* temp = other.start;
        start = new Node(temp->data);
        Node* copyStart = start;
        while (temp->next != nullptr)
        {
            copyStart->next = temp->next;
            temp = temp->next;
            copyStart = copyStart->next;
        }
    }

    ~List()
    {
        Node* tmp = start;                              //деструктор
        while (start->next != nullptr)
        {
            start = start->next;
            delete tmp;
            tmp = start;
        }
    }

    List& operator=(const List& other)              //оператор копирования присваивания
    {
        if (start != nullptr)
        {
            Node* tmp = start;                              //деструктор
            while (start->next != nullptr)
            {
                start = start->next;
                delete tmp;
                tmp = start;
            }
        }
        start = new Node(other.start->data);
        Node* temp = start;
        Node* otherTemp = other.start;
        for (uint64_t i = 0; i < size; ++i)
        {
            temp->next = new Node(otherTemp->next->data);
            temp = temp->next;
            otherTemp = otherTemp->next;
        }
    }

    List& operator=(List&& other)                   //оператор перемещения
    {

    }

    void Add(int d)
    {
        Node* temp = start;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new Node(d);
    }

    void Erase(uint64_t num)
    {
        if (num < size)
        {
            Node* temp = start;
            for (uint64_t i = 0; i < num; ++i)
                temp = temp->next;
            Node* del = temp->next;
            if (temp->next->next != nullptr)
            {
                temp->next = temp->next->next;
            }
            else
            {

            }

        }
    }

    bool Find(int d)
    {
        Node* temp = start;
        while (temp->next != nullptr || temp->data != d)
        {
            temp = temp->next;
            if (temp->data == d)
            {
                //return temp->data;
                return true;
            }
        }
        return false;
    }

    void Output(List list)
    {

    }


private:

    Node* start;
    uint64_t size;

    friend std::ostream& operator<<(std::ostream& out, const List& list);
};

std::ostream& operator<<(std::ostream& out, const List& list)
{
    Node* temp = list.start;
    while (temp->next != nullptr)
    {
        out << temp->data << " ";

    }
    out << "\n";
    return out;
}

   
    


int main()
{
    uint64_t size = 10;
    List list(20);
    for (uint64_t i = 0; i < size; i++)
    {
        list.Add(rand() % 52);
    }
    std::cout << list;
}

