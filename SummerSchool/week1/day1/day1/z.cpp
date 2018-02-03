#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define mt make_tuple
#define rep(i,a,b) for(int (i) = (a); (i) < (b); ++(i))

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

bool check(string& s){
	int op = 0;
	for(const char& c : s){
		if(c == ')'){
			if(!op) return false;
			op--;
		}
		else op++;
	}
	return !op;
}

int main(){
	int n;
	cin >> n;
	string t;
	rep(i,0,n){
		t.push_back('(');
	}
	rep(i,0,n) t.push_back(')');
	do{
		if(check(t)){
			cout << t << endl;
		}
	}while(next_permutation(all(t)));
	return 0;
}
