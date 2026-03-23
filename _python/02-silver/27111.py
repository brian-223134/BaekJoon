import sys
input = sys.stdin.readline

n = int(input());
building = set()
cnt = 0

for _ in range(n):
  a, b = map(int, input().split())

  if b == 1:
    if a in building:
      cnt += 1
    building.add(a)
  else:
      if a not in building:
        cnt += 1
      else:
        building.remove(a)

cnt += len(building)
print(cnt)