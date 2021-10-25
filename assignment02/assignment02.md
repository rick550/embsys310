

1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step 
thru the program  only once to increment “counter”. 
a) What is the value of the “counter” from the “Locals” window? 

The value before the increment is 2147483647. After incrementing just once,
the value is now -2147483648.

b) What is the value of the “counter” in the “Registers” window?
The value in the registers window is 0x80000000

c) Please note down which flags are set in the APSR register. And explain why. 
Flags set are:
N and V.

N Flag is because there is a negative value. This overflow value is basically a junk value.

V Flag because there was an overflow condition. The value that was input exceeded the allowable size.


2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program 
once to increment “counter” 
a) What happens to the value of “counter” in the “Locals” window? 
Before the counter increment the local value is -1, after incrementing we have the value of 0
in the locals window.

b) Please note down which are set in the APSR register. And explain why.
Flags set are:
Z and C.

Z flag is set because the increment results in a 0. Also the register is also 0 (0x00000000)

C flag is set because of the nature of adding the complement, which can sometimes lead to a 
carry condition.

3. Change the “counter” variable type in your code to “unsigned int”. Inject the values 
“0x7FFFFFFF” then step thru the program to increment the “counter” once: 
a) What is the value of “counter” in the “Locals” window after incrementing for each value? 
The value in the locals window is 2147483647

b) Please note down which flags are set in the APSR register. And explain why. 
Only the C flag is set. This flag is set because the operation resulted in a carry.

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” 
then step thru the program to increment the “counter” once: 
a) What is the value of “counter” in the “Locals” window after incrementing for each value? 
The value before the increment is 4294967295. The value after the increment is 0.

b) Please note down which are set in the APSR register. And explain why. 
The Z - zero condition flag is set. Also the C carry flag is set. The C flag is set because
of the carry operation.

5. Move the “counter’ variable outside of main (at the top of the file): 
a) What is the scope of the variable “counter”?
This is now a global variable visible everywhere in the file it will be used.

b) Is it still visible in the “Locals” view?
It is no longer visible in the locals view. 

c) In which window view can we track “counter” now? 
In my IDE, it is now only visible in the "Watch 1" view window.
 
d) What is the address of the “counter” variable in memory? 
Address is: 0x0000000


6. Change the source code to the following, then run the program in the simulator: 
 
int counter = 0x0; 
int main() { 
int *p_int = (int *)0x20000000; 
++(*p_int); 
++(*p_int); 
++(*p_int); 
counter ++; 
return 0; 
} 
 
a) What is the value of “counter” at the end of the program (halting at the return 0 statement) 
The value of counter has changed from 0 to 4.

b) Explain why the counter value has changed?
The counter value has changed because the line:

int *p_int = (int *)0x20000000;

0x20000000 hex value is casted into int value and assigned to int pointer*p_int.
*p_int now points to address 0x20000000. Looking at the Watch 1 and Locals windows,
I see that counter has location 0x20000000 and p_int has location 0x20000000.
So they are both pointing to the same area in memory but with different names.

As p_int is being incremented, so is counter.

7. Change the setting of IAR to run the same program on the evaluation board: 

Setup: 
1. Connect evaluation board to your computer through ST 
Link cable. 
2. Set the IAR to using STLink: 
3. Project -> Options -> Debugger -> Device: ST-Link 
4. Download setting is flash loader 
5. Make sure ST-Link Interface is set to SWD 
6. Run the same code described in the simulator. 


a) What is the address where “counter” is stored?  
Counter is stored at address location 0x20000000 in the R1 register.

b) Is the “counter” variable stored in RAM or ROM? 
It is stored in RAM.

c) What is the value of “counter” at the end of the program (halting at the return 0 
statement). 
The value of counter is 4.
