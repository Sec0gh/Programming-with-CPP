#include<iostream>
using namespace std;
//This function sort the elements of array in ascending order.
void insertion_sort(int array[],int size)
{
	int i, j, key;
	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;
		/*To sort the elements in descending order we will modify 
		the condition of while..loop to (j >= 0 && array[j] "<" key)
		the modifing in " > " operator will be " < " */
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}
int main()
{
	int array[] = {9,2,7,5,1,4,3,6};
	int size = sizeof(array) / sizeof(array[3]);

	insertion_sort(array,size);

	cout << "The array after sorting is : " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}