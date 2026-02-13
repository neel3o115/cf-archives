#include <bits/stdc++.h>
using namespace std;
void solve(int xe){
	int n,m,k;cin>>n>>m>>k;
	int sm=0,od=2e9,ev=2e9;
	vector <int> adj[n+1];
	for (int i=0;i<k;i++){
		int a;cin>>a;
		sm+=a;
		if(a&1)od=min(od,a);
		else ev=min(ev,a);
	}
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if (sm&1){
		ev=sm-od;
		od=sm;
	}
	else{
		ev=sm;
		od=sm-od;
	}
	int arr[n+1][2];
	for (int i=1;i<=n;i++){
		arr[i][0]=2e9;
		arr[i][1]=2e9;
	}
	queue <int> q;
	arr[1][0]=0;
	q.push(1);
	while (!q.empty()){
		int a=q.front();
		q.pop();
		for (auto x:adj[a]){
			if (arr[x][0]>arr[a][1]+1 || arr[x][1]>arr[a][0]+1){
				arr[x][0]=min(arr[a][1]+1,arr[x][0]);
				arr[x][1]=min(arr[a][0]+1,arr[x][1]);
				q.push(x);
			}
		}
	}
	printf("1");
	for (int i=2;i<=n;i++){
		if (arr[i][0]<=ev || arr[i][1]<=od)printf("1");
		else printf("0");
	}printf("\n");
}

int main() {
	int t;cin>>t;
	int x = t;
	while(t--){
		solve(x);
	}
	return 0;
}