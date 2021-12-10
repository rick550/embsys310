void swap_pointer(int** x, int** y)
{
    int* temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    int x = 2000000;
    int y = 1000000;
    
    int* xPtr = &x;
    int* yPtr = &y;
    
    swap_pointer(&xPtr, &yPtr);
    
    //int* a = xPtr;
    //int* b = yPtr;

    
    return 0;
}
