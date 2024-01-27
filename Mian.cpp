#include <iostream>

template<typename T>
class Node {
private:
    Node<T>* next;
    T data;
    Node<T>* prev;
public:
    Node() {
        next = nullptr;
        prev = nullptr;
    }
    explicit Node(T data, Node<T>* next, Node<T>* prev) {
        setNext(next);
        setPrev(prev);
        setData(data);
    }
    Node<T>* getNext() const {
        return next;
    }
    Node<T>* getPrev() const {
        return prev;
    }
    void setNext(Node<T>* next) {
        if (next != nullptr) {
            this->next = next;
        }
    }
    void setPrev(Node<T>* prev) {
        if (prev != nullptr) {
            this->prev = prev;
        }
    }
    T getData() const {
        return data;
    }
    void setData(T data) {
        this->data = data;
    }
};

template<typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoubleLinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
    }

    void AddToHead(const T& value) {
        Node<T>* newNode = new Node<T>(value, head, nullptr);
        if (!head) {
            tail = newNode;
        }
        else {
            head->setPrev(newNode);
        }
        head = newNode;
        size++;
    }

    void AddToTail(const T& value) {
        Node<T>* newNode = new Node<T>(value, nullptr, tail);
        if (!tail) {
            head = newNode;
        }
        else {
            tail->setNext(newNode);
        }
        tail = newNode;
        size++;
    }

    // –ешта метод≥в класу DoubleLinkedList без зм≥н...

    void Show() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
};

int main() {
    DoubleLinkedList<int> list;

    int choice;
    do {
        std::cout << "1. Add to head\n";
        std::cout << "2. Add to tail\n";
        std::cout << "3. Show list\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to add to head: ";
            int value;
            std::cin >> value;
            list.AddToHead(value);
            break;
        case 2:
            std::cout << "Enter value to add to tail: ";
            std::cin >> value;
            list.AddToTail(value);
            break;
        case 3:
            std::cout << "List: ";
            list.Show();
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
