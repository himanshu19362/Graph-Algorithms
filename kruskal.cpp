#include <bits/stdc++.h>
using namespace std;

class DSU{

	vector<int> parent;
	vector<int> rank;
	int n;

public:
	DSU(int n){
		for(int i = 0 ; i < n ; i++)	parent.push_back(-1);
		for(int i = 0 ; i < n ; i++)	rank.push_back(1);

		this->n = n;
	}

	int find(int x){		//find using path compression
		if(parent[x] == -1)		return x;
		return parent[x] = find(parent[x]);
	}

	void unite(int x , int y){
		int s1 = find(x);
		int s2 = find(y);

		if(s1!=s2){		

			if(rank[s1] < rank[s2]){		//union by rank
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else{
				parent[s2] = s1;
				rank[s1] += rank[s2];	
			}
		}
	}
};

int kruskal(vector<vector<int> > edgeList , int n){
	sort(edgeList.begin(), edgeList.end());
	
	vector<vector<int>> mstEdge;
	DSU dsu(n);

	int ans = 0;
	for(int i = 0 ; i < edgeList.size() ; i++){
		auto edge = edgeList[i];
		int w = edge[0] , x = edge[1] , y = edge[2];
		int s1 = dsu.find(x);
		int s2 = dsu.find(y);
		if(s1!=s2){
			ans += w;
			dsu.unite(x , y);
			mstEdge.push_back(edge);
		}
	}

	return ans;
}


int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> edgeList;
	
	for(int i = 0 ; i < m ; i++){
		int x,y,w;
		cin>>x>>y>>w;
		edgeList.push_back({w , x , y});
	}

	cout<<kruskal(edgeList , n)<<endl;

	return 0;
}