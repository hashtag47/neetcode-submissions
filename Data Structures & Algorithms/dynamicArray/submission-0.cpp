#include <stdint.h>
#include <iostream>

class DynamicArray {
public:
    DynamicArray(int capacity) {
        if(capacity > 0) {
            this->capacity = capacity;
            index = 0;
            arr = new int[capacity];
        }
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(index == capacity) {
            resize();
        }
        arr[index++] = n;
    }

    int popback() {
        if(index == 0) {
            return -1;
        } else {
            return arr[--index];
        }
    }

    void resize() {
        if(index == capacity) {
            std::size_t prev = index;
            this->capacity *= 2;
            int* temp = new int[this->capacity];
            for(std::size_t i = 0; i < prev; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
    }

    int getSize() {
        return index;
    }

    int getCapacity() {
        return capacity;
    }
private: 
    std::size_t index;
    int capacity;
    int* arr;
};
