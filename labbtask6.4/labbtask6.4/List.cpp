#include <iostream>
#include <memory>
#include <stdexcept>
#include "Header.h"
template <typename T>
class List {
public:
    List() : start(nullptr), size(0) {}

    List(List<T>& data) : size(1) {
        start = std::make_unique<node>(data);
    }

    List(const List& other) : size(other.size) {
        if (other.start) {
            start = std::make_unique<node>(other.start->data);
            node* current = start.get();
            node* temp = other.start->next.get();
            while (temp) {
                current->next = std::make_unique<node>(temp->data);
                current = current->next.get();
                temp = temp->next.get();
            }
        }
    }

    List& operator=(const List& other) {
        if (this == &other) return *this;
        start.reset();
        size = other.size;
        if (other.start) {
            start = std::make_unique<node>(other.start->data);
            node* current = start.get();
            node* temp = other.start->next.get();
            while (temp) {
                current->next = std::make_unique<node>(temp->data);
                current = current->next.get();
                temp = temp->next.get();
            }
        }
        return *this;
    }

    List(List&& other) noexcept : start(std::move(other.start)), size(other.size) {
        other.size = 0;
    }

    List& operator=(List&& other) noexcept {
        if (this == &other) return *this;
        start = std::move(other.start);
        size = other.size;
        other.size = 0;
        return *this;
    }

    ~List() = default;

    List& add(T data) {
        auto newNode = std::make_unique<node>(data);
        if (!start) {
            start = std::move(newNode);
        }
        else {
            node* tempNode = start.get();
            while (tempNode->next) {
                tempNode = tempNode->next.get();
            }
            tempNode->next = std::move(newNode);
        }
        size++;
        return *this;
    }

    bool find(T data) {
        node* tempNode = start.get();
        while (tempNode) {
            if (tempNode->data == data) return true;
            tempNode = tempNode->next.get();
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& out, const List& list) {
        auto tempNode = list.start.get();
        while (tempNode) {
            out <<  *(tempNode->data)<< " ";
            tempNode = tempNode->next.get();
        }
        return out;
    }

    T getData() {
        if (start) return start->data;
        throw
            throw std::runtime_error("List is empty");
    }

    size_t Size() const {
        return size;
    }

    T operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        node* tempNode = start.get();
        for (size_t i = 0; i < index; i++) {
            tempNode = tempNode->next.get();
        }
        return tempNode->data;
    }

    List& deleting(size_t index) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }

        if (size == 1) {
            start = std::move(nullptr);
        }
        else {
            if (index == 0) {
                start = std::move(start->next);
            }
            else {
                node* current = start.get();
                for (size_t i = 0; i < index; ++i) {
                    current = current->next.get();
                }

                if (current->next.get() != nullptr) {
                    current = current->next.get();

                }
                else {
                    *current= std::move(nullptr);
                    std::cout << std::endl;
                }
            }

        }
        
        size--;
        return *this;
    }

private:
    class node {
    public:
        BASEofALL* data;
        std::unique_ptr<node> next;

        node(BASEofALL* value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<node> start;
    size_t size;
};


int main() {
    List<BASEofALL*> myList;
    
    int a[3] = {1,2,3};
    Ellipse ell(a,a,1,1,1,1,1);
    HyperLinkLabel hll("asd",a,"asd",1,1,1,1,1);
    TextBox tb;
    Button btn;

    //std::cin >> ell;
    std::cout << "-----------------\n";
    //std::cin >> hll;
    std::cout << "-----------------\n";
    //std::cin >> tb;
    std::cout << "-----------------\n";
    //std::cin >> btn;
    std::cout << "-----------------\n";
    //reinterpret_cast<BASEofALL*>(&ell)
    myList.add(&ell); // add(hll).add(tb).add(btn);
    myList.add(&hll);
    std::cout << "List contents: " << myList << std::endl;

    myList.deleting(1); 
    std::cout << "After deletion: " << myList << std::endl;

    std::cout << "Element at index 0: " << myList[0] << std::endl;

    return 0;
}
