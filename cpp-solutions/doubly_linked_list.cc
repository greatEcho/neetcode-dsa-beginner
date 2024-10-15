#include <iostream>
using std::cout; using std::endl;

class ListNode {
public:
  int val;
  ListNode* next;
  ListNode* prev;
  ListNode(int val): val(val), next(nullptr), prev(nullptr) {}
};

// doubly linked list class
class DLinkedList {
  ListNode* head;
  ListNode* tail;
public:
  DLinkedList() {
    head = new ListNode(-1);
    tail = head;
  }

  ~DLinkedList() {
    // it needed to escape memory leaks
    ListNode* cur_node = this->head;
    ListNode* next_node;
    do {
      next_node = cur_node->next; // save pointer
      delete cur_node; // free memory
      cur_node = next_node; // step
    } while (next_node);
  }

  ListNode* getHead(void) {
    return this->head->next;
  }

  ListNode* getTail(void) {
    return this->tail;
  }

  void insertFront(int val) {
    ListNode* new_node = new ListNode(val);
    if (head->next) {
      head->next->prev = new_node;
    } 
    new_node->next = head->next;
    new_node->prev = head;
    head->next = new_node;
    // we have empty list
    if (head == tail) tail = head->next;
  }

  void insertEnd(int val) {
    ListNode* new_node = new ListNode(val);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

  int popFront(void) {
    if (head == tail) return -1; // empty list
    ListNode* node_to_rm = head->next;
    int val = head->next->val;
    head->next = head->next->next;
    if (head->next) { // we have more than 1 element in list
      head->next->prev = head;
    }
    else { // we have only 1 element
      tail = head;
    }
    delete node_to_rm;
    return val;
  }

  int popEnd(void) {
    if (head == tail) return -1; // empty list
    int val = tail->val;
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    return val;
  }

  void print(void) {
    ListNode* cur_node = head->next;
    while (cur_node) {
      cout << cur_node->val << ' ';
      cur_node = cur_node->next;
    }
    cout << endl;
  }
  
  bool empty(void) {
    return head == tail;
  }
    
};


int main(void) 
{
  DLinkedList* lst = new DLinkedList();
  cout << lst->empty() << endl;
  lst->insertEnd(1);
  lst->popFront();
  lst->insertEnd(2);
  cout << lst->getTail()->val << endl;
  lst->popEnd();
  cout << lst->getTail()->val << endl;
  cout << lst->popEnd() << endl;
  lst->insertEnd(3);
  cout << lst->popEnd() << endl;
  cout << lst->popEnd() << endl;
  lst->insertFront(5);
  lst->insertFront(4);
  lst->insertFront(3);
  lst->insertEnd(6);
  lst->insertEnd(7);
  lst->print();
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  cout << lst->popFront() << endl;
  lst->print();
  cout << lst->empty() << endl;

  delete lst;

  

  return 0;
}
