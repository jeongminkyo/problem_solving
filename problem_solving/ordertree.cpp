#include<iostream>
#include<vector>
using namespace std;
vector<int> dep;
long long int factorial(int num)
{
	long long int sum = 1;
	while (1)
	{
		if (num <= 1)
		{
			break;
		}
		else
		{
			sum *= num;
			num--;
		}
	}
	return sum;	
}

long long int H(int a, int b)
{
	return factorial(a + b - 1) / (factorial(b)*factorial(a - 1));
}

int rec(int depth, int parentnum, int reminder)
{
	if (reminder == 0) return 1;
	int result;
	if (depth < dep.size())
	{
		result = rec(depth + 1, dep[depth], reminder - dep[depth]) * H(parentnum,dep[depth]);
	}
	else
	{
		result = 0;
		for (int i = 1; i <= reminder; ++i)
		{
			result += (rec(depth + 1, i, reminder - i) * H(parentnum, i));
		}

	}
	return result;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	
	while (T--)
	{
		int node_num,depth;
		cin >> node_num;
		cin >> depth;
		for (int i = 0; i <= depth; i++)
		{
			int num;
			cin >> num;
			dep.push_back(num);
		}
		//ют╥б
		cout << rec(1, dep[0], node_num-1) << endl;
		dep.clear();
	}
}