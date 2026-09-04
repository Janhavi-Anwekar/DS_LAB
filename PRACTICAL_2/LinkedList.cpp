#include <iostream>

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    // addFirst
    void addFirst(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            head = node;
            size++;
            return;
        }
        node->next = head;
        head = node;
        size++;
    }

    // addLast
    void addLast(int val) {
        if (head == nullptr) {
            addFirst(val);
            return; 
        }
        Node* node = new Node(val);
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = node;
        size++;
    }

    // add at index
    void add(int idx, int val) {
        if (idx == 0 || size == 0) {
            addFirst(val);
            return;
        }
        Node* node = new Node(val);
        Node* prev = head;
        for (int i = 1; i < idx; i++) {
            if (prev->next == nullptr) break; // Safety check
            prev = prev->next;
        }
        Node* nextNode = prev->next;
        prev->next = node;
        node->next = nextNode;
        size++;
    }

    // deleteFirst
    Node* deleteFirst() {
        if (size == 0) {
            return nullptr;
        }
        Node* del = head;
        head = head->next;
        size--;
        return del;
    }

    // deleteLast
    Node* deleteLast() {
        if (size == 0) {
            return nullptr;
        }
        if (size == 1) {
            return deleteFirst();
        }
        Node* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node* del = curr->next;
        curr->next = nullptr;
        size--;
        return del;
    }

    // display
    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }
        std::cout << "Null" << std::endl;
    }
};

int main() {
    LinkedList list;
    int input;

    std::cout << "Enter numbers to add to the list (Enter -1 to stop):" << std::endl;
    
    while (true) {
        std::cin >> input;
        if (input == -1) {
            break;
        }
        list.addLast(input);
    }

    std::cout << "Final Linked List:" << std::endl;
    list.display();

    return 0;
}
