#include<iostream>
#include<vector>
int dp[101][10001] = { -1 };
using namespace std;
vector<pair<int, int>> coin;

int solve(int a, int b, int count)
{
	if (b == 0) 
		return 1;
	if (a >= count)
		return 0;
	int &ret = dp[a][b];
	if (ret != -1) 
		return ret;
	ret = 0;

	for (int i = 0; i <= coin[a].second; i++)
	{
		if (b - coin[a].first * i >= 0)
		{
			ret += solve(a + 1, b - coin[a].first * i,count);
		}
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	
	for (int i = 0; i < testcase; i++)
	{
		for (int m = 0; m < 101; m++)
		{
			for (int n = 0; n < 10001; n++)
			{
				dp[m][n] = -1;
			}
		}
		int card_num, ob_num;
		cin >> card_num >> ob_num;
		int count = 0;

		int num = 1;
		while (num <= ob_num)
		{
			num = num << 1;
			count++;
		}
		num = 1;
		for (int j = 0; j < count; j++)
		{
			coin.push_back(make_pair(num,card_num));
			num = num << 1;
		}
		int result = solve(0, ob_num, count);
		printf("%d\n",result);
		coin.clear();
	}
}