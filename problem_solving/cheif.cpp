#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	string s;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int card_num, man;
		cin >> card_num >> man;
		cin.ignore();
		vector <list <int>> vt(man);

		for (int j = 0; j < man; j++)
		{
			cin.clear();
			getline(cin, s);
			string buf;
			stringstream ss(s);
			while (ss >> buf)
			{
				int k = atoi(buf.c_str());
				if (vt[j].empty() != 1 && vt[j].back() == k)
				{
					vt[j].pop_back();
				}
				else
					vt[j].push_back(k);
			}
			cin.clear();
		}//ют╥б

		int j = 0;
		int m = (j + 1) % man;

		while (1)
		{
			if (j == man)
			{
				j = j%man;

			}
			if (m == man)
			{
				m = m % man;
			}
			list<int>::iterator check;
			list<int>::iterator ptnum;
			int count = 0;
			if (vt[j].empty())
			{
				j++;
				m = (j + 1) % man;
				continue;
			}
			while (vt[m].empty())
			{
				if (count == man-1)
				{
					break;
				}
				m = (m + 1) % man;
				count++;
			}
			if (count == man-1)
				break;
			count = 0;
			ptnum = vt[m].begin();
			if (j >= vt[m].size())
			{
				ptnum = --vt[m].end();
			}
			else
			{
				advance(ptnum, j);
			}
			check = find(vt[j].begin(), vt[j].end(), *ptnum);
			if (check != vt[j].end())
			{
				vt[j].erase(check);
				vt[m].erase(ptnum);
			}
			else
			{
				list<int>::iterator iter = vt[j].begin();
				for (int k = 0; k <= vt[j].size(); k++)
				{
					if (iter == vt[j].end())
					{
						vt[j].insert(iter, *ptnum);
						break;
					}
					if (*ptnum < *iter)
					{
						vt[j].insert(iter,*ptnum);
						break;
					}
					else
					{
						iter++;
					}
				}
				vt[m].erase(ptnum);
			}
			j++;
			m= (j+1)%man;
		}

		cout << j+1 << endl;

		for (int j = 0; j < man; j++)
		{
			vt[j].clear();
		}
	}
}