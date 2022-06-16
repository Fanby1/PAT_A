
#include<stdio.h>
#include<string>
#include<stdio.h>
#include<string>
#include<queue>
#include<stack>
#include<iostream>
#include<vector>
#include <iomanip>
#include<set>
using namespace std;
#define MAXSIZE 10000

int N;          // (N≤10 4)
vector<int>GraphT[MAXSIZE];  //定义一个不限列的有maxn行的二维数组
bool vis[MAXSIZE] = { false };
int maxdepth = 0;
set<int> deepestroots;  //set自动排序，没有重复


void DFS(int u, int depth) {
	if (maxdepth<depth)
	{
		maxdepth = depth;
		deepestroots.clear();
		deepestroots.insert(u + 1);
	}
	else if(maxdepth==depth)
	{
		deepestroots.insert(u + 1);
	}
	
	vis[u] = true;
	for (int j = 0; j < GraphT[u].size(); j++)
	{
		int t = GraphT[u][j];
		if (!vis[t]) {
			DFS(t, depth + 1);
		}
	}
}

void DFSTrave(vector<int>* GraphT)
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			DFS(i, 1);
			count++;
		}
	}
	if (count == 1) {
		set<int>::iterator it = deepestroots.begin();
		//set只能通过迭代器来访问
		int s = *(it)-1;
		maxdepth = 0;
		fill(vis, vis + MAXSIZE, false);
		set<int>deepestroots_temp = deepestroots;
		deepestroots.clear();
		DFS(s, 1);
		it = deepestroots_temp.begin();
		for (it; it != deepestroots_temp.end(); it++)
		{
			deepestroots.insert(*it);
		}
		it = deepestroots.begin();
		for (it; it != deepestroots.end(); it++) {
			cout << *(it) <<endl;
		}

	}
	else {
		cout << "Error: " << count << " components" << endl;
	}
}



int main() {
	
	cin >> N;
	//特殊讨论，如果只有一个节点，那最深就这个节点。
	if (N==1)    
	{
		cout << "1" << endl;
		return 0;
	}
	//在指针数组中存储。
	for (int i = 0; i < (N-1); i++)
	{
		int a, b;
		cin >> a >> b;
		GraphT[a - 1].push_back(b - 1);
		GraphT[b - 1].push_back(a - 1);
	}
	//两次dfs
	//先判断有几个连通分量，即需要几次深度搜索
	//如果次数多，则输出error：k 
	DFSTrave(GraphT);

	return 0;
}


