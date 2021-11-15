/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

void stack_init(void);
int stack_push(char data);
int stack_pop();
int isEmpty();
int isFull();

#endif
