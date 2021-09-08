//Heap Sort
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int min = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] < arr[min])
        min = left;

    if (right < n && arr[right] < arr[min])
        min = right;
    
    if (min != i)
    {
        swap(arr[i], arr[min]);
        heapify(arr, n, min);
    }
}
void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int array[] = { 10,70,90,8,56,11 };
    int n = sizeof(array) / sizeof(array[0]);

    heap_sort(array, n);

    print(array, n);
}