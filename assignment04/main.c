#include<assert.h>
#include"stack.h"

int main()
{
    char  testChar;
    char  result1;
    int   result2;

    
    // *******************************************************************
    // Test1: Push and pop an item starting from an empty stack
    // *******************************************************************
    // Arrange:    
    stack_init();
    testChar = 'X';
    
    // Act:
    result2 = stack_push(testChar);
    result1 = stack_pop();
    
    // Assert:
    assert(0 == result2);
    assert(testChar == result1);
    
    // *******************************************************************
    // Test2: Check for an empty stack
    // *******************************************************************
    // Arrange:    
    stack_init();
    
    // Act:
    result2 = isEmpty();
    
    // Assert:
    assert(1 == result2);
    
    
    // *******************************************************************
    // Test3: Check for a full stack
    // *******************************************************************
    // Arrange:        
    stack_init();

    
    // Act:
    result2 = stack_push('A');
    result2 = stack_push('B');
    result2 = stack_push('C');
    result2 = stack_push('D');
    
    // Assert:
    assert(0 == result2);
    
    
    // *******************************************************************
    // Test4: Check each item after a pop
    // *******************************************************************
    // Arrange:      
    stack_init();  
    
    // Act:
    stack_push('D');
    stack_push('E');
    stack_push('F');
    
    // Assert:
    assert('F' == stack_pop());
    assert('E' == stack_pop());
    assert('D' == stack_pop());
    
    
    // *******************************************************************
    // Test5: Attempt to pop from a stack that is empty
    // *******************************************************************
    // Arrange:      
    stack_init();
    
    // Act:
    stack_push('W');
    stack_pop();
    result2 = stack_pop();
    
    
    // Assert:
    //assert('W' == stack_pop());
    assert(-1 == result2);
    
    return 0;
}
