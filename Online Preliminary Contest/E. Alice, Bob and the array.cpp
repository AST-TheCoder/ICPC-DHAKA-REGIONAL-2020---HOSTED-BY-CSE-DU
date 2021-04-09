//Problem link: https://algo.codemarshal.org/contests/icpc-dhaka-20-preli/problems/E
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
	cin>>t;
	while(t--){
		ll l;
		cin>>l;
		vector<ll> x;
		x.pb(-1);

		for(ll i=1;i<=l;i++){
			ll p;
			cin>>p;
			x.pb(p);
		}x.pb(-1);

		ll ok=0,n=0,p=0;
		for(ll i=0;i<x.size();i++){
			if(x[i]<0 && !ok){
				n++;
				ok=1;
			}
			if(x[i]>0){
				p+=x[i];
				ok=0;
			}
		}

		n-=2;
		if(n<0){
			n=0;
			p=-INT_MAX;
			for(ll i=1;i<x.size()-1;i++){
				p=max(p,x[i]);
			}
		}

		cout<<"Case "<<++ii<<": "<<p<<" "<<n<<endl;
	}

	return 0;
}
