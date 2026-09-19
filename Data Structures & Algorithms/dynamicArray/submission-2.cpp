#include <stdint.h>
#include <iostream>

class DynamicArray {
public:
    DynamicArray(int capacity) : capacity{capacity}, index{0} {
        arr = new int[capacity];
    }

    ~DynamicArray() {
        index = 0;
        capacity = 0;
        delete[] arr;
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
        if(index > 0) {
            index--;
        } 
        return arr[index];
    }

    void resize() {
        capacity *= 2;
        int* temp = new int[capacity];
        for(std::size_t i = 0; i < index; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
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
