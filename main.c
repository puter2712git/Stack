#include "stack.h"

int main() {
  struct stack *stack;

  initialize(&stack);

  push(stack, 5);
  push(stack, 15);
  push(stack, 25);

  dump_stack(stack);

  pop(stack);

  dump_stack(stack);

  finalize(&stack);

  return 0;
}