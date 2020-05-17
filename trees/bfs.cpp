#include <bits/stdc++.h>

#define loop(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__;

int n, m;
vector<vector<int> > g;
vector<int> parent, used;
queue<int> q;
int next_, a, b, child;


int main() {
	cin >> n >> m;
	g.resize(n);
	for (int i =0 ; i < m; ++i){
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	parent.resize(n), used.resize(n);
	fill(used.begin(), used.end(), false);
	fill(parent.begin(), parent.end(), -1);

	q.push(0);
	used[0] = true;

	while (!q.empty()){
		next_ = q.front();
		q.pop();

		loop(i, g[next_].size()){
			child = g[next_][i];
			if (! used[child]){
				used[child] = true;
				q.push(child);
				parent[child] = next_;
			}
		}
	}

	// bool flag_connected = true;
	// loop(i, n){
	// 	if (!used[i]){
	// 		flag_connected = false;
	// 		break;
	// 	}
	// }

	// if (flag_connected){
	// 	cout << "Yes" << "\n";
	// 	for (int i =1 ; i<n; ++i){
	// 		cout << parent[i] + 1 << "\n";
	// 	}
	// } else {
	// 	cout << "No\n"; 
	// }

	return 0;
}