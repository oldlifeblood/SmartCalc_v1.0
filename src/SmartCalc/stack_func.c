#include "polish.h"

int getOperatorPriority(char operator) {
  switch (operator) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
    case '%':
      return 2;
    case '^':
      return 3;
    case 'U':
    case 'q':
    case 'i':
    case 'o':
    case 'a':
    case 'l':
    case 'n':
    case 's':
    case 'c':
    case 't':
      return 4;
    default:
      return 0;
  }
}

void initStack(Stack* stack) {
  stack->data = (double*)malloc(sizeof(double) * MAX_EXPRESSION_SIZE);
  if (stack->data == NULL) {
    exit(EXIT_FAILURE);
  }
  stack->top = -1;
}

void freeStack(Stack* stack) {
  free(stack->data);
  stack->top = -1;
}

int stackEmpty(Stack* stack) { return (stack->top == -1); }

int stackFull(Stack* stack) { return (stack->top == MAX_EXPRESSION_SIZE - 1); }

int stackPush(Stack* stack, double value) {
  if (!stackFull(stack)) {
    stack->data[++stack->top] = value;
  } else {
    return errorStack;
  }
  return 0;
}

double stackPop(Stack* stack) {
  if (!stackEmpty(stack)) {
    return stack->data[stack->top--];
  } else {
    return errorStack;
  }
}

bool isLeftAssociative(char op) {
  return (op == '+' || op == '-' || op == '*' || op == '/');
}
