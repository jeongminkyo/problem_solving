#include<iostream>
#include<vector>
#include<queue>
#include <fstream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	int degree[1010] = { 0 };
	bool check[1010] = { 0 };
	vector<int> order;
	queue<int> Q;
	vector<int>result;
	int sum = 0;

	for (int i = 0; i < testcase; i++)
	{
		int singer, PD, num, turn;

		cin >> singer >> PD;

		for (int j = 0; j < PD; j++)
		{
			cin >> num;
			for (int k = 0; k < num; k++)
			{
				cin >> turn;
				order.push_back(turn);
				if (k == 0)
				{
					continue;
				}
				else
				{
					degree[turn]++;
				}
				if (k == num - 1)
				{
					order.push_back(0);
				}
			}
		}

		while (1)
		{
			for (int j = 1; j <= singer; j++)
			{
				if (degree[j] == 0 && check[j] == 0)
				{
					Q.push(j);
					break;
				}
				sum += degree[j];
				if (sum == 0 && j == singer)
				{
					goto jump;
				}
			}

			sum = 0;
			if (Q.empty() == 1)
			{
				result.push_back(-1);
				goto jump;
			}

			for (int k = 0; k < order.size() - 1; k++)
			{
				if (order[k] == Q.front())
				{
					degree[order[k + 1]]--;
				}
			}
			int head = Q.front();
			result.push_back(head);
			check[head] = 1;
			Q.pop();

		}
	jump:

		for (int j = 0; j < singer; j++)
		{
			if (result[j] == -1)
			{
				cout << "0" << endl;
				break;
			}
			else if (j == singer - 1)
			{
				for (int k = 0; k < singer; k++)
				{
					if (k != singer - 1)
					{
						cout << result[k] << " ";
					}
					else
					{
						cout << result[k] << endl;
					}
				}
			}
		}

		order.clear();
		result.clear();
		for (int j = 1; j <= singer; j++)
		{
			check[j] = 0;
		}
		for (int j = 0; j < 1010; j++)
		{
			degree[j] = 0;
		}
	}
}