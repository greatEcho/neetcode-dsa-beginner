#include <iostream>

ListNode *reverseList(ListNode *head)
{
  ListNode *nxt, prev = nullptr;
  while (head) {
    nxt = head->next;
    head->next = prev;
    prev = head;
    head = nxt;
  }
  return prev;
}

int main(void)
{
   



  return 0;
}
