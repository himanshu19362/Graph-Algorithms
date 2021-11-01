#include <bits/stdc++.h>
using namespace std;

void bfs(int src , vector<int> graph[] , bool visited[]){
	queue<int> q;
	q.push(src);
	visited[src] = true;

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		cout<<curr<<" ";
		
		for(int neighbour:graph[curr]){
			if(!visited[neighbour]){
				visited[neighbour] = true;
				q.push(neighbour);
			}
		}

	}
}

int main(){
	int n,m;	//Nodes from 0 to n-1.
	cin>>n>>m;
	vector<int> graph[n];

	for(int i = 0 ; i < m ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bool visited[n] = {false};

	bfs(0 , graph , visited);

	return 0;
}