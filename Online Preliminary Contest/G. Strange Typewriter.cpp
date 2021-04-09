//Problem link: https://algo.codemarshal.org/contests/icpc-dhaka-20-preli/problems/G
//Note: The solution is not checked. So, I'm not 100% sure that it is correct.
//Solution:

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{	

	ll t,ii=0;
	scanf("%lli",&t);

	while(t--){
		ll n,mod=1000000007;
		scanf("%lli",&n);
		vector<pair<ll,ll>> key_hash[200];
		for(ll i=1;i<=n;i++){
			string x;
			cin>>x;
			ll hash=0;
			for(ll j=0;j<x.size();j++){
				hash=(hash*29+(ll)(x[j]-'a')+1)%mod;
			}
			key_hash[x[0]].pb({x.size(),hash});
		}

		for(ll i='a';i<='z';i++){
			key_hash[i].resize(distance(key_hash[i].begin(),unique(all(key_hash[i]))));
		}

		string s;
		cin>>s;
		ll hash[s.size()+5],base[s.size()+5],dp[s.size()+5];
		base[0]=1;
		for(ll i=1;i<s.size()+5;i++){
			base[i]=(base[i-1]*29)%mod;
			dp[i]=INT_MAX;
		}

		hash[0]=0;
		for(ll i=1;i<=s.size();i++){
			hash[i]=(hash[i-1]*29+(ll)(s[i-1]-'a')+1)%mod;
		}

		dp[1]=0;
		for(ll i=1;i<=s.size();i++){
			for(ll j=0;j<key_hash[s[i-1]].size();j++){
				ll len=key_hash[s[i-1]][j].first;
				ll val=key_hash[s[i-1]][j].second;
				if(i+len-1>s.size()) continue;
				ll h=(hash[i+len-1]-(hash[i-1]*base[len])%mod+mod)%mod;
				if(h==val) dp[i+len]=min(dp[i+len],dp[i]+1);
			}
		}

		printf("Case %lli: ",++ii);
		if(dp[s.size()+1]==INT_MAX) printf("impossible\n");
		else printf("%lli\n",dp[s.size()+1]);
	}

	return 0;
}
