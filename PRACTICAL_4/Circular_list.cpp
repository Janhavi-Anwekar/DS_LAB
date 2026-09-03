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

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

public:
    // Destructor to clean up memory
    ~LinkedList() {
        if (head == nullptr) return;
        Node* curr = head;
        Node* nextNode = nullptr;
        do {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        } while (curr != head);
    }

    void addFirst(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            head = node;
            tail = node;
            tail->next = head; // Make it circular
            size++;
            return;
        }
        node->next = head;
        head = node;
        tail->next = head;
        size++;
    }

    void addLast(int val) {
        if (head == nullptr) {
            addFirst(val);
            return;
        }
        Node* node = new Node(val);
        tail->next = node;
        tail = node;
        tail->next = head;
        size++;
    }

    void add(int val, int idx) {
        Node* node = new Node(val);
        Node* curr = head;
        while (idx > 0) {
            curr = curr->next;
            idx--;
        }
        node->next = curr->next;
        curr->next = node;
        size++;
    }

    Node* deleteFirst() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* del = head;
        if (head == tail) { // Only one element
            head = nullptr;
            tail = nullptr;
        } else {
            tail->next = head->next;
            head = tail->next;
        }
        size--;
        return del;
    }

    Node* deleteLast() {
        if (head == nullptr) {
            return nullptr;
        }
        Node* del = tail;
        if (head == tail) { // Only one element
            head = nullptr;
            tail = nullptr;
        } else {
            Node* curr = head;
            while (curr->next != del) {
                curr = curr->next;
            }
            curr->next = head;
            tail = curr;
        }
        size--;
        return del;
    }

    Node* deleteNode(int idx) { // Renamed from delete to avoid C++ keyword conflicts
        Node* curr = head;
        while (idx > 0) {
            curr = curr->next;
            idx--;
        }
        Node* del = curr->next;
        curr->next = del->next;
        if (del == tail) {
            tail = curr;
        }
        if (del == head) {
            head = curr->next;
        }
        size--;
        return del;
    }

    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* curr = head;
        do {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        } while (curr != head);
        std::cout << "HEAD" << std::endl;
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

    std::cout << "\nYour Circular Linked List:" << std::endl;
    list.display();

    return 0;
}
