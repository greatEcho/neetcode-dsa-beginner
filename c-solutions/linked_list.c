#include <stdio.h>

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

typedef struct LinkedList {
  ListNode *head;
  ListNode *tail;
} LinkedList;

void insert(LinkedList *lst, int val)
{
  ListNode new_node = {
    .value = val,
    .next = NULL
  };
  lst->tail = &new_node;
  printf("%p\n", lst->tail);
  printf("%d\n", lst->tail->value);
}

#if 0
ListNode* new_ListNode(int val)
{
  ListNode new_node = {
    .value = val,
    .next = NULL,
  };
  return &new_node;
}
#endif

int main(void)
{
  ListNode n1;
  ListNode n2;
  n1.value = 0;
  n2.value = 1;

  ListNode *pn3;
  pn3->value = 2;


  // Linked List
  LinkedList list1 = {
    .head = &( (ListNode) {.value=0, .next=NULL}),
    .tail = list1.head,
  };

  insert(&list1, -4);
  //printf("%d\n", list1.node.value);
  //printf("%p\n", list1.tail->next);

  ListNode *pcur = list1.head;
  printf("%d\n", list1.head->value);
  printf("%p\n", list1.head->next);
  while (pcur->next != NULL) {
    printf("%d\n", pcur->value);
  }

  return 0;
}
