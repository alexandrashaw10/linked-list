#include "list.h"

/*------------------ Begin: Fileprivate Helper Functions ---------------------*/

/*
 * Returns an initialized node
 *
 * @returns Node initialized with a `data` set to `num` and `next` set to NULL
 */
static Node node_create(int num) {
    Node newnode;
    newnode.data = num;
    newnode.next = NULL;
    return newnode;
}

/*
 * Returns the last node in a chain of linked nodes
 *
 * Precondition:
 * - assume that self will never be null
 *
 * @param Node* const self: the head of the list
 * @returns Node* the last node in the list
 */
static Node* node_get_last(Node* self) {
    Node* current = self;
    while(current -> next != NULL){
        current = current -> next;
    }
    return current;
}

/*
 * Gets an Node* from a specified index in linked list
 *
 * Precondition:
 * - assume that self will never be null
 * - assume that the index will never be out of bounds
 *
 * @param Node* const self: the linked list to access
 * @param int index: the index to access
 * @returns Node* the node at the specified index
 */
static Node* node_get(Node* const self, int i) {
    Node* current = self;
    while(i > 0 && current -> next != NULL){
        current = current -> next;
        i--;
    }
    return current;
}

/*
 * Destroy all nodes that follow and free self
 *
 * Precondition:
 * - assume that self will never be null
 *
 * @param Node* const self: the Node to destroy
 */
static void node_destroy(Node* self) {
    if(self -> next != NULL){
        node_destroy(self -> next);
    }
    free(self);
}

/*------------------- End: Fileprivate Helper Functions ----------------------*/


/*------------------- Begin: Public Interface Functions ----------------------*/

/*
 * Returns an initialized list
 *
 * @returns List initialized with a `size` of 0 and a null `first` node;
 */
List list_create() {
    // TODO:
    List* head = (List*) malloc(sizeof(List));
    head -> size = 0;
    head -> next = NULL;
    return *head;
}

/*
 * Adds an int to the end of a list and updates its size
 *
 * Precondition:
 * - assume that self will never be null
 *
 * @param List* const self: the List to modify
 * @param int data: the data to add the list
 */
void list_add(List* const self, int data) {
    // TODO: malloc size of node, increment size,
    //new pointer to null, if just head, add, else, get last node
    self -> size++;
    if(self -> next == NULL){
        self -> next = (Node*) (malloc(sizeof(Node)));
        *(self -> next) = node_create(data);
    }
    else {
        Node* last = node_get_last(self -> next); // starting at first node
        last -> next = (Node*) (malloc(sizeof(Node)));
        *(last -> next) = node_create(data);
    }
}

/*
 * Adds an int at the given of a list and updates its size
 *
 * Precondition:
 * - assume that self will never be null
 *
 * @param List* const self: the List to modify
 * @param int data: the data to add the list
 * @param int index: the index at which the node is added
 */
void list_insert(List* const self, int data, int index){
    if(self -> size > index){
        self -> size++;
        Node* temp;
        if(index == 0) { // insert a node attached to the head
            temp = self -> next;
            self -> next = (Node*) (malloc(sizeof(Node)));
            *(self -> next) = node_create(data);
            self -> next -> next = temp;
        }
        else if(index == self -> size - 1) { // index is at last node
            list_add(self, data);
        }
        else { // insert node at index
            Node* priornode = node_get(self -> next, index - 1);
            temp = priornode -> next;
            priornode -> next = (Node*) (malloc(sizeof(Node)));
            *(priornode -> next) = node_create(data);
            priornode -> next -> next = temp;
        }
    }
}

/*
 * Gets an int from the given index of a list
 *
 * Precondition:
 * - assume that self will never be null
 * - assume that the index will never be out of bounds
 *
 * @param List* const self: the List to access
 * @param int index: the index to access
 * @returns int the data at the given index of the list
 */
int list_get(const List* const self, int index) {
  // TODO:
  Node* current;
  //cant pass self
  current = node_get(self -> next, index);
  return current -> data;
}

/*
 * Returns the size of the list
 *
 * Precondition:
 * - assume that self will never be null
 *
 * @param const List* const self: the List to query
 * @returns int the size of the list
 */
int list_size(const List * const self) {
  // TODO:
  int size = self -> size;
  return size;
}

/*
 * Removes all data from a list and sets its size to 0
 *
 * Precondition:
 * - assume that self will never be null
 *
 * @param List* const self: the List to modify
 */
void list_destroy(List* const self) {
    // TODO:

    if(self -> next != NULL){
        node_destroy(self -> next);
    }
    self -> next = NULL;
    self -> size = 0;
}

/*--------------------- End: Public Interface Functions ----------------------*/
