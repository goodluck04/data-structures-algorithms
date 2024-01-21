#include <iostream>
#include <vector>


class MyHashMap {
private:
    std::vector<int> map;

public:
    MyHashMap() : map(1000001, -1) {}

    int get(int key) {
        return map[key];
    }

    void put(int key, int value) {
        map[key] = value;
    }

    void remove(int key) {
        map[key] = -1;
    }

    void printHashMap(){
        for(auto x : map){
            if(x > 0){
                std::cout<< x << std::endl;
            } 
        }
    }
};

int main() {
    // Example usage
    MyHashMap myHashMap;

    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    myHashMap.printHashMap();

    int result1 = myHashMap.get(1);
    // Expected output: 1
    std::cout << "Value for key 1: " << result1 << std::endl;

    int result2 = myHashMap.get(3);
    // Expected output: -1
    std::cout << "Value for key 3: " << result2 << std::endl;

    myHashMap.put(2, 1);

    int result3 = myHashMap.get(2);
    // Expected output: 1
    std::cout << "Updated value for key 2: " << result3 << std::endl;

    myHashMap.remove(2);

    int result4 = myHashMap.get(2);
    // Expected output: -1
    std::cout << "Value for key 2 after removal: " << result4 << std::endl;

    return 0;
}
