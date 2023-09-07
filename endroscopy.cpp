#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map<char,set<int>> mp;
int n,m;
bool isValid(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m;
}
char find_dir(vector<int> &p){
	if(p[0]==0){
       if(p[1]==-1){ return 'R';}
	   else return 'L';
	}
	else if(p[0]==1) return 'D';
	return 'U';
}
int main(){
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifdef baby_ka_laptop
      freopen("in.txt" , "r", stdin);
      freopen("out.txt" ,"w", stdout);
    #endif
	 int t; cin>>t;
    while(t--){
      cin>>n>>m;
	int X,Y; cin>>X>>Y;
	X++; Y++;
	int l; cin>>l; 
	vector<vector<int>> a(n+1,vector<int> (m+1));
	vector<vector<int>> v(n+1,vector<int> (m+1,-1));
	vector<vector<vector<int>>> moves={{},{{1,0},{-1,0},{0,1},{0,-1}},{{-1,0},{1,0}},{{0,-1},{0,1}},{{-1,0},{0,1}},{{0,1},{1,0}},{{0,-1},{1,0}},{{-1,0},{0,-1}}};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		   cin>>a[i][j];
	    }
	}
	mp['D'] = {1,2,4,7};
	mp['U'] = {1,2,5,6};
	mp['L'] = {1,3,6,7};
	mp['R'] = {1,3,4,5};
	queue<pair<int,int>> q;
	q.push({X,Y});
	v[X][Y]=1;
   if(a[X][Y]==0){v[X][Y]=0;}
	while(!q.empty()){
		auto f = q.front(); q.pop();
		int x = f.first;
		int y = f.second;
        for(auto p:moves[a[x][y]]){
           int x1 = x + p[0];
           int y1 = y + p[1];
		   if(!isValid(x1,y1)) continue;
         if(a[x1][y1]==0)continue;
		   if(v[x1][y1]!=-1) continue;
	       char c = find_dir(p);
		   if(mp[c].find(a[x1][y1])==mp[c].end()) continue;
		   v[x1][y1] = v[x][y]+1;
		   q.push({x1,y1});
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
       for(int j=1;j<=m;j++){
          if(v[i][j]>=1 && v[i][j]<=l)ans++;

	}
   }
	cout<<ans<<endl;
    }
	return 0;
}