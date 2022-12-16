#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

typedef int element;


/* Stack data structure which store elements */
struct stack {
  element *data;
  int top;
  int size;
};

/* Initialize the @_stack */
void initialize(struct stack **_stack);

/* Finalize the @_stack */
void finalize(struct stack **_stack);

/* Check if the @_stack is empty */
bool is_empty(struct stack *_stack);

/* Check if the @_stack is full */
bool is_full(struct stack *_stack);

/* Push the @_item into the @_stack */
void push(struct stack *_stack, element _item);

/* Pop the top of the element of the @_stack */
element pop(struct stack *_stack);

/* Print all elements of the @_stack */
void dump_stack(struct stack *_stack);

#endif