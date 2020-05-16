n, l = 0, 0
g = [[] for i in range(n)]
depth = [0 for i in range(n)]
tin = [0 for i in range(n)]
tout = [0 for i in range(n)]
timer = 0
up = [[] for i in range(n)]

def dfs (v, p = 0):
	depth[v] = depth[p] + 1
	timer += 1
	tin[v] = timer
	up[v][0] = p
	for i in range(1, l+1):
		up[v][i] = up[up[v][i-1]][i-1]
	for i in range(len(g[v])):
		to = g[v][i]
		if to != p:
			dfs(to, v)
	timer += 1
	tout[v] = timer

def upper ( a,  b):
	return tin[a] <= tin[b] and tout[a] >= tout[b]

def lca ( a,  b):
	if (upper (a, b)):
		return a
	if (upper (b, a)):
		return b
	for i in range(l, -1, -1):
		if (not upper (up[a][i], b)):
			a = up[a][i]
	return up[a][0]

def dist(a, b):
	return depth[a] + depth[b] - 2*depth[lca(a, b)]

# int main() {

# 	... чтение n и g ...

# 	tin.resize (n),  tout.resize (n),  up.resize (n);
# 	l = 1;
# 	while ((1<<l) <= n)  ++l;
# 	for (int i=0; i<n; ++i)  up[i].resize (l+1);
# 	dfs (0);

# 	for (;;) {
# 		int a, b; // текущий запрос
# 		int res = lca (a, b); // ответ на запрос
# 	}

# }