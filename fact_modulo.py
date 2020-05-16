MODULO = 998244353
n, m = map(int, input().split())

facts = [1 for i in range(m+1)]
for i in range(1, m+1):
	facts[i] = (i * facts[i-1]) % MODULO

facts_1 = [pow(facts[i], MODULO-2, MODULO) for i in range(m+1)]


def C(n, k):
	if k > n:
		print("C is 0")
		return 0
	else:
		to_ret = (facts[n] * facts_1[k] * facts_1[n-k]) % MODULO
		# print("C(", n, ", ", k, "): ", to_ret)
		return to_ret