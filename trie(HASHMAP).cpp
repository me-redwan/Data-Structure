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

struct node
{
	bool ended;
	map<char,node*>mp;
	node(){
		ended=false;
	}
};
//INSERT INTO TRIE
void insert( node *&root,string s){
	  if (root == nullptr) root = new node; 
	node *temp=root;
	for(int i=0;i<s.size();i++){
			if(temp->mp.find(s[i])==temp->mp.end()){
				temp->mp[s[i]]=new node;
			}
				temp=temp->mp[s[i]];
	}
	temp->ended=true;
}

//SEARCH INTO TRIE
bool search(node * root,string s){
	 if (root == nullptr) return false; 
	node *temp=root;
	for(int i=0;i<s.size();i++){
		temp=temp->mp[s[i]];
		if(temp==nullptr)return false;
	}
	return temp->ended;
}

//DISTROY TRIE
void del(node*&root){
	if(root==nullptr)return;
    for(auto it=root->mp.begin();it!=root->mp.end();it++){
        del(it->second);
    }
    delete root;
}


int main(){
	WRITE
	node *root= new node;
	insert(root,"red");
	insert(root,"redwan");
	cout<<search(root,"nex")<<endl;
	del(root);
	root= new node;
	insert(root,"phan");
	insert(root,"tom");
	cout<<search(root,"asd")<<endl;
	return 0;
}
