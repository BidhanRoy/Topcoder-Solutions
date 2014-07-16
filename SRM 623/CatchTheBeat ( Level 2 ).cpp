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

#define mx 0

class CatchTheBeat {
	
	int lis(vi vec){
		int n = sz(vec);
		vi I(n+1,INT_MAX);
		I[0] = -INT_MAX;
		int ret = 0;
		rep(i,n){
			int L = upper_bound( all(I) , vec[i] ) - I.begin();
			I[L] = vec[i];
			ret = max(ret,L);
		}
		return ret;
	}
	
	int maxCatched(int n,vi x,vi y){
		vpii ret;
		rep(i,n)
			if( y[i] >= abs(x[i]) )
				ret.pb( { y[i]+x[i] , y[i]-x[i] } );
		n = sz(ret);
		sort(all(ret));
		vi Arr;
		rep(i,n) Arr.pb(ret[i].yy);	
		return lis(Arr);
	}
	
public:
	int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
		vi x(n), y(n);
		x[0]=x0;
		for(int i=1; i<n; i++) x[i] = ( i64(x[i-1]) * i64(a) +b ) % mod1;
		rep(i,n) x[i]-=offset;
		y[0]=y0;
		for(int i=1; i<n; i++) y[i] = ( i64(y[i-1]) * i64(c) +d ) % mod2;
		return maxCatched( n , x , y );
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, bool hasAnswer, int p10) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5 << "," << p6 << "," << p7 << "," << p8 << "," << p9;
	cout << "]" << endl;
	CatchTheBeat *obj;
	int answer;
	obj = new CatchTheBeat();
	clock_t startTime = clock();
	answer = obj->maxCatched(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p10 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p10;
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	int p6;
	int p7;
	int p8;
	int p9;
	int p10;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 0;
	p2 = 0;
	p3 = 1;
	p4 = 1;
	p5 = 1;
	p6 = 1;
	p7 = 100;
	p8 = 100;
	p9 = 1;
	p10 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 0;
	p2 = 1234;
	p3 = 0;
	p4 = 0;
	p5 = 0;
	p6 = 0;
	p7 = 1000000000;
	p8 = 1000000000;
	p9 = 1000;
	p10 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 0;
	p2 = 999;
	p3 = 0;
	p4 = 0;
	p5 = 0;
	p6 = 0;
	p7 = 1000000000;
	p8 = 1000000000;
	p9 = 1000;
	p10 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 100;
	p1 = 0;
	p2 = 0;
	p3 = 1;
	p4 = 1;
	p5 = 1;
	p6 = 1;
	p7 = 3;
	p8 = 58585858;
	p9 = 1;
	p10 = 66;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 500000;
	p1 = 123456;
	p2 = 0;
	p3 = 1;
	p4 = 0;
	p5 = 1;
	p6 = 1;
	p7 = 1000000000;
	p8 = 1000000000;
	p9 = 0;
	p10 = 376544;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 500000;
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	p5 = 0;
	p6 = 0;
	p7 = 1;
	p8 = 1;
	p9 = 0;
	p10 = 500000;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 10;
	p1 = 999999957;
	p2 = 79;
	p3 = 993948167;
	p4 = 24597383;
	p5 = 212151897;
	p6 = 999940854;
	p7 = 999999986;
	p8 = 999940855;
	p9 = 3404;
	p10 = 3;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	{ 
	// ----- test 7 -----
	p0 = 500000;
	p1 = 12314;
	p2 = 53542;
	p3 = 532561259;
	p4 = 95385721;
	p5 = 25712847;
	p6 = 248217541;
	p7 = 1000000000;
	p8 = 999999937;
	p9 = 500000000;
	p10 = 992;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, true, p10) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// One of the modes in the game "osu!" is called "catch the beat".
// In this mode, you control a character that catches falling fruit.
// 
// 
// 
// The game is played in the vertical plane.
// For simplicity, we will assume that both your character and all pieces of fruit are points in that plane.
// 
// 
// 
// You start the game at the coordinates (0, 0).
// Your character can only move along the x-axis.
// The maximum speed of your character is 1 unit of distance per second.
// For example, you need at least 3 seconds to move from (-2, 0) to (1, 0).
// 
// 
// 
// There are n pieces of fruit.
// The pieces are numbered 0 through n-1.
// For each i, fruit i starts at (x[i], y[i]).
// All pieces of fruit fall down with constant speed of 1 unit of distance per second.
// That is, a fruit currently located at (xf, yf) will move to (xf, yf-t) in t seconds.
// You will catch a fruit if the character is located at the same point as the fruit at some moment in time.
// 
// 
// 
// The initial coordinates x[] and y[] are generated using the following pseudocode:
// 
// 
// 
// x[0] = x0
// for i = 1 to n-1:
//     x[i] = (x[i-1] * a + b) % mod1
// 
// for i = 0 to n-1:
//     x[i] = x[i] - offset
// 
// y[0] = y0
// for i = 1 to n-1:
//     y[i] = (y[i-1] * c + d) % mod2
// 
// (In the pseudocode, '%' represents the 'modulo' operator.)
// 
// 
// You are given all the ints used in the above pseudocode.
// Return the maximum number of pieces of fruit you can catch.
// 
// DEFINITION
// Class:CatchTheBeat
// Method:maxCatched
// Parameters:int, int, int, int, int, int, int, int, int, int
// Returns:int
// Method signature:int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset)
// 
// 
// CONSTRAINTS
// -n will be between 1 and 500,000, inclusive.
// -mod1 and mod2 will be between 1 and 1,000,000,000, inclusive.
// -x0, a and b will be between 0 and (mod1 - 1), inclusive.
// -y0, c and d will be between 0 and (mod2 - 1), inclusive.
// -offset will be between 0 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 0
// 0
// 1
// 1
// 1
// 1
// 100
// 100
// 1
// 
// Returns: 2
// 
// There are 3 pieces of fruit.
// Their initial coordinates are (-1, 0), (0, 1), and (1, 2).
// Clearly you cannot catch fruit 0.
// You can catch the other two.
// One way of doing so:
// 
// Wait at (0, 0) for 1 second.
// Catch fruit 1.
// Move to (1, 0) in 1 second.
// Immediately catch fruit 2.
// 
// 
// 1)
// 1
// 0
// 1234
// 0
// 0
// 0
// 0
// 1000000000
// 1000000000
// 1000
// 
// Returns: 1
// 
// The only fruit is located at (-1000, 1234). We can go to (-1000, 0) and then wait for 234 seconds to catch it.
// 
// 2)
// 1
// 0
// 999
// 0
// 0
// 0
// 0
// 1000000000
// 1000000000
// 1000
// 
// Returns: 0
// 
// Now the only fruit is located at (-1000, 999). We can't catch it.
// 
// 3)
// 100
// 0
// 0
// 1
// 1
// 1
// 1
// 3
// 58585858
// 1
// 
// Returns: 66
// 
// 
// 
// 4)
// 500000
// 123456
// 0
// 1
// 0
// 1
// 1
// 1000000000
// 1000000000
// 0
// 
// Returns: 376544
// 
// The fruits are located in (123456, 0), (123456, 1), ..., (123456, 499999).
// 
// 5)
// 500000
// 0
// 0
// 0
// 0
// 0
// 0
// 1
// 1
// 0
// 
// Returns: 500000
// 
// In this case all the fruits start at (0, 0).
// Note that there can be more than one fruit at any position.
// We can catch all such fruit at the same time.
// 
// 6)
// 10
// 999999957
// 79
// 993948167
// 24597383
// 212151897
// 999940854
// 999999986
// 999940855
// 3404
// 
// Returns: 3
// 
// Watch out for integer overflow when generating the coordinates.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!