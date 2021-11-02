#include <bits/stdc++.h>
using namespace std;

//Also known as kahn's Algorithm
void topoSort(vector<int> graph[] , int n , int indegree[]){
	queue<int> q;
	for(int i = 0 ; i < n ; i++){
		if(indegree[i] == 0)	q.push(i);
	}

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		cout<<curr<<" ";

		for(int neighbour:graph[curr]){
			indegree[neighbour]--;
			if(indegree[neighbour] == 0)	q.push(neighbour);
		}

	}
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<int> graph[n];
	int indegree[n] = {0};
	for(int i = 0 ; i < m ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		indegree[y]++;		
	}

	topoSort(graph , n , indegree);
	return 0;
}