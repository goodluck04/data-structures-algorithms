#include <iostream>

class LRUCache {
private:
    int* keys;
    int* values;
    int* keyToIndex;
    int capacity;
    int size;

public:
    LRUCache(int cap) : capacity(cap), size(0) {
        keys = new int[cap];
        values = new int[cap];
        keyToIndex = new int[10001]; // Assuming key is in the range [0, 10000]

        for (int i = 0; i < cap; ++i) {
            keyToIndex[i] = -1;
        }

        for (int i = 0; i < 10001; ++i) {
            keyToIndex[i] = -1;
        }
    }

    ~LRUCache() {
        delete[] keys;
        delete[] values;
        delete[] keyToIndex;
    }

    int get(int key) {
        int index = findKey(key);
        if (index != -1) {
            moveToHead(index);
            return values[index];
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        int index = findKey(key);

        if (index != -1) {
            values[index] = value;
            moveToHead(index);
        } else {
            if (size == capacity) {
                evict();
            }

            addToHead(key, value);
        }
    }

private:
    void moveToHead(int index) {
        for (int i = index; i > 0; --i) {
            keys[i] = keys[i - 1];
            values[i] = values[i - 1];
            keyToIndex[keys[i]] = i;
        }

        keys[0] = keys[index];
        values[0] = values[index];
        keyToIndex[keys[0]] = 0;
    }

    void addToHead(int key, int value) {
        for (int i = size; i > 0; --i) {
            keys[i] = keys[i - 1];
            values[i] = values[i - 1];
            keyToIndex[keys[i]] = i;
        }

        keys[0] = key;
        values[0] = value;
        keyToIndex[key] = 0;

        if (size < capacity) {
            ++size;
        }
    }

    int findKey(int key) {
        for (int i = 0; i < size; ++i) {
            if (keys[i] == key) {
                return i;
            }
        }
        return -1;
    }

    void evict() {
        // Remove the least recently used item (at the end of the array)
        int keyToEvict = keys[size - 1];
        keyToIndex[keyToEvict] = -1;
        --size;
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
