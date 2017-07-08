#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
struct city
{
	bool check = 0;
	int ci_num;
	int muse;
	int car;
	vector<city*> vt;
};

long long le_car=0;
long long le_mu=0;
city ci;

void dfs(city ct1,city ct2)
{
	for (int i = 0; i < ct1.vt.size(); i++)
	{
		if (ct1.vt.size()==1)
		{
			ct1.check = 1;
			le_car += ct1.car;
			le_mu += ct1.muse;
		}
		else if (ct1.vt[i]->ci_num != ct2.ci_num)
		{
			if (ct1.check == 0)
			{
				ct1.check = 1;
				le_car += ct1.car;
				le_mu += ct1.muse;
			}
			if (ct1.vt[i]->check == 0)
			{
				if (ct1.vt[i]->vt.size()==1)
				{
					ct1.vt[i]->check = 1;
					le_car += ct1.vt[i]->car;
					le_mu += ct1.vt[i]->muse;
					continue;
				}
				else
				{
					dfs(*ct1.vt[i], ct1);
				}
					
			}
		}
	}
	
}

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		vector<city> vt_city;
		vector<pair<int, int>> road;
		vector<long long> over;
		int city_num, road_num;
		long long total_car=0;
		long long total_muse=0;
		long long ri_car;
		long long ri_mu;
		cin >> city_num >> road_num;
		vt_city.push_back(ci);

		for (int j = 0; j < city_num; j++)
		{
			city c;
			cin >> c.car >> c.muse;
			c.ci_num = j + 1;
			total_car += c.car;
			total_muse += c.muse;
			vt_city.push_back(c);
		}

		for (int j = 0; j < road_num; j++)
		{
			int a, b;
			cin >> a >> b;
			road.push_back(make_pair(a, b));
			vt_city[b].vt.push_back(&vt_city[a]);
			vt_city[a].vt.push_back(&vt_city[b]);
		}
		//ют╥б
		for (int j = 0; j < road.size(); j++)
		{
			city ci1;
			city ci2;
			if (vt_city[road[j].first].ci_num < vt_city[road[j].second].ci_num)
			{
				ci1 = vt_city[road[j].first];
				ci2 = vt_city[road[j].second];
			}
			else
			{
				ci1 = vt_city[road[j].second];
				ci2 = vt_city[road[j].first];
			}
			dfs(ci1,ci2);

			for (int i = 0; i < vt_city.size(); i++)
			{
				vt_city[i].check = 0;
			}

			ri_car = total_car - le_car;
			ri_mu = total_muse - le_mu;
			over.push_back(ri_car * le_mu + le_car * ri_mu);
			le_car = 0;
			le_mu = 0;
		}
		
		vector<long long>::iterator it;
		it = max_element(over.begin(), over.end());
		cout << *it << endl;

		over.clear();
		vt_city.clear();
		road.clear();
		total_car = 0;
		total_muse = 0;
		le_car = 0;
		le_mu = 0;
		ri_car = 0;
		ri_mu = 0;
	}
} 

