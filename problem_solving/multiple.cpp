#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;
vector<pair<int, int>> vt(6250000);

int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int col, row;
		cin >> col >> row;

		vector<int> player1;
		vector<int> player2;

		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < row; k++)
			{
				int num;
				cin >> num;
				pair<int, int> pa = make_pair(k,j);
				vt[num] = pa;
			}
		}

		int game;
		cin >> game;

		for (int j = 0; j < game; j++)
		{
			int card_num;
			int p1_HP, p2_HP, p1_s_row, p1_s_col, p2_s_row, p2_s_col;
			int m_row, m_col;
			cin >> card_num;

			for (int k = 0; k < card_num; k++)
			{
				int deck;
				cin >> deck;
				player1.push_back(deck);
			}

			for (int k = 0; k < card_num; k++)
			{
				int deck;
				cin >> deck;
				player2.push_back(deck);
			}

			cin >> p1_HP;
			p2_HP = p1_HP;
			cin >> p1_s_row >> p1_s_col;
			p2_s_row = p1_s_row;
			p2_s_col = p1_s_col;

			while (1)
			{
				if (vt[player1[0] * player1[1]].second - p2_s_row < 0)
				{
					m_row = -(vt[player1[0] * player1[1]].second - p2_s_row);
				}
				else
				{
					m_row = vt[player1[0] * player1[1]].second - p2_s_row;
				}

				if (vt[player1[0] * player1[1]].first - p2_s_col < 0)
				{
					m_col = -(vt[player1[0] * player1[1]].first - p2_s_col);
				}
				else
				{
					m_col = vt[player1[0] * player1[1]].first - p2_s_col;
				}

				p2_HP -= (m_row + m_col);
				p2_s_col = vt[player1[0] * player1[1]].first;
				p2_s_row = vt[player1[0] * player1[1]].second;

				if (p1_HP <= 0 || p2_HP <= 0)
				{
					break;
				}

				for (int x = 0; x < 2; x++)
				{
					player1.push_back(*player1.begin());
					player1.erase(player1.begin());
				}

				if (vt[player2[0] * player2[1]].second - p1_s_row < 0)
				{
					m_row = -(vt[player2[0] * player2[1]].second - p1_s_row);
				}
				else
				{
					m_row = vt[player2[0] * player2[1]].second - p1_s_row;
				}

				if (vt[player2[0] * player2[1]].first - p1_s_col < 0)
				{
					m_col = -(vt[player2[0] * player2[1]].first - p1_s_col);
				}
				else
				{
					m_col = vt[player2[0] * player2[1]].first - p1_s_col;
				}

				p1_HP -= (m_row + m_col);
				p1_s_col = vt[player2[0] * player2[1]].first;
				p1_s_row = vt[player2[0] * player2[1]].second;

				for (int x = 0; x < 2; x++)
				{
					player2.push_back(*player2.begin());
					player2.erase(player2.begin());
				}

				if (p1_HP <= 0 || p2_HP <= 0)
				{
					break;
				}

			}

			if (p1_HP <= 0)
				cout << "B" << endl;
			else
				cout << "A" << endl;

			player1.clear();
			player2.clear();
		}


	}
}