#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int num;
		cin >> num;
		int max_num = 0;
		int *pt = &max_num;
		int count = 0;
		int arr[1000] = { 0 };
		for (int j = 1; j <= num; j++)
		{
			cin >> arr[j];
			if (max_num < arr[j])
			{
				max_num = arr[j];
			}
		}
		int start = 1;
		while (1)
		{
			if (start == num)
				break;
			pt = max_element(arr+start,arr+num+1);
			for (int j = start; j <= num; j++)
			{
				if (*pt == arr[j])
				{
					if (j == start)
						break;
					else
					{
						if (j == num)
						{
							reverse(arr + start, arr + num + 1);		//max가 오른쪽끝일때
							count++;
							break;
						}
						else 
						{
							reverse(arr+j, arr+num+1);//자리 스왑
							count++;
						}

						reverse(arr + start, arr + num+1);
						count++;
						break;
					
					}
				}	
			}	//max가 오른쪽 끝으로 감 count ++
			start++;
		}
		
		cout << count << endl;

	}
}