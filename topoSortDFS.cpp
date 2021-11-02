#include <bits/stdc++.h>
using namespace std;

void topoSort(int src , vector<int> graph[] , bool visited[] , vector<int> &ans){
	visited[src] = true;

	for(int neighbour:graph[src]){
		if(!visited[neighbour])		topoSort(neighbour , graph , visited , ans);		
	}
	ans.push_back(src);
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

	vector<int> ans;
	bool visited[n] = {false};
	
	for(int i = 0 ; i < n ; i++){
		if(!visited[i])		topoSort(i , graph , visited , ans);
	}

	reverse(ans.begin() , ans.end());

	for(auto x:ans)	cout<<x<<" ";

	return 0;

}