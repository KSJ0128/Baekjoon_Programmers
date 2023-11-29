#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int N;
	vector<int> arr;
	cin >> N;

	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	bubble_sort(arr);

	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';
}
