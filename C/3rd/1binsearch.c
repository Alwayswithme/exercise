/**
 * 在上面有关折半查找的例子中, whilie循环语句内共执行了两次测试,
 * 其实只要一次就足够(代价时将更多的测试在循环外执行).重写该函数,
 * 使得循环内部只执行两次测试.比较两种版本的运行时间
 */
#include <stdio.h>

int binsearch(int x, int arr[], int n);

int main() {
}
int binsearch(int x, int arr[], int n) {
    int low, high, mid;
    low = 0;
    high = n-1;
    mid = (high + low) / 2;
    while ( low <= high && arr[mid] != x ) {
        if (arr[mid] < x) {
            low = mid + 1;
        } else (arr[mid] > x) {
            high = mid - 1;
        }
        mid = (high+low) / 2;
    }
    if (x == arr[mid])
        return mid;
    else
        return -1;
}
