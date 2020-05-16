A, B = set(), set()

q_a = set()
q_a.add(1)
q_b = set()

while (len(q_a) > 0):
	for item in q_a:
		A.add(item)
	for item in q_a:
		for neigh in adj[item]:
			if (neigh not in A) and (neigh not in B):
				q_b.add(neigh)
