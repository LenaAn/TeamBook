# https://e-maxx.ru/algo/palindromes_count

d1 = [0 for i in range(n)]
l, r = 0, -1
for i in range(n):
	if i < r:
		k = 1
	else:
		k = min(d1[l+r-i], r-i+1)
	
	while i+k < n and i-k >= 0 and s[i+k] == s[i-k]:
		k += 1

  	d1[i] = k
  	if i+k-1 > r:
	    l = i - k + 1
	    r = i + k - 1

d2 = [0 for i in range(n)]
l, r = 0, -1
for i in range(n):
	if i > r:
		k = 0
	else:
		k = min(d2[l+r-i+1], r-i+1)

	while i+k < n and i - k - 1 >= 0 and s[i+k] == s[i-k-1]:
		k += 1

	d2[i] = k
	if i + k - 1 > r:
		l = i - k
		r = i + k - 1