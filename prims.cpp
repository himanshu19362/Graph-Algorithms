#include <bits/stdc++.h>
using namespace std;

int prims(vector<vector<int>> graph[] , int src , int n){
	set<vector<int>> s;		//it will store {edge Weight , node} which is the edge weight from parent node to 'node' 

	bool mstVisited[n] = {false};
	s.insert({0 , src});

	int ans = 0;
	while(!s.empty()){
		auto it = *s.begin();
		s.erase(it);

		int w = it[0] , node = it[1];
		
		if(mstVisited[node])	continue;

		ans += w;
		mstVisited[node] = true;

		for(auto neighbour:graph[node]){
			if(!mstVisited[neighbour[0]]){		//Makes sure that we don't end up forming cycles.
				s.insert({neighbour[1] , neighbour[0]});
			}
		}
	}

	return ans;
}

int main(){

	int n,m;
	cin>>n>>m;

	vector<vector<int>> graph[n];
	for(int i = 0 ; i < m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x].push_back({y ,w});
		graph[y].push_back({x , w});
	}

	cout<<prims(graph , 0 , n)<<endl;

	return 0;
}