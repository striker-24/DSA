#include <cassert>   /// for assert
#include <iostream>  /// for I/O operations
#include <memory>    /// for dynamic memory
#include <new>       /// for managing  dynamic storage
This conversation was marked as resolved by Tishasoumya-02

namespace data_structures {

namespace linked_list {

class Node {
 public:
    int32_t val;  /// value of the current link
    Node *next;   /// pointer to the next value on the list
};

class list {
 private:
    Node *head;  // link before the actual first element
 public:

    list() {
        head = nullptr;  // Initialize the first link
    }
    bool isEmpty();
    void insert(int32_t new_elem);
    void reverseList();
    void display();
    int32_t top();
    int32_t last();
    int32_t traverse(int32_t index);
};

bool list::isEmpty() { return head == nullptr; }

void list::insert(int32_t n) {
    try {
        Node *new_node = new Node();
        Node *temp = nullptr;
        new_node->val = n;
        new_node->next = nullptr;
        if (isEmpty()) {
            head = new_node;
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    } catch (std::bad_alloc &exception) {
        std::cerr << "bad_alloc detected: " << exception.what() << "\n";
    }
}

void list::reverseList() {
    Node *curr = head;
    Node *prev = nullptr, *next_node = nullptr;
    while (curr != nullptr) {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    head = prev;
}

int32_t list::top() {
    try {
        if (!isEmpty()) {
            return head->val;
        }
    } catch (const std::exception &e) {
        std::cerr << "List is empty" << e.what() << '\n';
    }
}

int32_t list::last() {
    try {
        if (!isEmpty()) {
            Node *t = head;
            while (t->next != nullptr) {
                t = t->next;
            }
            return t->val;
        }
    } catch (const std::exception &e) {
        std::cerr << "List is empty" << e.what() << '\n';
    }
}

int32_t list::traverse(int index) {
    Node *current = head;

    int count = 0;
    while (current != nullptr) {
        if (count == index) {
            return (current->val);
        }
        count++;
        current = current->next;
    }
    assert(0);
}

}  // namespace linked_list
}  // namespace data_structures

static void test() {
This conversation was marked as resolved by Panquesito7

@Panquesito7 Panquesito7 25 days ago Member
Suggested change 
static void test() {

static void test() {
@Lazeeez	Reply…
    data_structures::linked_list::list L;
    // 1st test
    L.insert(11);
    L.insert(12);
    L.insert(15);
    L.insert(10);
    L.insert(-12);
    L.insert(-20);
    L.insert(18);
    assert(L.top() == 11);
    assert(L.last() == 18);
    L.reverseList();
    // Reversal Testing
    assert(L.top() == 18);
    assert(L.traverse(1) == -20);
    assert(L.traverse(2) == -12);
    assert(L.traverse(3) == 10);
    assert(L.traverse(4) == 15);
    assert(L.traverse(5) == 12);
    assert(L.last() == 11);
    std::cout << "All tests have successfully passed!" << std::endl;
}

int main() {
    test();  // run self-test implementations
    return 0;
}
