#include <iostream>

class BST {
private:
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* root;

    // Helper method to clear memory
    void deleteTree(Node* curr) {
        if (curr == nullptr) return;
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }

    // Helper method for insertion
    Node* insertRecursive(Node* curr, int val) {
        if (curr == nullptr) {
            return new Node(val);
        }

        if (val < curr->val) {
            curr->left = insertRecursive(curr->left, val);
        } 
        else if (val > curr->val) {
            curr->right = insertRecursive(curr->right, val);
        }

        return curr;
    }

    // Helper method for search
    int searchRecursive(Node* current, int target) {
        if (current == nullptr) {
            return -1;
        }

        if (target == current->val) {
            return current->val;
        }

        if (target < current->val) {
            return searchRecursive(current->left, target);
        } 
        else {
            return searchRecursive(current->right, target);
        }
    }

    // Helper method for Inorder
    void inorderRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        inorderRecursive(current->left);
        std::cout << current->val << " ";
        inorderRecursive(current->right);
    }

    // Helper method for Preorder
    void preorderRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        std::cout << current->val << " ";
        preorderRecursive(current->left);
        preorderRecursive(current->right);
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }

    // Destructor to prevent memory leaks
    ~BST() {
        deleteTree(root);
    }

    // Insertion
    void insert(int val) {
        root = insertRecursive(root, val);
    }
    
    // Search
    int search(int target) {
        return searchRecursive(root, target);
    }

    // Inorder 
    void inorder() {
        inorderRecursive(root);
        std::cout << std::endl;
    }

    // Preorder
    void preorder() {
        preorderRecursive(root);
        std::cout << std::endl; 
    }
};

int main() {
    BST tree;
    bool running = true;

    while (running) {
        std::cout << "1. Insert an element\n";
        std::cout << "2. Search for an element\n";
        std::cout << "3. View In-order traversal\n";
        std::cout << "4. View Pre-order traversal\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter integer value to insert: ";
                int insertVal;
                std::cin >> insertVal;
                tree.insert(insertVal);
                std::cout << insertVal << " inserted successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Enter integer value to search: ";
                int searchVal;
                std::cin >> searchVal;
                int result = tree.search(searchVal);
                if (result == -1) {
                    std::cout << "Result: -1 (Element not found)\n";
                } else {
                    std::cout << "Result: " << result << " (Element found)\n";
                }
                break;
            }
            case 3:
                std::cout << "In-order Traversal: ";
                tree.inorder();
                break;

            case 4:
                std::cout << "Pre-order Traversal: ";
                tree.preorder();
                break;

            case 5:
                std::cout << "Exiting application. Goodbye!\n";
                running = false;
                break;

            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
        std::cout << std::endl;
    }

    return 0;
}
