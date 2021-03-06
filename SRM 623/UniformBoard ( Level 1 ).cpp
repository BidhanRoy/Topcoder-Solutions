/*
 * Bidhan Roy
 * University of Dhaka
 */
 
using namespace std;
#include <bits/stdc++.h>
 
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
 
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
 
#define mx 30

class UniformBoard {
public:
	int A[mx][mx], P[mx][mx];
	void call(int n,int dp[][mx]){
		rep(i,n){
			rep(j,n){
				if(i) dp[i][j] += dp[i-1][j];
				if(j) dp[i][j] += dp[i][j-1];
				if(i && j) dp[i][j] -= dp[i-1][j-1];
			}
		}
	}
	int get(int i,int j,int h,int w,int dp[][mx]){
		int ret = dp[i+h-1][j+w-1];
		if(i) ret -= dp[i-1][j+w-1];
		if(j) ret -= dp[i+h-1][j-1];
		if(i && j) ret += dp[i-1][j-1];
		return ret;
	}
	int getBoard(vector <string> board, int K) {
		int n = sz(board);
		int cnt = 0, empty = 0;;
		rep(i,n){
			rep(j,n){
				if(board[i][j]=='.') A[i][j] = P[i][j] = 0, empty++;
				else if(board[i][j]=='A') A[i][j] = 1, P[i][j] = 0, cnt++;
				else A[i][j] = 0 , P[i][j] = 1;
			}
		}
		call(n,A);
		call(n,P);
		int ans = 0;
		rep(i,n) rep(j,n) for(int H=1; H<=n; H++) for(int W=1; W<=n; W++) {
			if(i+H-1>=n) continue;
			if(j+W-1>=n) continue;
			if(cnt<H*W) continue;
			if(!empty){
				if(get(i,j,H,W,A)==H*W) ans = max(ans,H*W);
				continue;
			}
			int apple = get(i,j,H,W,A);
			int pie = get(i,j,H,W,P);
			int temp = pie + (H*W) - apple ;
			if(temp<=K) ans = max(ans,H*W);
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	UniformBoard *obj;
	int answer;
	obj = new UniformBoard();
	clock_t startTime = clock();
	answer = obj->getBoard(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"AP",".A"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"AP",".A"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"PPP","APA","A.P"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"AAA","PPP","AAA"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	p2 = 3;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000;
	p2 = 0;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"PPAAPA..AP","PPA.APAP..","..P.AA.PPP","P.P..APAA.","P.P..P.APA","PPA..AP.AA","APP..AAPAA","P.P.AP...P",".P.A.PAPPA","..PAPAP..P"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	p2 = 15;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
