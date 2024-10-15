#include <cassert>
#include <iostream>


struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(-1), next(nullptr) {};
  ListNode(int val): val(val), next(nullptr) {};
  ListNode(int val, ListNode* next): val(val), next(next) {};
};

ListNode* reverse(ListNode* head)
{
  ListNode* top_head = nullptr;
  if (!head || !head->next) return head;
  top_head = reverse(head->next);
  
  /* reverse */
  head->next->next = head;
  head->next = nullptr;

  return top_head;
}

void printList(const ListNode* const head);

int main(void)
{
  ListNode *ret;
  /* edge cases */
  ListNode* empty_lst = nullptr;
  ListNode* shortest_lst = new ListNode(1);
  ret = reverse(empty_lst);
  assert(ret == empty_lst);
  ret = reverse(shortest_lst);
  assert(ret == shortest_lst);

  /* base case */
  ListNode* simplest_lst = new ListNode(1, new ListNode(2));
  printList(simplest_lst);
  ret = reverse(simplest_lst);
  printList(ret);
  /* extended cases */
  ListNode* lst_1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  printList(lst_1);
  ret = reverse(lst_1);
  printList(ret);
}

void printList(const ListNode* const head)
{
  const ListNode* current_node = head;
  while (current_node) {
    std::cout << current_node->val << ' ';
    current_node = current_node->next;
  }
    std::cout << std::endl;
}
