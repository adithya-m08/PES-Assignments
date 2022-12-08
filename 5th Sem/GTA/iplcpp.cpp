#include<bits/stdc++.h>
 
using namespace std;
 
int n,e,i,j;
vector<vector<pair<int,int> > > graph;
vector<int> color;
bool vis[100011];
 
void colour(int node)
{
	queue<int> q;
	int c=0;
	set<int> already_colored;
	if(vis[node])
		return;
	vis[node]=1;
 
	for(i=0;i<graph[node].size();i++)
	{
		if(color[graph[node][i].second]!=-1)
		{
			already_colored.insert(color[graph[node][i].second]);
		}
	}
 
	for(i=0;i<graph[node].size();i++)
	{
		if(!vis[graph[node][i].first])
		{
			q.push(graph[node][i].first);
		}
		if(color[graph[node][i].second]==-1)
		{
			while(already_colored.find(c)!=already_colored.end())
			c++;
			//cout<<graph[node][i].second+1<<" "<<c<<"\n";
			color[graph[node][i].second]=c;
			already_colored.insert(c);
			c++;
		}
	}
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		colour(temp);
	}
	return;
}
 
int main()
{
	int x,y;
	set<int> empty;
	cout<<"Enter number of vertices and edges respectively:";
	cin>>n>>e;
	cout<<"\n";
	graph.resize(n); //  Number of Vertices.
	color.resize(e,-1); // Number of Edges.
	memset(vis,0,sizeof(vis));
	for(i=0;i<e;i++)
	{
		cout<<"\nEnter edge vertices of edge "<<i+1<<" :";
		cin>>x>>y;
		x--; y--;
		graph[x].push_back(make_pair(y,i));
		graph[y].push_back(make_pair(x,i));
	}
	colour(0);
	for(i=0;i<e;i++)
	{
		cout<<"Edge "<<i+1<<" is coloured "<<color[i]+1<<"\n";
	}
}