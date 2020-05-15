#include<bits/stdc++.h>
using namespace std;
#define tk printf("Case %d:\n",q+1)
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt","w",stdout);
#define sf(x) scanf("%lld",&x)
#define sff(x,y) scanf("%lld %lld",&x,&y)
#define sfff(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define pb push_back
#define pi acos(-1.0)
#define inf  LLONG_MAX
typedef long long ll;
typedef pair<ll,ll> pii;

ll find(ll arr[],ll n){
    if(arr[n]==n)return n; // if he is the root of himseft return him
    return arr[n]=find(arr,arr[n]); //otherwise find for root and set all elements parent of the same tree  to root 
}

int main(){
            ll n;//number of elements
            sf(n);//scan
            ll arr[n+1];// array for finding roots
            ll wig[n+1]; // array for storing weight
            for(int i=1;i<=n;i++){arr[i]=i;}//setting all elements root = itself ; and all weight =1
            ll a,b;
            sff(a,b);
            ll x=find(arr,a);// find root of first element
            ll y=find(arr,b); // find root for second element
            if(x!=y){ // if root are not same then we will do other works
                if(wig[x]>=wig[y]){ // more weight will dominate
                    arr[y]=x; // seting less weight elements root to more weight element; 
                    wig[x]+=wig[y]; // adding less weights full weight to more weight element as we adding less weight elemets root;
                    wig[y]=0; //weight of less weight elemet=0;
                }
                else{

                    arr[x]=y;   //VV
                    wig[y]+=wig[x];//VV
                    wig[x]=0;   //VV

                }
            }

}
    
