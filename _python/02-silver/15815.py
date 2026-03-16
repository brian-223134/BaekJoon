import sys

expression = sys.stdin.readline().strip()
stack = []
append = stack.append
pop = stack.pop

for ch in expression:
    if '0' <= ch <= '9':
        append(ord(ch) - 48)
        continue

    second = pop()
    first = pop()

    if ch == '+':
        append(first + second)
    elif ch == '-':
        append(first - second)
    elif ch == '*':
        append(first * second)
    else:
        quotient = abs(first) // abs(second)
        append(-quotient if (first < 0) ^ (second < 0) else quotient)

print(stack[0])