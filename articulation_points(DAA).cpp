#include<iostream>
#include<vector>
#include<fstream>
#include<stack>
using namespace std;

int M, N;
vector<vector<int> > graph;
int dfsAP()
{
	int v, tv, sv = 0, num = 1, ap = 0, rAPC = 0;
	bool allVis;
	stack<int> s;
	vector<int> DFN(N), level(N), parent(N);
	vector<bool> visited(N), isAp(N);
	visited[sv] = true;
	s.push(sv);
	DFN[sv] = num++;
	parent[sv] = -1;
	level[sv] = DFN[sv];
	while(!s.empty())
	{
		int v = s.top();
		allVis = true;
		for(size_t i = 0;i<graph[v].size();++i)
		{
			tv = graph[v][i];
			if(!visited[tv])
			{
				if(v==sv)
					++rAPC;
				visited[tv] = true;
				s.push(tv);
				DFN[tv] = num++;
				parent[tv] = v;
				level[tv] = DFN[tv];
				allVis = false;
				break;
			}
		}
		if(allVis)
		{
			s.pop();
			for(size_t i = 0;i<graph[v].size();++i)
			{
				tv = graph[v][i];
				if(tv!=parent[v] && DFN[tv]<DFN[v])
					level[v] = (level[v]<DFN[tv])?level[v]:DFN[tv];
				else
				{
					if(v==parent[tv])
					{
						level[v] = (level[v]<level[tv])?level[v]:level[tv];
						if(level[tv]>=DFN[v] && v != sv &&!isAp[v])
						{
							++ap;
							isAp[v] = true;
							//cout<<v<<" ";
						}

					}
				}
			}
		}
	}
	if(rAPC>=2)
	{
		//cout<<sv<<endl;
		++ap;
	}
	return ap;
}

int main()
{
	//ifstream file("Test.in");
	//file>>N>>M;
	cin>>N>>M;
	graph.resize(N);
	while(M--)
	{
		int v1, v2;
		//file>>v1>>v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	cout<<dfsAP()<<endl;
	return 0;
}