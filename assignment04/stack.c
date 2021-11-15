#include "stack.h"
#define STACK_SIZE 3

// Stack store
char StackStore[STACK_SIZE];

int* stackPtr; // points to the top of the stack

// Initialize internals of the stack
void stack_init(void)
{
    *stackPtr = -1;
    for(int i = 0; i < STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

int stack_push(char data)
{
    // test to see if stack is full
    if(*stackPtr == STACK_SIZE)
    {
        return -1;
    }
    else
    {
        *stackPtr = *stackPtr + 1;
        StackStore[*stackPtr] = data;
        return 0; // push successful
    }
}

int stack_pop()
{
    if(*stackPtr < 0)
    {
        return -1; // error, stack is empty already
    }
    else
    {
        char ch = StackStore[*stackPtr];
        StackStore[*stackPtr] = 0; // set to zero
        *stackPtr = *stackPtr - 1;        
        return ch;
    }
}

int isEmpty()
{
    if(*stackPtr == -1)
    {
        return 1; // Stack is empty
    }
    else
    {
        return 0; // Stack is not empty
    }
}

int isFull()
{
    if(*stackPtr == STACK_SIZE - 1)
    {
        return 1; // Stack is full
    }
    else
    {
        return 0; // Stack is not full
    }
}