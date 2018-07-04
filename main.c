#include "list.h"

#include <stdio.h>
#include <assert.h>

int main(void) {
  // creates an initialized list
  List l = list_create();

  // adds three numbers to the list
  list_add(&l, 4);
  list_add(&l, 5);
  list_add(&l, 7);
  list_insert(&l, 6, 2);

  // prints the size of the size
  printf("list of size %d\n", list_size(&l));

  // prints the elements stored in the list
  for (int i = 0; i < list_size(&l); i++) {
    printf("%d: %d\n", i, list_get(&l, i));
  }

  // destroys the list
  list_destroy(&l);

  return 0;
}
