// ll = long long
// n= size of array
// ind = index
// val= value

ll tree[100001];

//update BIT (also for Construct)
void update(ll n,ll ind,ll val){
	while(ind<=n){
		tree[ind]+=val;
		ind+=(ind & -ind);
	}
}

//query

int query(ll n,ll ind){
	ll value=0;
	while(ind>0){
		value+=tree[ind];
		ind-=(ind & -ind);
	}
	return value;
}
