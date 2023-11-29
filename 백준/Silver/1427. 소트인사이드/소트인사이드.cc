#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num;
	vector<int> arr;
	cin >> num;

	while (num >= 10)
	{
		arr.insert(arr.begin(), num % 10);
		num /= 10;
	}
	arr.insert(arr.begin(), num);

	for (int i = 0; i < arr.size() - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[max] < arr[j])
				max = j;
		}

		if (max != i)
		{
			int tmp = arr[max];
			arr[max] = arr[i];
			arr[i] = tmp;
		}
	}

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
}