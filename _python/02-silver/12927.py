import sys

def main() -> None:
    s = sys.stdin.readline().strip()
    n = len(s)

    # 1-indexed로 다루기 위해 앞에 더미 추가
    light = [''] + list(s)
    count = 0

    for i in range(1, n + 1):
        if light[i] == 'Y':
            count += 1
            for j in range(i, n + 1, i):
                light[j] = 'N' if light[j] == 'Y' else 'Y'

    print(count)

if __name__ == "__main__":
    main()