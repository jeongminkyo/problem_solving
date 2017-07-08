#include<iostream>
#include<vector>
#include<queue>
int count_num = 0;
using namespace std;

struct node
{
	bool visit = 0;
	int x;
	int y;
	vector<node*> pt;
};

queue<node> q;

void windP(node *no, int wind)
{
	if (wind == 360)
	{
		no->visit = 1;
		for (int i = 0; i < no->pt.size(); i++)
		{
			if (no->pt[i]->y <= no->y)
			{
				if (no->pt[i]->visit != 1)
				{
					count_num++;
					q.push(*no->pt[i]);
					no->pt[i]->visit = 1;
				}
			}
		}
		if (q.empty())
			return;
		if (&q.front() == no)
		{
			q.pop();
			if (!q.empty())
				windP(&q.front(),wind);
			else
			{
				return;
			}
		}
		else
			windP(&q.front(),wind);
	}
	else if (wind == 90)
	{
		no->visit = 1;
		for (int i = 0; i < no->pt.size(); i++)
		{
			if (no->pt[i]->x <= no->x)
			{
				if (no->pt[i]->visit != 1)
				{
					count_num++;
					q.push(*no->pt[i]);
					no->pt[i]->visit = 1;
				}
			}
		}
		if (q.empty())
			return;
		if (&q.front() == no)
		{
			q.pop();
			if (!q.empty())
				windP(&q.front(),wind);
			else
			{
				return;
			}
		}
		else
			windP(&q.front(),wind);
	}
	else if (wind == 180)
	{
		no->visit = 1;
		for (int i = 0; i < no->pt.size(); i++)
		{
			if (no->pt[i]->y >= no->y)
			{
				if (no->pt[i]->visit != 1)
				{
					count_num++;
					q.push(*no->pt[i]);
					no->pt[i]->visit = 1;
				}
			}
		}
		if (q.empty())
			return;
		if (&q.front() == no)
		{
			q.pop();
			if (!q.empty())
				windP(&q.front(),wind);
			else
			{
				return;
			}
		}
		else
			windP(&q.front(),wind);
	}
	else if (wind == 270)
	{
		no->visit = 1;
		for (int i = 0; i < no->pt.size(); i++)
		{
			if (no->pt[i]->x >= no->x)
			{
				if (no->pt[i]->visit != 1)
				{
					count_num++;
					q.push(*no->pt[i]);
					no->pt[i]->visit = 1;
				}
			}
		}
		if (q.empty())
			return;
		if (&q.front() == no)
		{
			q.pop();
			if (!q.empty())
				windP(&q.front(),wind);
			else
			{
				return;
			}
		}
		else
			windP(&q.front(),wind);
	}
}

void windNE(node *no)
{
	no->visit = 1;
	for (int i = 0; i < no->pt.size(); i++)
	{
		if ((no->pt[i]->x < no->x && no->pt[i]->y <= no->y) || (no->pt[i]->x == no->x && no->pt[i]->y < no->y))
		{
			if (no->pt[i]->visit != 1)
			{
				count_num++;
				q.push(*no->pt[i]);
				no->pt[i]->visit = 1;
			}
		}
	}
	if (q.empty())
		return;
	if (&q.front() == no)
	{
		q.pop();
		if (!q.empty())
			windNE(&q.front());
		else
		{
			return;
		}
	}
	else
		windNE(&q.front());
}

void windNW(node *no)
{
	no->visit = 1;
	for (int i = 0; i < no->pt.size(); i++)
	{
		if ((no->pt[i]->x > no->x && no->pt[i]->y <= no->y) || (no->pt[i]->x == no->x && no->pt[i]->y < no->y))
		{
			if (no->pt[i]->visit != 1)
			{
				count_num++;
				q.push(*no->pt[i]);
				no->pt[i]->visit = 1;
			}
		}
	}
	if (q.empty())
		return;
	if (&q.front() == no)
	{
		q.pop();
		if (!q.empty())
			windNW(&q.front());
		else
		{
			return;
		}
	}
	else
		windNW(&q.front());
}

void windSE(node *no)
{
	no->visit = 1;
	for (int i = 0; i < no->pt.size(); i++)
	{
		if ((no->pt[i]->x < no->x && no->pt[i]->y >= no->y) || (no->pt[i]->x == no->x && no->pt[i]->y > no->y))
		{
			if (no->pt[i]->visit != 1)
			{
				count_num++;
				q.push(*no->pt[i]);
				no->pt[i]->visit = 1;
			}
		}
	}
	if (q.empty())
		return;
	if (&q.front() == no)
	{
		q.pop();
		if (!q.empty())
			windSE(&q.front());
		else
		{
			return;
		}
	}
	else
		windSE(&q.front());
}

void windSW(node *no)
{
	no->visit = 1;
	for (int i = 0; i < no->pt.size(); i++)
	{
		if ((no->pt[i]->x > no->x && no->pt[i]->y >= no->y) || (no->pt[i]->x == no->x && no->pt[i]->y > no->y))
		{
			if (no->pt[i]->visit != 1)
			{
				count_num++;
				q.push(*no->pt[i]);
				no->pt[i]->visit = 1;
			}
		}
	}
	if (q.empty())
		return;
	if (&q.front() == no)
	{
		q.pop();
		if (!q.empty())
			windSW(&q.front());
		else
		{
			return;
		}
	}
	else
		windSW(&q.front());
}
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
		
	while (testcase--)
	{
		int wind;
		cin >> wind;
		int num;
		cin >> num;
		vector<node> vt(num);
		int x, y;
		cin >> x >> y;
		vt[0].x = x;
		vt[0].y = y;
		for (int i = 1; i < num; i++)
		{
			cin >> x >> y;
			vt[i].x = x;
			vt[i].y = y;
			for (int j = 0; j < i; j++)
			{
				if (j != i)
				{
					vt[i].pt.push_back(&vt[j]);
					vt[j].pt.push_back(&vt[i]);
				}
			}
		}
		//ют╥б
		switch (wind)
		{
			case 45:
			{
				for (int i = 0; i < num; i++)
				{
					windNE(&vt[i]);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
			case 135:
			{
				for (int i = 0; i < num; i++)
				{
					windSE(&vt[i]);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
			case 225:
			{
				for (int i = 0; i < num; i++)
				{
					windSW(&vt[i]);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
			case 315:
			{
				for (int i = 0; i < num; i++)
				{
					windNW(&vt[i]);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
			case 360:
			{
				for (int i = 0; i < num; i++)
				{
					windP(&vt[i],wind);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}
				
				break;
			}
			case 90:
			{
				for (int i = 0; i < num; i++)
				{
					windP(&vt[i], wind);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
			case 180:
			{
				for (int i = 0; i < num; i++)
				{
					windP(&vt[i], wind);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
			case 270:	
			{
				for (int i = 0; i < num; i++)
				{
					windP(&vt[i], wind);
					for (int j = 0; j < num; j++)
					{
						vt[j].visit = 0;
					}
				}

				break;
			}
		}

		cout << count_num << endl;
		count_num = 0;
		vt.clear();
	}
}