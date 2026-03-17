import sys
from collections import deque

INF = 10**9

def zero_one_bfs(board: list[list[str]], start_r: int, start_c: int) -> list[list[int]]:
    h = len(board)
    w = len(board[0])
    dist = [[INF] * w for _ in range(h)]
    dq = deque([(start_r, start_c)])
    dist[start_r][start_c] = 0

    while dq:
        r, c = dq.popleft()
        base = dist[r][c]

        for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= h or nc < 0 or nc >= w:
                continue
            if board[nr][nc] == '*':
                continue

            w_cost = 1 if board[nr][nc] == '#' else 0
            nd = base + w_cost

            if nd >= dist[nr][nc]:
                continue

            dist[nr][nc] = nd
            if w_cost == 0:
                dq.appendleft((nr, nc))
            else:
                dq.append((nr, nc))

    return dist

def main() -> None:
    input = sys.stdin.buffer.readline
    t = int(input().strip())
    answers: list[str] = []

    for _ in range(t):
        h, w = map(int, input().split())
        board = [['.'] * (w + 2)]
        prisoners: list[tuple[int, int]] = []

        for r in range(1, h + 1):
            row = list(input().strip().decode())
            for c, ch in enumerate(row, start=1):
                if ch == '$':
                    prisoners.append((r, c))
                    row[c - 1] = '.'
            board.append(['.'] + row + ['.'])

        board.append(['.'] * (w + 2))

        d0 = zero_one_bfs(board, 0, 0)
        d1 = zero_one_bfs(board, prisoners[0][0], prisoners[0][1])
        d2 = zero_one_bfs(board, prisoners[1][0], prisoners[1][1])

        result = INF
        for r in range(h + 2):
            for c in range(w + 2):
                if board[r][c] == '*':
                    continue
                total = d0[r][c] + d1[r][c] + d2[r][c]
                if total >= INF:
                    continue
                if board[r][c] == '#':
                    total -= 2
                if total < result:
                    result = total

        answers.append(str(result))

    sys.stdout.write('\n'.join(answers))

if __name__ == "__main__":
    main()