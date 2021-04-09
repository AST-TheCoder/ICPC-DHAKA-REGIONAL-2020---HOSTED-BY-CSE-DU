//Problem link: https://algo.codemarshal.org/contests/icpc-dhaka-20-preli/problems/I
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

	while(1){
		ll l,l1,p,q;
		scanf("%lli %lli %lli/%lli",&l,&l1,&p,&q);
		if(q==0) break;

		ll b=(2LL*l1*q*q-2LL*q*q-2LL*l*p*p+2LL*p*p)/(p*p-p*q);
		ll ans=2LL*l+b-2LL;
		printf("%lli\n",ans);
	}

	return 0;
}
