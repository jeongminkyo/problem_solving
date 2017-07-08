#include<iostream>
using namespace std;
int two[10000000] = { 0 };
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int num;
		cin >> num;
		int ten_num = 2;
		int su = 2;
		int count = 6;
		int count2 = 2;
		if (num == 1)
		{
			cout << "0" << endl;
			continue;
		}
		else if (num == 2)
		{
			cout << "1" << endl;
			continue;
		}
		while (1)
		{
			if (num <= count)
			{
				break;
			}
			else
			{
				ten_num *= 2;
				su++;
				count2 = count;
				count += ten_num*su;
			}
		}
		if (((num - count2) % su) == 0)
		{
			ten_num += ((num - count2) / su);
			ten_num--;
		}
		else
		{
			ten_num += ((num - count2) / su);
		}
		
		int j = su;
		while (1)
		{
			if (ten_num == 0)
			{
				break;
			}
			two[j] = ten_num % 2;
			ten_num = ten_num / 2;
			j--;
		}
		if (((num - count2) % su) == 0)
		{
			cout << two[su] << endl;
		}
		else
		{
			cout << two[(num - count2) % su] << endl;
		}
		
	}

	return 0;
}