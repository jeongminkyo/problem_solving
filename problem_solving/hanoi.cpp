#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include <fstream>
using namespace std;
vector<int>stick1;
vector<int>stick2;
vector<int>stick3;
vector<int> vt;
vector<int>arr;
int count1 = 0;

void hanoi(int n, int a, int b, int c, int lookat) //n¿∫ index, a from b to?
{
	if (n <= 1)
	{
		switch (a)
		{
		case 1:
		{
			if (c == 2)
			{
				if (count1 == lookat)
				{
					break;
				}
				for (int i = 0; i <= arr.size(); i++)
				{
					if (stick1.back() == i)
					{
						if (arr[i] > 1)
						{
							for (int j = 0; j <arr[i]; j++)
							{
								int pt = stick1.back();
								stick2.push_back(pt);
								stick1.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
						}
						else
						{
							int pt = stick1.back();
							stick2.push_back(pt);
							stick1.pop_back();
							count1++;
							if (count1 == lookat)
								break;
						}
						break;
					}
				}
				break;
			}
			else if (c == 3)
			{
				if (count1 == lookat)
				{
					break;
				}
				for (int i = 0; i <= arr.size(); i++)
				{
					if (stick1.back() == i)
					{
						if (arr[i] > 1)
						{
							for (int j = 0; j < arr[i]; j++)
							{
								int pt = stick1.back();
								stick3.push_back(pt);
								stick1.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
						}
						else
						{
							int pt = stick1.back();
							stick3.push_back(pt);
							stick1.pop_back();
							count1++;
							if (count1 == lookat)
								break;
						}
						break;
					}
				}
				break;
			}
		}
		case 2:
		{
			if (c == 1)
			{
				if (count1 == lookat)
				{
					break;
				}
				for (int i = 0; i <= arr.size(); i++)
				{
					if (stick2.back() == i)
					{
						if (arr[i] > 1)
						{
							for (int j = 0; j < arr[i]; j++)
							{
								int pt = stick2.back();
								stick1.push_back(pt);
								stick2.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
						}
						else
						{
							int pt = stick2.back();
							stick1.push_back(pt);
							stick2.pop_back();
							count1++;
							if (count1 == lookat)
								break;
						}
						break;
					}
				}
				break;
			}
			else if (c == 3)
			{
				if (count1 == lookat)
				{
					break;
				}
				for (int i = 0; i <= arr.size(); i++)
				{
					if (stick2.back() == i)
					{
						if (arr[i] > 1)
						{
							for (int j = 0; j <arr[i]; j++)
							{
								int pt = stick2.back();
								stick3.push_back(pt);
								stick2.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
						}
						else
						{
							int pt = stick2.back();
							stick3.push_back(pt);
							stick2.pop_back();
							count1++;
							if (count1 == lookat)
								break;
						}
						break;
					}
				}
				break;
			}

		}
		case 3:
		{
			if (c == 1)
			{
				if (count1 == lookat)
				{
					break;
				}
				for (int i = 0; i <= arr.size(); i++)
				{
					if (stick3.back() == i)
					{
						if (arr[i] > 1)
						{
							for (int j = 0; j <arr[i]; j++)
							{
								int pt = stick3.back();
								stick1.push_back(pt);
								stick3.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
						}
						else
						{
							int pt = stick3.back();
							stick1.push_back(pt);
							stick3.pop_back();
							count1++;
							if (count1 == lookat)
								break;
						}
						break;
					}
				}
				break;
			}
			else if (c == 2)
			{
				if (count1 == lookat)
				{
					break;
				}
				for (int i = 0; i <= arr.size(); i++)
				{
					if (stick3.back() == i)
					{
						if (arr[i] > 1)
						{
							for (int j = 0; j <arr[i]; j++)
							{
								int pt = stick3.back();
								stick2.push_back(pt);
								stick3.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
						}
						else
						{
							int pt = stick3.back();
							stick2.push_back(pt);
							stick3.pop_back();
							count1++;
							if (count1 == lookat)
								break;
						}
						break;
					}
				}
				break;
			}
		}
		}
	}

	else
	{
		
		hanoi(n - 1, a, c,b, lookat);
		switch (a)
		{
			case 1:
			{
				if (c == 2)
				{
					if (count1 == lookat)
					{
						break;
					}
					for (int i = 0; i <= arr.size(); i++)
					{
						if (stick1.back() == i)
						{
							if (arr[i] > 1)
							{
								for (int j = 0; j < arr[i]; j++)
								{
									int pt = stick1.back();
									stick2.push_back(pt);
									stick1.pop_back();
									count1++;
									if (count1 == lookat)
										break;
								}
							}
							else
							{
								int pt = stick1.back();
								stick2.push_back(pt);
								stick1.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
							break;
						}
					}
					break;
				}
				else if (c == 3)
				{
					if (count1 == lookat)
					{
						break;
					}
					for (int i = 0; i <= arr.size(); i++)
					{
						if (stick1.back() == i)
						{
							if (arr[i] > 1)
							{
								for (int j = 0; j < arr[i]; j++)
								{
									int pt = stick1.back();
									stick3.push_back(pt);
									stick1.pop_back();
									count1++;
									if (count1 == lookat)
										break;
								}
							}
							else
							{
								int pt = stick1.back();
								stick3.push_back(pt);
								stick1.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
							break;
						}
					}
					break;
				}
			}
			case 2:
			{
				if (c == 1)
				{
					if (count1 == lookat)
					{
						break;
					}
					for (int i = 0; i <= arr.size(); i++)
					{
						if (stick2.back() == i)
						{
							if (arr[i] > 1)
							{
								for (int j = 0; j <arr[i]; j++)
								{
									int pt = stick2.back();
									stick1.push_back(pt);
									stick2.pop_back();
									count1++;
									if (count1 == lookat)
										break;
								}
							}
							else
							{
								int pt = stick2.back();
								stick1.push_back(pt);
								stick2.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
							break;
						}
					}
					break;
				}
				else if (c == 3)
				{
					if (count1 == lookat)
					{
						break;
					}
					for (int i = 0; i <= arr.size(); i++)
					{
						if (stick2.back() == i)
						{
							if (arr[i] > 1)
							{
								for (int j = 0; j <arr[i]; j++)
								{
									int pt = stick2.back();
									stick3.push_back(pt);
									stick2.pop_back();
									count1++;
									if (count1 == lookat)
										break;
								}
							}
							else
							{
								int pt = stick2.back();
								stick3.push_back(pt);
								stick2.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
							break;
						}
					}
					break;
				}

			}
			case 3:
			{
				if (c == 1)
				{
					if (count1 == lookat)
					{
						break;
					}
					for (int i = 0; i <= arr.size(); i++)
					{
						if (stick3.back() == i)
						{
							if (arr[i] > 1)
							{
								for (int j = 0; j <arr[i]; j++)
								{
									int pt = stick3.back();
									stick1.push_back(pt);
									stick3.pop_back();
									count1++;
									if (count1 == lookat)
										break;
								}
							}
							else
							{
								int pt = stick3.back();
								stick1.push_back(pt);
								stick3.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
							break;
						}
					}
					break;
				}
				else if (c == 2)
				{
					if (count1 == lookat)
					{
						break;
					}
					for (int i = 0; i <= arr.size(); i++)
					{
						if (stick3.back() == i)
						{
							if (arr[i] > 1)
							{
								for (int j = 0; j <arr[i]; j++)
								{
									int pt = stick3.back();
									stick2.push_back(pt);
									stick3.pop_back();
									count1++;
									if (count1 == lookat)
										break;
								}
							}
							else
							{
								int pt = stick3.back();
								stick2.push_back(pt);
								stick3.pop_back();
								count1++;
								if (count1 == lookat)
									break;
							}
							break;
						}
	
					}
					break;
				}
				
			}
		}
		hanoi(n - 1, b, a,c, lookat);
	}


}


int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int num;
		int lookat;
		cin >> num;
		int ct = 1;
		arr.push_back(0);
		for (int j = 1; j <= num; j++)
		{
			int num2;
			cin >> num2;
			arr.push_back(num2);
			for (int k = 1; k <= num2; k++)
			{
				vt.push_back(ct);
				
			}
			ct++;
		}
		int M = vt.size();
		for (int j = 1; j <= M; j++)
		{
			stick1.push_back(vt.back());
			vt.pop_back();
		}
		
		cin >> lookat;

		hanoi(num, 1, 2,3,lookat);
		int rot = stick2.size();
		if (stick2.empty() == 1)
		{
			cout << "0" << endl;
		}
		for (int i = 0; i < rot; i++)
		{
			if (i != rot - 1)
			{
				cout << stick2.back() << " ";
				stick2.pop_back();
			}
			else
			{
				cout << stick2.back() << endl;
			}
		}

		stick1.clear();
		stick2.clear();
		stick3.clear();	
		arr.clear();
		ct = 1;
		count1 = 0;
	}
}

