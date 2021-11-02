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
		if(parent[x] == -1)	return x;
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


int main(){

}