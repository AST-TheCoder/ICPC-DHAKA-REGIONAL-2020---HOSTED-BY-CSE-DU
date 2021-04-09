//Problem link: https://algo.codemarshal.org/contests/icpc-dhaka-20-preli/problems/F
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

ll vis[1000007];
vector<ll> pf;

ll count_co(ll n){
	ll ans=0;
	ll r=pow(2,(ll)pf.size());
	for(ll i=0;i<r;i++){
		ll m=1,c=0;
		for(ll j=0;j<pf.size();j++){
			if(i&(1<<j)){
				c++;
				m*=pf[j];
			}
		}
	
		if(c%2) ans-=(n/m);
		else ans+=(n/m);
	}
	return ans;
}

int main()
{	

	vector<ll> p;
	for(ll i=2;i<1000007;i++){
		if(!vis[i]){
			p.pb(i);
			for(ll j=i;j<1000007;j+=i) vis[j]=1;
		}
	}

	ll t,ii=0;
	cin>>t;
	while(t--){
		pf.clear();
		ll a,b,m;
		cin>>a>>b>>m;
		ll d=abs(a-b);

		if(!d){
			ll x;
			if(a==1) x=1;
			else x=0;
			cout<<"Case "<<++ii<<": "<<x<<endl;
			continue;
		}
		
		for(ll i=0;i<p.size() && p[i]*p[i]<=d;i++){
			if(d%p[i]==0){
				while(d%p[i]==0) d/=p[i];
				pf.pb(p[i]);
			}
		}

		if(d!=1) pf.pb(d);
		ll x=count_co(a-1);
		ll y=count_co(a+m);

		cout<<"Case "<<++ii<<": "<<y-x<<endl;
	}

	return 0;
}
