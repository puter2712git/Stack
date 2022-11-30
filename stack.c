#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void initialize(struct stack **_stack) {
  *_stack = (struct stack*)malloc(sizeof(struct stack));
  (*_stack)->data = NULL;
  (*_stack)->top = -1;
  (*_stack)->size = 0;

  return;
}

void finalize(struct stack **_stack) {
  free(*_stack);

  return;
}

bool is_empty(struct stack *_stack) {
  return _stack->size == 0;
}

bool is_full(struct stack *_stack) {
  return _stack->top + 1 == _stack->size;
}

void push(struct stack *_stack, element _item) {
  if (is_full(_stack)) {
    _stack->size++;
    _stack->data = (element*)realloc(_stack->data, _stack->size * sizeof(element));
  }

  _stack->data[++(_stack->top)] = _item;
  return;
}

element pop(struct stack *_stack) {
  assert(!is_empty(_stack));

  int popped = _stack->data[_stack->top--];
  _stack->size--;
  _stack->data = (element*)realloc(_stack->data, sizeof(element) * _stack->size);

  return popped;
}

void dump_stack(struct stack *_stack) {
  assert(!is_empty(_stack));

  printf("==============================\n");
  printf("Print the elements of the stack.\n");
  for (int i = 0; i < _stack->size; i++) {
    printf("[%2d] : %d\n", i, _stack->data[i]);
  }
  printf("==============================\n");

  return;
}