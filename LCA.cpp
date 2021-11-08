#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 , M = 5;			//M = log(N)


//Used just to initialize the depth array and base values of parent array.
void dfs(int node , int par , int depth[] , int parent[][M] , vector<int> graph[]){		
	parent[node][0] = par;
	
	if(par == -1)	depth[node] = 0;
	else	depth[node] = depth[par] + 1;

	// parent[node][0] = par;
	for(int neighbour:graph[node]){
		if(neighbour!=par)	dfs(neighbour , node , depth , parent , graph);
	}
}


int LCA(int u , int v , int depth[] , int parent[][M]){
	
	if(u == v)	return u;
	
	if(depth[u] < depth[v])		swap(u , v);	//u is at a lower level.

	int diff = depth[u]-depth[v];
	int j = 0;
	while(diff){
		if((diff & 1) == 1)		u = parent[u][j];
		
		diff = diff >> 1;
		j++;
	}

	if(u == v)	return u;
	for(j = M-1 ; j >= 0 ; j--){
		if(parent[u][j]!=parent[v][j]){
			u = parent[u][j] , v = parent[v][j];
		}
	}
	return parent[u][0];
}


int main(){
	int n;
	cin>>n;		//nodes from 0 to n-1

	vector<int> graph[n];
	for(int i = 0 ; i < n-1 ; i++){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int depth[n] , parent[n][M];
	//parent[i][j] stores ancestor node of node i at a distance of 2**j
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < M ; j++){
			parent[i][j] = -1;
		}
	}

	dfs(0 , -1 , depth , parent , graph);	//this will initialize depth array and base values of parent array

	for(int j = 1 ; j < M ; j++){		//Build parent Array/sparse Table.
		for(int i = 1 ; i < n ; i++){
			if(parent[i][j-1]!=-1){
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}

	// for(int i = 0 ; i < n ; i++){		//Print the sparse Table
	// 	cout<<i<<"---> ";
	// 	for(int j = 0 ; j < M ; j++){
	// 		cout<<parent[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<<LCA(8 , 11 , depth , parent)<<endl;
	cout<<LCA(9 , 7 , depth , parent)<<endl;
	cout<<LCA(8 , 10 , depth , parent)<<endl;

	return 0;
}