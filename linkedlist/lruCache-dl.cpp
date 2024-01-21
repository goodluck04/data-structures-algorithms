#include <iostream>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int capacity;
    int size;

public:
    LRUCache(int cap) : capacity(cap), size(0), head(nullptr), tail(nullptr) {}

    ~LRUCache() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int get(int key) {
        Node* node = findNode(key);

        if (node != nullptr) {
            moveToHead(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        Node* node = findNode(key);

        if (node != nullptr) {
            node->value = value;
            moveToHead(node);
        } else {
            if (size == capacity) {
                evict();
            }

            addToHead(key, value);
        }
    }

private:
    Node* findNode(int key) {
        Node* current = head;

        while (current != nullptr) {
            if (current->key == key) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    void moveToHead(Node* node) {
        if (node == head) {
            return;
        }

        if (node == tail) {
            tail = node->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = head;
        node->prev = nullptr;

        if (head != nullptr) {
            head->prev = node;
        }

        head = node;

        if (tail == nullptr) {
            tail = node;
        }
    }

    void addToHead(int key, int value) {
        Node* newNode = new Node(key, value);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        ++size;
    }

    void evict() {
        if (tail != nullptr) {
            Node* temp = tail;
            tail = tail->prev;

            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }

            delete temp;

            --size;
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // Output: 1
    cache.put(3, 3);
    std::cout << cache.get(2) << std::endl; // Output: -1 (not found)
    cache.put(4, 4);
    std::cout << cache.get(1) << std::endl; // Output: -1 (not found)
    std::cout << cache.get(3) << std::endl; // Output: 3
    std::cout << cache.get(4) << std::endl; // Output: 4

    return 0;
}
