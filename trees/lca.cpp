#include <bits/stdc++.h>

#define loop(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__;

int n, l;
vector<vector<int> > g;
vector<int> tin, tout, depth;
int timer;
vector<vector<int> > up;

void dfs (int v, int p = 0) {
	depth[v] = depth[p] + 1;
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

int dist(int a, int b) {
	return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

int main() {
	int a, b;
	cin >> n;
	g.resize(n);
	// cout << "resized g" << "\n";
	for (int i =0 ; i < n-1; ++i){
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// cout << "g " << "\n";


	tin.resize(n),  tout.resize(n),  up.resize(n), depth.resize(n);
	l = 1;
	while ((1<<l) <= n)
		++l;
	for (int i=0; i<n; ++i)
		up[i].resize(l+1);
	dfs(0);
}