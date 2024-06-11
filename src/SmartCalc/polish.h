/**
 * @file polish.h
 *
 * @brief Заголовочный файл с определением структуры Stack и функций
 * калькулятора на языке си.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define errorStack -1;
#define MAX_EXPRESSION_SIZE 256

/**
 * @struct Stack
 * Структура стека для операндов калькулятора.
 */
typedef struct stack {
  double* data;  ///< Массив данных стека.
  int top;       ///< Индекс вершины стека.
} Stack;

/**
 * @brief Преобразование инфиксного выражения в обратную польскую запись.
 *
 * @param str Входное инфиксное выражение.
 * @param x Значение переменной для вычисления выражения.
 * @return Строка с обратной польской записью выражения.
 */
char* startRPN(const char* str, double x);

/**
 * @brief Вычисление значения выражения из обратной польской записи.
 *
 * @param queue Строка с обратной польской записью выражения.
 * @param tokens Массив токенов из исходного выражения.
 * @param stack Структура стека для операндов.
 * @param x Значение переменной для вычисления выражения.
 * @return Вычисленное значение выражения.
 */
double evaluateRPN(char* queue, char* tokens[], Stack* stack, double x);

/**
 * @brief Проверка, является ли символ оператором.
 *
 * @param c Проверяемый символ.
 * @return 1, если символ - оператор, 0 в противном случае.
 */
int isOperator(char c);

/**
 * @brief Проверка корректности числовых токенов.
 *
 * @param tokens Массив токенов из исходного выражения.
 * @param count Количество токенов в массиве.
 * @return 1, если все числовые токены корректны, 0 в противном случае.
 */
int numValid(char* tokens[], int count);

/**
 * @brief Преобразование инфиксного выражения в обратную польскую запись.
 *
 * @param countArray Количество токенов в массиве.
 * @param tokens Массив токенов из исходного выражения.
 * @param queue Строка с обратной польской записью выражения.
 * @param stack Структура стека для операндов.
 */
void queueParse(int countArray, char* tokens[], char* queue, Stack* stack);

/**
 * @brief Получение приоритета оператора.
 *
 * @param op Символ оператора.
 * @return Приоритет оператора.
 */
int getOperatorPriority(char op);

/**
 * @brief Преобразование инфиксного выражения в массив токенов.
 *
 * @param str Инфиксное выражение.
 * @param tokens Массив для хранения токенов.
 * @return Количество токенов в массиве.
 */
int parseInfixExpression(char* str, char* tokens[]);

/**
 * @brief Инициализация структуры стека.
 *
 * @param stack Структура стека для инициализации.
 */
void initStack(Stack* stack);

/**
 * @brief Проверка, пуст ли стек.
 *
 * @param stack Структура стека.
 * @return 1, если стек пуст, 0 в противном случае.
 */
int stackEmpty(Stack* stack);

/**
 * @brief Проверка, полон ли стек.
 *
 * @param stack Структура стека.
 * @return 1, если стек полон, 0 в противном случае.
 */
int stackFull(Stack* stack);

/**
 * @brief Добавление значения в стек.
 *
 * @param stack Структура стека.
 * @param value Значение для добавления в стек.
 * @return 1, если операция успешна, 0 в противном случае.
 */
int stackPush(Stack* stack, double value);

/**
 * @brief Удаление значения из стека.
 *
 * @param stack Структура стека.
 * @return Значение, удаленное из стека.
 */
double stackPop(Stack* stack);

/**
 * @brief Освобождение памяти, занятой структурой стека.
 *
 * @param stack Структура стека для освобождения.
 */
void freeStack(Stack* stack);

/**
 * @brief Проверка, является ли оператор левоассоциативным.
 *
 * Эта функция проверяет, является ли оператор левоассоциативным.
 *
 * @param op Символ оператора.
 * @return True, если оператор левоассоциативен, false в противном случае.
 */
bool isLeftAssociative(char op);

#endif  // CALCULATOR_H
