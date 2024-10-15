#include <iostream>
#include <vector>

using std::cout; using std::endl; using std::vector;

class ListNode {
  public:
    int value;
    ListNode* next = nullptr;

    ListNode(int val): value(val) {};
};

class LinkedList {
  private:
    ListNode* get_ref(int index)
    {
      size_t i = 0;
      ListNode *cur = head;
      while (cur != nullptr) {
        if (i == index) {
          return cur;
        }
        cur = cur->next;
        i++;
      }
      return nullptr;
    }


  public: 
    ListNode* head;
    ListNode* tail;
    LinkedList() 
    {
      // the Dummy node. We will never use this node as users
      head = new ListNode(-1);
      tail = head;
    }

    ~LinkedList()
    {
      ListNode *tmp;
      while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
      }
    }

    void insertHead(int val)
    {
      ListNode *new_head = new ListNode(val);
      new_head->next = head->next;
      if (head == tail)
        tail = new_head;
      head->next = new_head;
    }

    // add elemnt at the end
    void insertTail(int val)
    {
      tail->next = new ListNode(val);
      tail = tail->next;
    }

    // get value by index
    int get(int index)
    {
      ListNode *cur = head->next;
      size_t i = 0;
      while (cur != nullptr) {
        if (i == index)
          return cur->value;
        cur = cur->next;
        i++;
      }
      return -1;
    }

    bool remove(int index)
    {
      #if 0
      // remove head
      if (index == 0) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
      }
      #endif

      // get the first element
      ListNode *prev = head;
      ListNode *cur = head->next;
      size_t i = 0; // index
      // we will remove final prev->next
      while (cur != nullptr) {
        if (i == index) {
          if (cur->next == nullptr) {
            tail = prev;
            prev->next = nullptr;
          }
          else {
            prev->next = prev->next->next; // or cur->next
          }
          delete cur;
          return true;
        }
        prev = prev->next;
        cur = cur->next;
        i++;
      }
      return false;
    }

    vector<int> getValues(void)
    {
      vector<int> vals {};
      ListNode *cur = head->next;
      while (cur != nullptr) {
        vals.push_back(cur->value);
        cur = cur->next;
      }
      return vals;
    }
    ListNode* getHead(void)
    {
      return this->head->next;
    }

    void printValues(void)
    {
      vector<int> vals = getValues();
      for (auto i: vals)
        cout << i << " ";
      cout << endl;
    }
};

ListNode* myReverseList(ListNode* head)
{
  // length 0
  if (head == nullptr) {
    return head;
  }
  // length 1
  if (head->next == nullptr) {
    return head;
  }
  // length 2
  if (head->next->next == nullptr) {
    head->next->next = head;
    head = head->next;
    head->next->next = nullptr;
    return head;
  }
  // length >2
  // first iteration
  ListNode* cur = head->next;
  ListNode* nxt = head->next->next;
  cur->next = head;
  head = cur;
  head->next->next = nullptr;
  cur = nxt;
  do {
    nxt = nxt->next;
    cur->next = head;
    head = cur;
    cur = nxt;
  } while (cur != nullptr);
  
  return head;
}

ListNode* reverseList(ListNode *head)
{
  ListNode* nxt, *prev = nullptr;
  while (head != nullptr) {
    nxt = head->next;
    head->next = prev;
    prev = head;
    head = nxt;
  }
  return prev;
}


int main(void)
{
  LinkedList list1;
  
  list1.insertTail(2);
  list1.printValues();
  list1.insertHead(1);
  list1.printValues();
  list1.insertHead(0);
  list1.printValues();

  list1.insertHead(-12);
  list1.printValues();
  list1.insertTail(3);
  list1.printValues();
  list1.remove(5);
  list1.printValues();

  list1.head->next = myReverseList(list1.head->next); 
  list1.printValues();
  list1.head->next = reverseList(list1.head->next); 
  list1.printValues();

  return 0;
}
