#include <bits/stdc++.h>

#define loop(i,a,b) for (int i = a; i < b; i++)
#define loop(i,n)   for (int i = 0; i < n; i++)

using namespace std;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__;

vector<int> parent, my_size;

int find_set(int v){
	if (parent[v] == v)
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v){
	u = find_set(u);
	v = find_set(v);

	if (u != v) {
		if (my_size[u] < my_size[v]) {
			swap(u, v);
		}
		parent[v] = u;
		my_size[u] += my_size[v];	
	}
}


int main() {
	int n;
	cin >> n;

	loop(i, n+1)
	{
		parent.push_back(i);
		my_size.push_back(1);
	}


	// loop(i, 1, n+1) {
	// 	printf("%d ", ans[i]);
	// }
	// printf("\n");

	return 0;
}