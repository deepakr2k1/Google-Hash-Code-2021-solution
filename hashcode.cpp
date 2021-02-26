// Hash-Code 2021 solution got (+8,946,214 pts)
// Link to Problem -
// https://hashcodejudge.withgoogle.com/#/rounds/5879728443490304/

#include <bits/stdc++.h>
using namespace std;
#define FastIO           ios_base::sync_with_stdio(false),cin.tie(NULL);
#define dbg              cout<<"-------------------------\n" 
#define endl             "\n"
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define irep(i,a,b)      for(int i=a;i>=b;i--)
#define ip(V,n)          vector<int> V(n); for(int _i=0;_i<n;_i++) cin>>V[_i]
#define op(V,sep)        for(int _i=0;_i<V.size();_i++) cout<<V[_i]<<sep;cout<<endl
#define all(x)           (x).begin(),(x).end()
#define vi               vector<int>
#define vvi              vector<vector<int>>
#define pb               push_back
#define pii              pair<int,int>
#define mp               make_pair
#define fi               first
#define se               second
#define int              long long int
#define INF              1e18
// .................... User: zero_bug ....................

void solve() {

    freopen("f.txt","r",stdin);
    freopen("output-f.txt","w",stdout);

    int d,I,s,v,f;
	cin>>d>>I>>s>>v>>f;
    int VV=v;
    vvi adj(I);

	unordered_map<string,int> street_time;
	unordered_map<string,pii> street_inter;

	while(s--) {
        int b,e;
        cin>>b>>e;
        adj[b].push_back(e);
        string street;
        cin>>street;
        int time;
        cin>>time;
        street_inter[street]={b,e};
        street_time[street]=time;		
	}

    vector<vector<string>> cars(v);
    vector<pii> ABCD;

	rep(i,0,v-1) {
		int n;
		cin>>n;
		int sum=0;
		while(n--) {
			string street;
			cin>>street;
            cars[i].push_back(street);
            sum+=street_time[street];
		}
        ABCD.push_back({sum, i});
	}

    sort(all(ABCD));

    vector<vector<string>> ans1(I);
    vector<vector<int>> ans2(I);
	set<string> used;

    rep(cc,0,VV-1) {
        int time=0;
        bool first=true;
        for(string street: cars[ABCD[cc].second]) {
            if(!first) {
                time+=street_time[street];
            }
            if(used.find(street) == used.end()) {
                ans1[street_inter[street].second].push_back(street);       
                ans2[street_inter[street].second].push_back(2);
                used.insert(street);
            }
            first=false;
        }
    }

    int count=0;
    rep(i,0,I-1) {
        if(!ans1[i].empty()) {
            count++;
        }
    }

    cout<<count<<endl;
    rep(i,0,I-1) {
        if(!ans1[i].empty()) {
            cout<<i<<endl;
            count++;
            cout<<ans1[i].size()<<endl;
            rep(x,0,ans1[i].size()-1) {
                cout<<ans1[i][x]<<" "<<ans2[i][x]<<endl;
            }
        }
    }
}

int32_t main() {
    FastIO
    #ifdef NCR
        preCompute();
    #endif  // Power | ModInverse | Factorial | NCRmodP
    #ifdef SIEVE
        sieve();
    #endif  // checkPrime(sieve) | getFactorization
    solve();
}