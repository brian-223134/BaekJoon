import sys


def main() -> None:
	input = sys.stdin.readline

	n, k = map(int, input().split())
	wheel = ["?"] * n
	char_pos = {}

	pos = 0

	for _ in range(k):
		s, ch = input().split()
		s = int(s)

		pos = (pos - s) % n

		existing = wheel[pos]
		if existing == "?":
			if ch in char_pos and char_pos[ch] != pos:
				print("!")
				return
			wheel[pos] = ch
			char_pos[ch] = pos
		elif existing != ch:
			print("!")
			return

	answer = "".join(wheel[(pos + i) % n] for i in range(n))
	print(answer)

if __name__ == "__main__":
	main()