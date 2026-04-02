#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int id;
    string name;
    ListNode* next;
};

class NodeList {
private:
    ListNode* head;
    int count;

public:
    NodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        ListNode* n = new ListNode{id, name, head};
        head = n;
        count++;
    }

    void removeNode(int id) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;
        if (prev) prev->next = curr->next;
        else head = curr->next;
        delete curr;
        count--;
    }

    void display() const {
        ListNode* curr = head;
        while (curr) {
            cout << "(" << curr->id << ": " << curr->name << ") -> ";
            curr = curr->next;
        }
        cout << "null" << endl;
    }

    ~NodeList() {
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }

    NodeList(const NodeList& other) : head(nullptr), count(0) {
        ListNode* src = other.head;
        ListNode* tail = nullptr;
        while (src) {
            ListNode* n = new ListNode{src->id, src->name, nullptr};
            if (!head) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
            count++;
            src = src->next;
        }
    }

    NodeList& operator=(const NodeList& other) {
        if (this == &other) return *this;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        count = 0;
        ListNode* src = other.head;
        ListNode* tail = nullptr;
        while (src) {
            ListNode* n = new ListNode{src->id, src->name, nullptr};
            if (!head) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
            count++;
            src = src->next;
        }
        return *this;
    }
};

int main() {
    NodeList list;
    list.addNode(1, "A");
    list.addNode(2, "B");
    list.addNode(3, "C");

    cout << "initial list: ";
    list.display();

    list.removeNode(2);
    cout << "removed node2: ";
    list.display();

    NodeList list2 = list;
    list2.addNode(4, "D");
    cout << "original list: ";
    list.display();
    cout << "copied list with new node 4: ";
    list2.display();

    NodeList list3;
    list3 = list;
    cout << "assigned list: ";
    list3.display();

    return 0;
}
