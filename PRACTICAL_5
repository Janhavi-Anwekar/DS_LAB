#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to prevent memory leaks
    ~DoublyLinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    // addFirst
    void insert(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            head = node;
            tail = node;
            return;
        }

        node->next = head;
        head->prev = node;
        head = node;
    }

    // delete
    void deleteNode() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List is now empty
        }
        delete temp;
    }

    // display forward
    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }
        std::cout << "END\n";
    }

    // display backward
    void displayReverse() {
        Node* curr = tail;
        std::cout << "END ";
        while (curr != nullptr) {
            std::cout << " -> " << curr->val;
            curr = curr->prev;
        }
        std::cout << "\n";
    }
};

int main() {
    DoublyLinkedList list;
    int choice = 0;

    while (choice != 5) {
        std::cout << "\n--- Menu ---\n";
        std::cout << "1 - Add\n2 - Delete\n3 - Display Forward\n4 - Display Reverse\n5 - Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                std::cout << "Enter values to add (enter -1 to stop):\n";
                while (true) {
                    std::cin >> val;
                    if (val == -1) break;
                    list.insert(val);
                }
                break;
            }
            case 2:
                list.deleteNode();
                std::cout << "Deleted head node.\n";
                break;
            case 3:
                list.display();
                break;
            case 4:
                list.displayReverse();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
