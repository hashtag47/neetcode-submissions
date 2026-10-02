#include <vector>

struct Node {
    Node(int val): value{val}, next{nullptr} {}
    int value;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head{nullptr}, size{0}{
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* current = head;
        for(int i  = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }
    
    void insertTail(int val) {
        Node* node = new Node(val);
        if (head == nullptr) { head = node; size++; return; }
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = node;
        size++;
    }

    bool remove(int index) {
        if(index < 0 || index >= size)
        {
            return false;
        }
        if (index == 0) {
            Node* current = head;
            head = head->next;
            delete current;
        } else {
            Node* prev = head;
            Node* current = head;
            for(int i = 0; i <index - 1; ++i) {
                prev = prev->next;
            }
            Node* r = prev->next;
            prev->next = r->next;
            delete(r);
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        std::vector<int> v;
        Node* current = head;
        while(current != nullptr) {
            v.push_back(current->value);
            current = current->next;
        }
        return v;
    }

private:
    Node* head;
    int size;
};
