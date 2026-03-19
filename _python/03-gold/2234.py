import sys
from collections import deque

def main() -> None:
    m, n = map(int, sys.stdin.readline().split())
    grid = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

    # bit 오더: west(1), north(2), east(4), south(8)
    dr = [0, -1, 0, 1]
    dc = [-1, 0, 1, 0]
    wall_bit = [1, 2, 4, 8]

    room_id = [[-1] * m for _ in range(n)]
    room_sizes = []

    for r in range(n):
        for c in range(m):
            if room_id[r][c] != -1:
                continue

            cur_id = len(room_sizes)
            q = deque([(r, c)])
            room_id[r][c] = cur_id
            size = 1

            while q:
                cr, cc = q.popleft()
                cell = grid[cr][cc]

                for d in range(4):
                    nr = cr + dr[d]
                    nc = cc + dc[d]
                    if not (0 <= nr < n and 0 <= nc < m):
                        continue
                    if cell & wall_bit[d]:
                        continue
                    if room_id[nr][nc] != -1:
                        continue

                    room_id[nr][nc] = cur_id
                    size += 1
                    q.append((nr, nc))

            room_sizes.append(size)

    room_count = len(room_sizes)
    max_room_size = max(room_sizes)

    max_after_remove = 0
    for r in range(n):
        for c in range(m):
            id_a = room_id[r][c]
            for d in range(4):
                nr = r + dr[d]
                nc = c + dc[d]
                if not (0 <= nr < n and 0 <= nc < m):
                    continue
                id_b = room_id[nr][nc]
                if id_a == id_b:
                    continue
                max_after_remove = max(max_after_remove, room_sizes[id_a] + room_sizes[id_b])

    print(room_count)
    print(max_room_size)
    print(max_after_remove)

if __name__ == "__main__":
    main()