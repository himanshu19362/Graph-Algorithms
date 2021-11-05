#include <bits/stdc++.h>
using namespace std;

//DP on graphs with bitmsking
int tsp(vector<vector<int>> distance , int setOfCities , int n , int currCity , int src , vector<vector<int>> &dp){		//0s in set of cities means that these cities are not visited
	if(setOfCities == (1 << n) - 1){
		return distance[currCity][src];
	}
	
	if(dp[setOfCities][currCity]!=-1)	return dp[setOfCities][currCity];

	int ans = INT_MAX;
	for(int choice = 0 ; choice < n ; choice++){
		if((setOfCities & (1<<choice)) == 0){			
			ans = min(ans , distance[currCity][choice] + tsp(distance , setOfCities | (1<<choice) , n , choice , src , dp));
		}
	}
	
	return dp[setOfCities][currCity] = ans;
}


int main(){
		
	vector<vector<int>> distance = {
		{0 , 20 , 42 , 25},
		{20 , 0 , 30 , 34},
		{42 , 30 , 0 , 10},
		{25 , 34 , 10 , 0}
	};

	vector<vector<int>> dp(1001 , vector<int>(1001 , -1));

	cout<<tsp(distance , 1 , 4 , 0 , 0 , dp);	//This will return 85.
	return 0;

}