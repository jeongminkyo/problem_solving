#include<iostream>
#include<vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int stick, level_num;
		cin >> stick >> level_num;
		vector<int> level;
		level.push_back(-1);

		for (int i = 0; i < level_num; i++)
		{
			int num;
			cin >> num;
			level.push_back(num);
		}

		int start, end;
		cin >> start >> end;

		//ют╥б
		vector<int> upstart(level_num+1);
		for (int i = level_num; i > 0; i--)
		{
			if (level[i] == end || level[i] == end-1)
			{
				if (level[i] == end)
				{
					end++;
					upstart[i] = end;
				}
				else if (level[i] == end - 1)
				{
					end--;
					upstart[i] = end;
				}
			}
			else
			{
				upstart[i] = end;
				continue;
			}
		}

		bool check = 0;
		if (level[1] == start || level[1] == start-1)
		{
			if(level[1] == start)
				start++;
			else
			{
				start--;
			}
		}

		for (int i = 2; i <= level_num; i++)
		{
			if (start - upstart[i] == 1 || start - upstart[i] == -1)
			{
				check = 1;
				break;
			}
			else
			{
				if (level[i] == start || level[i] == start - 1)
				{
					if (level[i] == start)
					{
						start++;
					}
					else if (level[i] == start - 1)
					{
						start--;
					}
				}
				else
				{
					continue;
				}
			}
		}

		if (check == 0)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << "1" << endl;
		}

		level.clear();
		upstart.clear();
		check = 0;
	}
}