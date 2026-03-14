import sys

def main() -> None:
    input = sys.stdin.readline
    n, m = map(int, input().split())
    result = (m - 1) * n + 1
    print(result)

if __name__ == "__main__":
    main()