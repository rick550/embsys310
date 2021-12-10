2. Generate the map file for your program and provide details on: 
a. How much total ROM your program is occupying? 


b. How much total RAM your program is using? 
Total RAM used is 4 bytes

c. What part of your program is using the most ROM? 
On my machine, it appears to be the startup_stm32l475xx.o

d. What part of your program is using the most RAM? 
That would be the Linker with 8'264 bytes.
On Linker->Options->Stack/Heap Sizes: The CSTACK is set to 0x2048