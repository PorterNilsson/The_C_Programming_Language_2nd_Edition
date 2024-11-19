/* Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at 
the  price  of  more  tests  outside.)  Write  a  version  with  only  one  test  inside  the  loop  and  
measure the difference in run-time. */

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1]    

int binsearch(int x, int v[], int n) {

    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x  > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
} */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    printf("%d\n", binsearch(5, arr, 9));
    printf("%d\n", binsearch(8, arr, 9));
    
    return 0;
}

int binsearch(int x, int v[], int n) {

    int low, high, mid;
    
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        // printf("Low: %d\n", low);
        // printf("High: %d\n", high);
        // printf("Mid: %d\n", mid);
        if (x <= v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[low] == x)
        return low;
    else
        return -1;
}
