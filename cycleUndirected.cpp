#include <bits/stdc++.h>
using namespace std;

bool dfs(int src , vector<int> graph[] , int parent , bool visited[]){	//returns true if cycle found .
	visited[src] = true;
	
	for(int neighbour:graph[src]){
		if(!visited[neighbour]){
			if(dfs(neighbour , graph , src , visited))	return true;
		}
		else if(neighbour!=parent)	return true;
	}
	
	return false;
}


int main(){
	int n,m;
	cin>>n>>m;

	vector<int> graph[n];

	for(int i=0 ; i<m ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);		
	}
	bool visited[n] = {false};
	cout<<dfs(0 , graph , -1 , visited)<<endl;
	return 0;

}