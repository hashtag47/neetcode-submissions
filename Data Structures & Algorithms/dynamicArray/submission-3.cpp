#include <stdint.h>
#include <iostream>

class DynamicArray {
public:
    DynamicArray(int capacity) : m_capacity{capacity}, m_index{0} {
        m_arr = new int[m_capacity];
    }

    ~DynamicArray() {
        m_index = 0;
        m_capacity = 0;
        delete[] m_arr;
    }

    int get(int i) {
        return m_arr[i];
    }

    void set(int i, int n) {
        m_arr[i] = n;
    }

    void pushback(int n) {
        if(m_index == m_capacity) {
            resize();
        }
        m_arr[m_index++] = n;
    }

    int popback() {
        if(m_index > 0) {
            m_index--;
        } 
        return m_arr[m_index];
    }

    void resize() {
        m_capacity *= 2;
        int* temp = new int[m_capacity];
        for(std::size_t i = 0; i < m_index; ++i) {
            temp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = temp;
    }

    int getSize() {
        return m_index;
    }

    int getCapacity() {
        return m_capacity;
    }
private: 
    std::size_t m_index;
    int m_capacity;
    int* m_arr;
};
