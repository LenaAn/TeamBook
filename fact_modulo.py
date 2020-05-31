MODULO = 998244353
n, m = map(int, input().split())

facts = [1 for i in range(m+1)]
for i in range(1, m+1):
	facts[i] = (i * facts[i-1]) % MODULO

facts_1 = [1 for _ in range(m + 1)]
facts_1[m] = pow(facts[m], MODULO - 2, MODULO)
for i in range(m-1, -1, -1):
    facts_1[i] = facts_1[i+1] * (i+1) % MODULO


def C(n, k):
	if k > n:
		print("C is 0")
		return 0
	else:
		to_ret = (facts[n] * facts_1[k] * facts_1[n-k]) % MODULO
		# print("C(", n, ", ", k, "): ", to_ret)
		return to_ret