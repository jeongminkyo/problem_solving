#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
struct road;

int total_time=0;
struct city
{
	bool visit=0;
	int ci_num;
	vector<road *> rd;
};

struct road
{
	int ro_num;
	int check=0;
	city * left;
	city * right;
	int time;
};

struct comp
{
	bool operator()(struct road a, struct road b)
	{
		return a.time > b.time;
	}
};

priority_queue<struct road, vector<struct road>, comp> pq;

void prim(city *ci)
{
	 
	ci->visit = 1;
	
	for (int i = 0; i < ci->rd.size(); i++)
	{
		if (ci->rd[i]->check == 0)
		{
			pq.push(*ci->rd[i]);
			ci->rd[i]->check = 1;
		}
	}
	while (!pq.empty())
	{
		if (pq.top().left->visit == 0)
		{
			pq.top().left->visit = 1;
			total_time += pq.top().time;
			city *cy = pq.top().left;
			pq.pop();
			prim(cy);
		}
		else if (pq.top().right->visit == 0)
		{
			pq.top().right->visit = 1;
			total_time += pq.top().time;
			city *cy = pq.top().right;
			pq.pop();
			prim(cy);
		}
		else
		{
			pq.pop();
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{	
		int local, bus;
		cin >> local >> bus;
		vector<city> ci(local);
		vector<road> ro(bus);
		for (int i = 0; i < local; i++)
		{
			ci[i].ci_num = i;
		}
		for (int i = 0; i < bus; i++)
		{
			int num1, num2, num3;
			cin >> num1 >> num2 >> num3;
			ro[i].left = &ci[num1];
			ro[i].right = &ci[num2];
			ro[i].time = num3;
			ci[num1].rd.push_back(&ro[i]);
			ci[num2].rd.push_back(&ro[i]);
		}
		//ют╥б
		
		prim(&ci[0]);

		cout << total_time << endl;
		ci.clear();
		ro.clear();
		total_time = 0;
	
	}
}