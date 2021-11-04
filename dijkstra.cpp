#include <bits/stdc++.h>
using namespace std;

//Only works for  graphs with positive edge weights.
//This is a single source shortest path algorithm
void dijkstra(int src , vector<int> &distance , vector<vector<int>> graph[]){

	set<vector<int>> s;		//It will store {weight , node} . Shortest distance from source to 'node'
	s.insert({0 , src});
	distance[src] = 0;
	while(!s.empty()){
		auto it = *s.begin();
		s.erase(s.begin());

		int dis = it[0] , node = it[1];

		for(auto it:graph[node]){
			int nNode = it[0] , w = it[1];
			if(dis + w < distance[nNode]){
				auto del = s.find({distance[nNode] , nNode});
				if(del!=s.end())	s.erase(del);
				distance[nNode] = dis + w;
				s.insert({distance[nNode] , nNode});
			} 
		}
	}	
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> graph[n];
	for(int i = 0 ; i < m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y , w});
		graph[y].push_back({x , w});
	}

	vector<int> distance(n , INT_MAX);

	dijkstra(0 , distance , graph);

	for(int i = 0 ; i < n ; i++){
		cout<<"Distance from source node to "<<i<<" is "<<distance[i]<<endl;
	}

	return 0;
}