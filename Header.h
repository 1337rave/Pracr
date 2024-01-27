#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

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

    void DeleteFromHead() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->getNext();
        if (head) {
            head->setPrev(nullptr);
        }
        else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }

    void DeleteFromTail() {
        if (!tail) return;
        Node<T>* temp = tail;
        tail = tail->getPrev();
        if (tail) {
            tail->setNext(nullptr);
        }
        else {
            head = nullptr;
        }
        delete temp;
        size--;
    }

    void DeleteAll() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void Show() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }
};


#endif // DOUBLE_LINKED_LIST_H

