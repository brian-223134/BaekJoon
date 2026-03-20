import sys
input = sys.stdin.readline

H, W, X, Y = map(int, input().split())

B = [list(map(int, input().split())) for _ in range(H + X)]

A = [[0] * W for _ in range(H)]

for i in range(H):
    for j in range(W):
        A[i][j] = B[i][j]
        # 겹치는 영역이면 이미 복원한 A값을 빼준다
        if i >= X and j >= Y:
            A[i][j] -= A[i - X][j - Y]

for row in A:
    print(*row)
