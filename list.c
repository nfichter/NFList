#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next;};

void print_list(struct node *list) {
  printf("%d",list->i);
  if (list->next != NULL) {
    printf(",");
    print_list(list->next);
  } else {
    printf("\n");
  }
}

struct node * insert_front(struct node *list, int data) {
  struct node *newFront = (struct node*)malloc(sizeof(struct node));
  newFront->i = data;
  newFront->next = list;
  return newFront;
}

struct node * free_list(struct node *list) {
  free(list);
  if (list->next != 0) {
    free_list(list->next);
  }
}

int main() {
  struct node *a;
  a = (struct node*)malloc(sizeof(struct node));
  a->i = 0;
  struct node *b;
  b = (struct node*)malloc(sizeof(struct node));
  b->i = 1;
  struct node *c;
  c = (struct node*)malloc(sizeof(struct node));
  c->i = 2;
  
  a->next = b;
  b->next = c;

  //print_list works
  printf("\n===print_list===\n");
  
  printf("\nPrinting from a\n");
  print_list(a);

  printf("\nPrinting from b\n");
  print_list(b);

  printf("\nPrinting from c\n");
  print_list(c);

  //insert_front works
  printf("\n===insert_front===\n");
  
  struct node *d;
  d = insert_front(a,-1);
  printf("\nPrinting from d\n");
  print_list(d);

  //free_list works
  printf("\n===free_list===\n");

  free_list(c);
  printf("\nPrinting from d, c freed\n");
  print_list(d);

  free_list(b);
  printf("\nPrinting from d, b freed\n");
  print_list(d);

  free_list(d);
  printf("\nPrinting from d, d freed\n");
  print_list(d);
}
