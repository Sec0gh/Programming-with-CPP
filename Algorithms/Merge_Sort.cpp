#include<iostream>
using namespace std;
void merging(int array[],int start, int middle, int end)
{
	int size1 = middle - start + 1;
	int size2 = end - middle;
	int *left = new int[size1];
	int *right = new int[size2];
	for (int i = 0;i<size1;i++)
		left[i] = array[start + i];

	for (int j = 0; j < size2; j++)
		right[j] = array[middle + j + 1];

	int x = 0, y = 0, z = start;
	/*to sort in descending order the condition will modify into:
	if (left[x] >= right[y]) ... " >="*/
	while (x < size1 && y < size2)
	{
		if (left[x] >= right[y])
		{
			array[z] = left[x];
			x++;
		}
		else
		{
			array[z] = right[y];
			y++;
		}
		z++;
	}
	while (x < size1)
	{
		array[z] = left[x];
		x++;
		z++;
	}
	while (y < size2)
	{
		array[z] = right[y];
		y++;
		z++;
	}
}
void merge_sort(int array[], int start, int end)
{
	int middle;
	if (start < end)
	{
		middle = (start + end) / 2;
		merge_sort(array, start, middle);
		merge_sort(array, middle + 1, end);
		merging(array, start, middle, end);
	}
}
int main()
{
	int array[] = { 99, 6 ,76 ,15 ,58 ,35 ,86 };
	int size = sizeof(array) / sizeof(array[0]);

	merge_sort(array,0,size-1);

	//print array after sorting.
	for (int x = 0; x < size; x++)
		cout << array[x] << " ";
	cout << endl;

	system("pause");
	return 0;
}