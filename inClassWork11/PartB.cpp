#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct SmartListNode {
    int id;
    string name;
    unique_ptr<SmartListNode> next;

    SmartListNode(int i, string n, unique_ptr<SmartListNode> nx) : id(i), name(n), next(std::move(nx)) {}
};

class SmartNodeList {
private:
    unique_ptr<SmartListNode> head;
    int count;

public:
    SmartNodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        head = make_unique<SmartListNode>(id, name, std::move(head));
        count++;
    }

    void removeNode(int id) {
        SmartListNode* prev = nullptr;
        SmartListNode* curr = head.get();
        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next.get();
        }
        if (!curr) return;

        if (prev) {
            prev->next = std::move(curr->next);
        } 
        else {
            head = std::move(curr->next);
        }
        count--;
    }

    void display() const {
        SmartListNode* curr = head.get();
        while (curr) {
            cout << "(" << curr->id << ": " << curr->name << ") -> ";
            curr = curr->next.get();
        }
        cout << "null" << endl;
    }
};

int main() {
    SmartNodeList list;
    list.addNode(1, "A");
    list.addNode(2, "B");
    list.addNode(3, "C");

    cout << "initial list: ";
    list.display();

    list.removeNode(2);
    cout << "after removing node 2: ";
    list.display();

    list.addNode(4, "D");
    cout << "after adding node 4: ";
    list.display();

    return 0;
}
