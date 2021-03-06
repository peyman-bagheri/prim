// prim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
#define inf (int) 1e9 
int n;

void prim(vector<vector<int>> w)
{
	vector <bool> v(n, 0);
	int min = 1000;
	int w1;
	int w2;
	int y;
	int x;
	
	cout << " enter the desired vertex \n";
	cin >> x;
	v.at(x) = 1;
	for (int k = 0; k < (n-1); k++)
	{
		min = 1000;
		for (int i = 0; i < v.size(); i++)
		{
			if (v.at(i) == 1)
			{
				for (int j = 0; j < v.size(); j++)
				{
					if (v.at(j) == 0)
					{
						if (w[i][j] < min)
						{
							min = w[i][j];
							w1 = i;
							w2 = j;
						}
					}
				}
			}
		}
		cout << w1 << "-->" << w2 << "  " << min << "\n";
		v.at(w2) = 1;
	}
}

int main()
{
	int a;
	vector<vector<int>> w;
	cout << " enter count of your vertex \n";
	cin >> n;
	cout << " enter weight \n";
	for (int i = 0; i < n; i++)
	{
		vector<int>row;
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			row.push_back(a);
		}
		w.push_back(row);
	}

	prim(w);

	cin.get();
	cin.get();
	cin.get();
    return 0;
}

