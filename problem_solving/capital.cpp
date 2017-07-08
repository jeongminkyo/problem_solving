#include<iostream>
#include<algorithm>
using namespace std;
int ingu[510] = { 0 };
int mrx[510][510] = { 0 };
int sec_mrx[510][510] = { 0 };
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int city, road;
		int num1, num2;
		int sum = 0;
		int si = 0;
		int ri = 0;
		int xi[510];
		int *minvalue;
		cin >> city >> road;

		for (int j = 1; j <= city; j++)
		{
			xi[j] = 0;
		}

		si = 0;
		ri = 0;

		for (int j = 1; j <= city; j++)
		{
			cin >> ingu[j];
		}

		for (int j = 1; j <= road; j++)
		{
			cin >> num1 >> num2;
			mrx[num1][num2] = 1;
			mrx[num2][num1] = 1;
		}
		bool flag = 1;
		int counter = 2;
		while (1)
		{
			flag = 1;
			for (int j = 1; j <= city; j++)
			{
				for (int k = 1; k <= city; k++)
				{
					for (int m = 1; m <= city; m++)
					{
						sum += mrx[j][m] * mrx[m][k];
					}
					sec_mrx[j][k] = sum;
					sum = 0;
				}
			}

			for (int j = 1; j <= city; j++)
			{
				for (int k = 1; k <= city; k++)
				{
					if (mrx[j][k] == 0 && j != k && sec_mrx[j][k] != 0)
					{
						mrx[j][k] = counter;
					}
				}
			}

			for (int j = 1; j <= city; j++)
			{
				for (int k = 1; k <= city; k++)
				{
					if (j != k && mrx[j][k] == 0 && flag==1)
					{
						flag = 0;
						counter++;
					}

					if (k == city && j == city && flag == 1)
					{
						goto jump;
					}
				}
			}
		}
		jump:
		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
			{
				si += mrx[j][k];
				if (ri < mrx[j][k])
					ri = mrx[j][k];
			}

			xi[j] = (city - 1)*ri + si;
			si = 0;
			ri = 0;
		}
		int count = 0;
		int sudo = 0;
		minvalue = min_element(xi + 1, xi + city+1);

		for (int j = 1; j <= city; j++)
		{

			if (*minvalue == xi[j])
			{
				count++;
				if (count > 1)
				{
					if (ingu[sudo] < ingu[j])
					{
						sudo = j;
					}
				}
				else
				{
					sudo = j;
				}

			}
		}

		cout << sudo << endl;

		for (int j = 1; j <= city; j++)
		{
			for (int k = 1; k <= city; k++)
			{
				mrx[j][k] = 0;
			}
		}


	}
}