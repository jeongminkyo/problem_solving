#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int arr[1010][1010] = { 0 };
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		vector<pair<int, int>> finger;
		vector<pair<int, int>> com_finger;
		int num;
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] += 1;
			finger.push_back(make_pair(x, y));
		}

		cin >> num;

		for (int j = 0; j < num; j++)
		{
			int x, y;
			cin >> x >> y;
			com_finger.push_back(make_pair(x, y));
		}

		sort(finger.begin(), finger.end());
		sort(com_finger.begin(), com_finger.end());
		int count = 0;
		bool flag = 0;
		for (int m = 0; m < finger.size(); m++)
		{
			if (flag == 1)
				break;

			for (int j = 0; j < com_finger.size(); j++)
			{
				int dif1 = finger[m].first - com_finger[j].first;
				int dif2 = finger[m].second - com_finger[j].second;

				for (int k = 0; k < com_finger.size(); k++)
				{
					if (com_finger[k].first + dif1 > 1000 || com_finger[k].second + dif2 > 1000)
					{
						continue;
					}
					if (com_finger[k].first + dif1 < 0 || com_finger[k].second + dif2 < 0)
					{
						continue;
					}
					if (arr[com_finger[k].first + dif1][com_finger[k].second + dif2] == 1)
					{
						count++;
					}

				}
				double compare = ((double)count / (double)finger.size());
				if (100 * compare >= 90)
				{
					flag = 1;
					break;
				}
				
				count = 0;
				compare = 0;
			}
			
		}
		
		if (flag == 1)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}

		for (int j = 0; j < 1010; j++)
		{
			for (int k = 0; k < 1010; k++)
			{
				arr[j][k] = 0;
			}
		}
		finger.clear();
		com_finger.clear();
		flag = 0;

	}
}