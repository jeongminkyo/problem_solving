#include<iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int num;
		int arr[1000] = { 0 };
		int temp;
		int count = 0;
		cin >> num;
		for (int j = 1; j <= num; j++)
		{
			cin >> arr[j];
		}
		int j = num;
		while(1)
		{
			if (j == 1)
				break;
			if (arr[j] > arr[j - 1])
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				count++;
				j = num;
			}
			else
			{
				j--;
				continue;
			}
		}

		cout << count << endl;
	}
}