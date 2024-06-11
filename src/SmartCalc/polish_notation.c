#include "polish.h"

char *startRPN(const char *str, double x) {
  Stack stack;
  initStack(&stack);
  char *string = strdup(str);
  int errorNum = 0;
  char **tokens = malloc(MAX_EXPRESSION_SIZE * sizeof(char *));
  char *queue = malloc(MAX_EXPRESSION_SIZE * sizeof(char));
  int countArray = parseInfixExpression(string, tokens);
  errorNum = numValid(tokens, countArray);

  if (errorNum > 0) {
    memset(queue, 0, strlen(queue));
    strcat(queue, "Ошибка: Неправильное выражение");
  } else {
    queueParse(countArray, tokens, queue, &stack);
    int count2 = evaluateRPN(queue, tokens, &stack, x);
    if (count2 != 0) {
      memset(queue, 0, strlen(queue));
      strcat(queue, "Ошибка: Ошибка вычислений");
    }
  }
  free(string);
  free(tokens);
  freeStack(&stack);
  return queue;
}

double evaluateRPN(char *queue, char *tokens[], Stack *stack, double x) {
  char *resultString = (char *)malloc(MAX_EXPRESSION_SIZE * sizeof(char));
  double nanCheck = 0;
  int errorWrongOperator = 0;
  int count = parseInfixExpression(queue, tokens);
  for (int i = 0; i < count; i++) {
    if (isdigit(*tokens[i])) {
      double ch = atof(tokens[i]);
      stackPush(stack, ch);
    } else if (*tokens[i] == 'U') {
      stackPush(stack, stackPop(stack) * -1);
    } else if (*tokens[i] == 'i') {  // sin
      stackPush(stack, sin(stackPop(stack)));
    } else if (*tokens[i] == 'o') {  // cos
      stackPush(stack, cos(stackPop(stack)));
    } else if (*tokens[i] == 'a') {  // tan
      stackPush(stack, tan(stackPop(stack)));
    } else if (*tokens[i] == 'c') {  // acos
      nanCheck = acos(stackPop(stack));
      if (isnan(nanCheck)) {
        errorWrongOperator++;
      } else {
        stackPush(stack, nanCheck);
      }
    } else if (*tokens[i] == 's') {  // asin
      nanCheck = asin(stackPop(stack));
      if (isnan(nanCheck)) {
        errorWrongOperator++;
      } else {
        stackPush(stack, nanCheck);
      }
    } else if (*tokens[i] == 't') {  // atan
      stackPush(stack, atan(stackPop(stack)));
    } else if (*tokens[i] == 'q') {  // sqrt
      stackPush(stack, sqrt(stackPop(stack)));
    } else if (*tokens[i] == 'n') {  // ln
      stackPush(stack, log(stackPop(stack)));
    } else if (*tokens[i] == 'l') {  // log
      stackPush(stack, log10(stackPop(stack)));
    } else if (*tokens[i] == 'x') {
      stackPush(stack, x);
    } else {
      double operand2 = stackPop(stack);
      double operand1 = stackPop(stack);
      switch (*tokens[i]) {
        case '^':
          stackPush(stack, pow(operand1, operand2));
          break;
        case '%':
          stackPush(stack, fmod(operand1, operand2));
          break;
        case '+':
          stackPush(stack, operand1 + operand2);
          break;
        case '-':
          stackPush(stack, operand1 - operand2);
          break;
        case '*':
          stackPush(stack, operand1 * operand2);
          break;
        case '/':
          stackPush(stack, operand1 / operand2);
          break;
        default:
          errorWrongOperator++;
          break;
      }
    }
  }
  memset(queue, 0, strlen(queue));
  snprintf(resultString, MAX_EXPRESSION_SIZE, "%.7f", stackPop(stack));
  strcpy(queue, resultString);
  free(resultString);
  return errorWrongOperator;
}

void queueParse(int countArray, char *tokens[], char *queue, Stack *stack) {
  int checkUnar = 0;
  for (int i = 0; i < countArray; i++) {
    if (*tokens[checkUnar] == '-') {
      stackPush(stack, 'U');
      checkUnar++;
    } else if ((*tokens[i] == '(' && *tokens[i + 1] == '-')) {
      stackPush(stack, '(');
      stackPush(stack, 'U');
      i += 1;
    } else if (isdigit(*tokens[i]) || *tokens[i] == 'x') {
      strcat(queue, tokens[i]);
      strcat(queue, " ");
    } else if (isalpha(*tokens[i]) && *tokens[i] != 'x') {
      if (*tokens[i] == 'l' && tokens[i][1] != 'n') {
        stackPush(stack, *tokens[i]);
      } else {
        stackPush(stack, tokens[i][1]);
      }
    } else if (*tokens[i] == '(') {
      stackPush(stack, *tokens[i]);
    } else if (*tokens[i] == ')') {
      char ch;
      while (!stackEmpty(stack) && (ch = stackPop(stack)) != '(') {
        strncat(queue, &ch, 1);
        strcat(queue, " ");
      }
    } else {
      while (!stackEmpty(stack)) {
        char ch = stackPop(stack);

        if (getOperatorPriority(ch) > getOperatorPriority(*tokens[i]) ||
            (isLeftAssociative(ch) &&
             getOperatorPriority(ch) == getOperatorPriority(*tokens[i]))) {
          strncat(queue, &ch, 1);
          strcat(queue, " ");
        } else {
          stackPush(stack, ch);
          break;
        }
      }

      stackPush(stack, *tokens[i]);
    }
  }
  while (!stackEmpty(stack)) {
    char ch = stackPop(stack);
    strncat(queue, &ch, 1);
    strcat(queue, " ");
  }
}

int parseInfixExpression(char *str, char *tokens[]) {
  int count = 0;
  char *token = strtok(str, " ");
  while (token != NULL && count < MAX_EXPRESSION_SIZE) {
    tokens[count++] = token;
    token = strtok(NULL, " ");
  }
  for (int i = 0; i < count; ++i) {
    printf("%s\n", tokens[i]);
  }
  return count;
}

int numValid(char *tokens[], int count) {
  int error = 0;
  int checkUnar = 0;
  int openBracketsCount = 0;
  int closeBracketsCount = 0;

  for (int i = 0; i < count; i++) {
    if (i + 1 < count && strcmp(tokens[i], "%%") == 0 &&
        strcmp(tokens[i + 1], "%%") == 0) {
      error++;
    }
    if (count > 1) {
      if (*tokens[checkUnar] == '-') {
        checkUnar++;
      }

      if (*tokens[i] == '^' && i + 1 > count) {
        error++;
      }

      if (i + 1 < count && isalpha(*tokens[i]) && *tokens[i] == '(' &&
          *tokens[i + 1] != '-') {
        error++;
      }

      if (*tokens[i] == '(') {
        openBracketsCount++;
      }

      if (*tokens[i] == ')') {
        closeBracketsCount++;
      }

      if (i + 1 < count && isdigit(*tokens[i]) && isdigit(*tokens[i + 1])) {
        error++;
      }

      if (i + 1 < count && ((isalpha(*tokens[i]) && isalpha(*tokens[i + 1])) ||
                            (*tokens[i] != 'x' && isalpha(*tokens[i]) &&
                             *tokens[i + 1] != '('))) {
        error++;
      }

      if (i + 1 < count && *tokens[i] != '%' && isOperator(*tokens[i]) &&
          isOperator(*tokens[i + 1])) {
        error++;
      }
    } else {
      error++;
    }
  }

  if (closeBracketsCount != openBracketsCount) {
    error++;
  }

  return error;
}

int isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}
