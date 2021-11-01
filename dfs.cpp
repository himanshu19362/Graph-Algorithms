#include <bits/stdc++.h>
using namespace std;

void dfs(int src , vector<int> graph[] , bool visited[]){
	visited[src] = true;
	cout << src<<" ";

	for(int neighbour:graph[src]){
		if(!visited[neighbour])		dfs(neighbour , graph , visited);
	}
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<int> graph[n];
	for(int i = 0 ; i < m ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bool visited[n] = {false};
	dfs(0 , graph , visited);

}