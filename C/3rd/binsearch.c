#include <stdio.h>

int binsearch(int x, int arr[], int n);

int main() {
}
int binsearch(int x, int arr[], int n) {
    int low, high, mid;
    low = 0;
    high = n-1;
    
    while ( low <= high ) {
        mid = (high+low) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else
            return mid;
    }
    return -1;
}
