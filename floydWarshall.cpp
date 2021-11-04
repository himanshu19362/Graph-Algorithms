#include <bits/stdc++.h>
using namespace std;

//Can work for both directed and undirected graphs
vector<vector<int>> floyd(vector<vector<int>> graph , int n){

	vector<vector<int>> distance(graph);

	for(int k = 0 ; k < n ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				if(distance[i][k]!=INT_MAX and distance[k][j]!=INT_MAX and distance[i][j] > distance[i][k] + distance[k][j]){
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
	return distance;
}


int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> graph(n , vector<int> (m , INT_MAX));
	
	for(int i = 0 ; i < m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		graph[x][y] = w;
	}

	auto it = floyd(graph , n);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<it[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}