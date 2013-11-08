#include <stdio.h>
/** 
 * sort function
 */
void shellsort(int v[], int n);
void insertsort(int v[], int n);
void selectsort(int v[], int n);
void bubblesort(int v[], int n);
void swap(int v[], int i, int j);
int main() {
    int arr[] = { 15, 25, 52, 49, 79, 20 };
    for (int i = 0; i < 6; i++) {
        printf("%d   ", arr[i]);
    }
    printf("\n");
    //shellsort(arr, 6);
    insertsort(arr, 6);
    //selectsort(arr, 6);
    //bubblesort(arr, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d   ", arr[i]);
    }
    printf("\n");
}

void shellsort(int v[], int n) {
    int gap, i, j;
    for ( gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j]>v[j+gap]; j-=gap)
                swap(v, j, j+gap);
}

void insertsort(int v[], int n) {
    int i, j;
    int element;
    for (i = 1; i < n; i++) {
        element = v[i];
        for (j = i-1; j >= 0 && v[j] > element; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = element;
    }
}

void selectsort(int v[], int n) {
    int i, j;
    int min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++){
            if (v[min] > v[j])
                min = j;
        }
        if ( min != i)
            swap(v, min, i);
    }
}

void bubblesort(int v[], int n) {
    int i,j,t;
    for ( i = 0; i < n-1; i++ )
        for ( j = 0; j < n-1-i;j++)
            if (v[j+1] < v[j])
                swap(v,j+1, j);
}
void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
