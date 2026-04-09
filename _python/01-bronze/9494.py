import sys

while True:
    sentence = []
    N = int(sys.stdin.readline())
    if N == 0:
        break
    for i in range(N):
        a = sys.stdin.readline().strip().split(" ")
        sentence.append(a)
    count = 1
    for i in range(N):
        for j in range(len(sentence[i])):
            if count <= sum(map(len,sentence[i][:j+1]))+j+1:
                count = sum(map(len,sentence[i][:j+1]))+j+1
                break
    print(count)