# 백준 풀이 Repository

---

💻 **사용 언어**

- ![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)
- ![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)
- (모든 문제는 C++ 및 Python으로 풀이하였습니다.)

💻 **개발 환경**

- ![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=flat&logo=visual-studio&logoColor=white)
- ![Visual Studio Code](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-007ACC?style=flat&logo=visual-studio-code&logoColor=white)

---

## 🧩 Python 코딩 테스트 입력 패턴 정리

### 1) 기본 세팅

```python
import sys
input = sys.stdin.readline
```

### 2) 자주 쓰는 입력 템플릿

```python
# 단일 정수
n = int(input())

# 정수 여러 개(한 줄)
a, b, c = map(int, input().split())

# 배열 한 줄
arr = list(map(int, input().split()))

# N줄 입력
n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

# 문자열
s = input().strip()

# 숫자 문자열 자리수 분리 (예: "12345" -> [1,2,3,4,5])
digits = list(map(int, input().strip()))
```

## 백준 섭종 이후
- PS: 정올
- 코테: programmers

- 대량 입력에서 `input()`만 사용해 시간초과 발생
- 문자열 입력에서 `strip()` 누락으로 개행 문자 포함
- 문제 인덱스(1-based)와 Python 인덱스(0-based) 혼동
- 입력 형식 착각 (`int(input())` vs `map(int, input().split())`)
