#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<pair<int,int>>> vt;
int cnt=1;
int DFS(int x, int y,int size)
{
	vt[x][y].second = 1;
	int a=0, b=0, c=0, d=0;
	if (x + 1 < size)
	{
		if (vt[x + 1][y].first == 0)
		{
			if (vt[x + 1][y].second == 0)
			{
				a = DFS(x + 1, y, size);
		
			}
		}
	}
	
	if (x - 1 >= 0)
	{
		if (vt[x - 1][y].first == 0)
		{
			if (vt[x - 1][y].second == 0)
			{
				b = DFS(x - 1, y, size);
			
			}
		}
	}
	
	if (y + 1 < size)
	{
		if (vt[x][y + 1].first == 0)
		{
			if (vt[x][y + 1].second == 0)
			{
				c = DFS(x, y + 1, size);
				
			}
		}
	}
	
	if (y - 1 >= 0)
	{
		if (vt[x][y - 1].first == 0)
		{
			if (vt[x][y - 1].second == 0)
			{
				d = DFS(x, y - 1, size);
				
			}
		}
	}

	if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		vt[x][y].second = 0;
		return 1;
	}
	else
	{
		vt[x][y].second = 0;
		cnt += max(max(max(a, b), c), d);
		int aa = cnt;
		cnt = 1;
		return aa;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;

	while (T--)
	{
		int size, num;
		cin >> size >> num;
		vt.resize(size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int k;
				cin >> k;
				vt[i].push_back(make_pair(k,0));
			}
		}
		for (int i = 0; i < num; i++)
		{
			int x, y;
			cin >> x >> y;
			cout << DFS(x, y, size) << endl;
		}
		vt.clear();
		
	}
}