import sys

input = sys.stdin.readline


class DailyRecord:
	def __init__(self, text):
		self.text = text.rstrip("\n")

	def is_boj_link(self):
		prefix = "boj.kr/"
		if not self.text.startswith(prefix):
			return False
		number = self.text[len(prefix):]
		return number.isdigit()

	def problem_number(self):
		return int(self.text[7:])


def main():
	n = int(input())
	studies = []
	boj_links = []

	for _ in range(n):
		record = DailyRecord(input())
		if record.is_boj_link():
			boj_links.append(record)
		else:
			studies.append(record)

	studies.sort(key=lambda r: (len(r.text), r.text))
	boj_links.sort(key=lambda r: r.problem_number())

	for record in studies:
		print(record.text)
	for record in boj_links:
		print(record.text)


if __name__ == "__main__":
	main()