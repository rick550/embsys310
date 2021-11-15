1. Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-
band region to enable the clock for Port A, then answer the following: 
a. What instructions does the compiler produce in assembly for “writing” to the 
RCC_AHB2ENR bit when using bit-band address? 

0x800'0042: 0x2001         MOVS       R0, #1
0x800'0044: 0x4912         LDR.N      R1, [PC, #0x48]
0x800'0046: 0x6008         STR        R0, [R1]


b. What were the instructions produced when writing to the RCC_AHB2ENR without using 
bit-banding? 

0x800'0042: 0x4814         LDR.N    R0, [PC, #0x50]
0x800'0044: 0x6801         LDR      R1, [R0]
0x800'0046: 0xf051 0x0101  ORRS.W   R1, R1, #1
0x800'004A: 0x6001         STR      R1, [R0]


2. Create a function “func1” with 5 arguments and call “func1” from within another function 
“func2”. Trace thru the assembler and note: 
a. How does the calling function “func2” pass the values to the called function “func1”? 
It first pushes on to the stack R7 and LR. Next, two values, 2 and 1 are moved to R1 and R0.
So it doesn't really 'pass' it to func1, but it just stores it in the registers where func1 can access it
later on.

b. What extra code did the compiler generate before calling the function “func1” with the 
multiple arguments? 
On my machine, it had to create an STR instruction to store R2 into the SP (stack pointer).


c. What extra code did the compiler generate inside the called function “funct1” with the 
list of multiple arguments? 

Extra code generated appears to be a PUSH instruction for R4 and a LDR of R4 to get the value from the SP
with an offset of 0x4

d. Any other observations? 
1) When functions are called, any arguments that are passed are stored in the registers staring from right to left
2) In answering 2c, we are taking a value from the stack pointer with offset 0x4. Which on my machine was the
   second item in the stack. Since this is supposedly a 'stack' structure, I am suprised that you are able to   
   take some data that is NOT at the top of the stack. This leads me to suggest that the C stack in implemented
   as an array because you can access data directly.