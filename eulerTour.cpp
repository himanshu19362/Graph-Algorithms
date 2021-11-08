#include <bits/stdc++.h>
using namespace std;



void dfs(int tin[] , int tout[] , int &time , int node , int parent , vector<int> graph[]){
	tin[node] = ++time;
	for(int neighbour:graph[node]){
		if(neighbour!=parent)	dfs(tin , tout , time , neighbour , node , graph);
	}
	tout[node] = time;
}


int main(){
	int n;
	cin>>n;

	vector<int> graph[n];

	for(int i = 0 ; i < n-1 ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}


	//Euler Tour

	int tin[n] , tout[n] , time = -1;

	dfs(tin , tout , time , 0 , -1 , graph);

	for(int i = 0 ; i < n ; i++)	cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;

	int flat[n];
	for(int i = 0 ; i < n ; i++)	flat[tin[i]] = i;

	//Find elements in the subtree of node 1
	//To to that find all elements in flat from index tin[node] to tout[node]

	int l = tin[1] , r = tout[1];
	for(int i = l ; i <= r ; i++)	cout<<flat[i]<<" ";
	cout<<endl;
	
	return 0;
}