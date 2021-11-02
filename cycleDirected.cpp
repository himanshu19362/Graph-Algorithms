#include <bits/stdc++.h>
using namespace std;

bool dfs(int src, vector<int> graph[] , vector<int> &visited){
	visited[src] = 1;
	for(int neighbour:graph[src]){
		if(visited[neighbour] == -1){
			if(dfs(neighbour , graph , visited)){
				visited[src] = 0;
				return true;
			}
		}
		else if(visited[neighbour] == 1){
			visited[src] = 0;
			return true;
		}
	}
	visited[src] = 0;
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<int> graph[n];
	for(int i = 0 ; i < m ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);		
	}

	vector<int> visited(n , -1);	//-1:not visited  0:visited but not in stack  1:visited and currently in stack

	cout<<dfs(0 , graph , visited)<<endl;

	return 0;
}