#include "Header.h"

int main() {
    // Create a DoubleLinkedList object for integers
    DoubleLinkedList<int> list;

    // Add elements to the list
    list.AddToTail(1);
    list.AddToTail(2);
    list.AddToHead(3);

    // Print all elements in the list
    std::cout << "List after adding elements: ";
    list.Show(); // Outputs: 3 1 2

    // Delete elements from the head and tail of the list
    list.DeleteFromHead();
    list.DeleteFromTail();

    // Print elements after deletion
    std::cout << "List after deleting elements: ";
    list.Show(); // Outputs: 1

    // Delete all elements
    list.DeleteAll();

    return 0;
}

