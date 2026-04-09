import sys

def main() -> None:
	input = sys.stdin.readline
	r, c = map(int, input().split())

	team_distance = [0] * 10

	for _ in range(r):
		row = input().strip()

		team = 0
		for ch in row:
			if "1" <= ch <= "9":
				team = ord(ch) - ord("0")
				break

		if team == 0:
			continue

		rightmost = row.rfind(str(team))
		team_distance[team] = (c - 1) - rightmost

	sorted_unique_dist = sorted(set(team_distance[1:]))
	dist_to_rank = {dist: idx + 1 for idx, dist in enumerate(sorted_unique_dist)}

	out = []
	for team in range(1, 10):
		out.append(str(dist_to_rank[team_distance[team]]))

	sys.stdout.write("\n".join(out))

if __name__ == "__main__":
	main()
