extern "C"{
    // Add the header files required to run your main 
    #include <stdio.h>
    #include "search.h"

}
int sum(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n > 1)
    {
        return a[n-1] + sum(a, n - 1);
    }
    return a[0];

}
bool search(int a[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    else if (n > 0 && a[n - 1] != x)
    {
        return search(a, n - 1, x);
    }
    else

    return true;
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    int arr[4] = {10,12,20,5};
    
    printf("%d \n",sum(arr,4));
    printf("%d",search(arr, 4, 10));
    return 0;
}