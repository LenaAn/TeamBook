E = [[1, 0, 0],
	 [0, 1, 0],
	 [0, 0, 1]]

def matrix_power(M, n):
	res = E
	mtpl = M
	while n:
		if n%2 == 1:
			res = mult(res, mtpl)
		mtpl = mult(mtpl, mtpl)
		n //= 2
	return res

# c ** (-n) % mod
cn_1 = pow(c, n*(mod-2) % (mod-1) , mod)
