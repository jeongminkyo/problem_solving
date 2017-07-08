#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
using namespace std;

int main()
{
	vector <pair<int,int> > vt;
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int time, program;
		cin >> time >> program;
		int s_time, e_time;
		for (int j = 0; j < program; j++)
		{
			cin >> s_time >> e_time;
			vt.push_back(make_pair(e_time, s_time));
		}//ют╥б
		
		sort(vt.begin(), vt.end());
		int j = 0;
		bool flag = 0;
		while (1)
		{
			if (j+1 == vt.size())
			{
				break;
			}
			if (vt[j].first > vt[j + 1].second)
			{
				vt.erase(vt.begin() + j + 1);
				flag = 1;
			}
			if (flag == 0)
			{
				j++;
			}
			flag = 0;
		}
		cout << vt.size() << endl;
		vt.clear();
		
	}
}