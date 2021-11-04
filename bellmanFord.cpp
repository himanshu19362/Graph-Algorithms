#include <bits/stdc++.h>
using namespace std;

//Works for directed Graphs. 
//For undirected graph , input edges as {x, y, w} and {y, x, w} seperatly
void bellmanFord(int src , vector<int> &distance , vector<vector<int>> edgeList , int m){
	distance[src] = 0;

	for(int i = 0 ; i < m-1 ; i++){
		for(auto edge:edgeList){
			int u = edge[0] , v = edge[1] , w = edge[2];

			if(distance[u]!=INT_MAX and distance[u] + w < distance[v]){
				distance[v] = distance[u] + w;
			}
		}
	}

	for(auto edge:edgeList){
		int u = edge[0] , v = edge[1] , w = edge[2];

		if(distance[u]!=INT_MAX and distance[u] + w < distance[v]){
			cout<<"Negative Cycle Found"<<endl;
			// return;
			exit(0);
		}
	}
}


int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> edgeList;		
	for(int i = 0 ; i < m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		edgeList.push_back({x , y , w});
	}

	vector<int> distance(n , INT_MAX);
	bellmanFord(0 , distance , edgeList , m);

	for(int i = 0 ; i < n ; i++){
		cout<<"Distance from source node to "<<i<<" is "<<distance[i]<<endl;
	}

	return 0;
}