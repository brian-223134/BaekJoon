import sys

input = sys.stdin.readline

class Student:
    def __init__(self, name, korean, english, math):
        self.name = name
        self.korean = korean
        self.english = english
        self.math = math

    def __lt__(self, other):
        # 문제에서 요구한 정렬 우선순위
        if self.korean != other.korean:
            return self.korean > other.korean
        if self.english != other.english:
            return self.english < other.english
        if self.math != other.math:
            return self.math > other.math
        return self.name < other.name


n = int(input())
students = []

for _ in range(n):
    name, korean, english, math = input().split()
    students.append(Student(name, int(korean), int(english), int(math)))

students.sort()

for student in students:
    print(student.name)
