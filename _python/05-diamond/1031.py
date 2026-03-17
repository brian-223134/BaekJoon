import sys
from collections import deque

class EdmondsKarp:  
    def __init__(self, n: int):
        self.n = n
        # capacity[u][v]와 flow[u][v]를 항상 유지
        self.capacity = [[0] * n for _ in range(n)]
        self.flow = [[0] * n for _ in range(n)]
    
    def add_edge(self, u: int, v: int, cap: int) -> None:
        self.capacity[u][v] += cap
    
    def bfs(self, source: int, sink: int) -> list:
        # BFS로 source에서 sink로 가는 증강 경로 찾기
        parent = [-1] * self.n
        parent[source] = source
        queue = deque([source])
        
        while queue:
            u = queue.popleft()
            
            for v in range(self.n):
                if parent[v] == -1 and self.capacity[u][v] - self.flow[u][v] > 0:
                    parent[v] = u
                    if v == sink:
                        # 경로 복원
                        path = []
                        curr = sink
                        while parent[curr] != curr:
                            path.append(curr)
                            curr = parent[curr]
                        path.append(source)
                        path.reverse()
                        return path
                    queue.append(v)
        
        return []
    
    def max_flow(self, source: int, sink: int) -> int:
        # Edmonds-Karp 알고리즘으로 최대 유량 계산
        total = 0
        
        while True:
            path = self.bfs(source, sink)
            if not path:
                break
            
            # 경로의 최소 용량 찾기
            min_flow = float('inf')
            for i in range(len(path) - 1):
                u, v = path[i], path[i + 1]
                min_flow = min(min_flow, self.capacity[u][v] - self.flow[u][v])
            
            # 유량 업데이트
            for i in range(len(path) - 1):
                u, v = path[i], path[i + 1]
                self.flow[u][v] += min_flow
                self.flow[v][u] -= min_flow
            
            total += min_flow
        
        return total
    
    def can_reroute_bfs(self, u: int, target: int, start_i: int, start_j: int, n_g: int, n_h: int) -> list:
        """BFS로 u에서 target으로 가는 경로 찾기. 경로 리스트 또는 None 반환"""
        parent = {u: None}
        queue = deque([u])
        
        while queue:
            curr = queue.popleft()
            
            if curr == target:
                # 경로 복원
                path = []
                node = target
                while node is not None:
                    path.append(node)
                    node = parent[node]
                path.reverse()
                return path
            
            if curr <= n_g:
                for v in range(n_g + 1, n_g + n_h + 1):
                    if v not in parent:
                        i = curr - 1
                        j = v - n_g - 1
                        if i > start_i or (i == start_i and j > start_j):
                            if self.capacity[curr][v] - self.flow[curr][v] > 0:
                                parent[v] = curr
                                queue.append(v)
            else:
                for v in range(1, n_g + 1):
                    if v not in parent:
                        i = v - 1
                        j = curr - n_g - 1
                        if i > start_i or (i == start_i and j > start_j):
                            if self.capacity[curr][v] - self.flow[curr][v] > 0:
                                parent[v] = curr
                                queue.append(v)
        
        return None

def main() -> None:
    n, m = map(int, input().split())
    g_games = list(map(int, input().split()))
    h_games = list(map(int, input().split()))
    
    # 전체 경기 수 확인
    if sum(g_games) != sum(h_games):
        print(-1)
        return
    
    # 노드: 0(source), 1~n(지민), n+1~n+m(한수), n+m+1(sink)
    total_nodes = n + m + 2
    ek = EdmondsKarp(total_nodes)
    
    source = 0
    sink = n + m + 1
    
    # 간선 추가
    for i in range(n):
        ek.add_edge(source, i + 1, g_games[i])
    
    for i in range(n):
        for j in range(m):
            ek.add_edge(i + 1, n + 1 + j, 1)
    
    for j in range(m):
        ek.add_edge(n + 1 + j, sink, h_games[j])
    
    # 최대 유량 계산
    max_flow_value = ek.max_flow(source, sink)
    
    if max_flow_value != sum(g_games):
        print(-1)
        return
    
    # 사전 순 정렬: 각 간선의 필수 여부 판단
    result = [[0] * m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            u = i + 1          # 지민이 팀 노드
            v = n + 1 + j      # 한수 팀 노드
            
            # 현재 edge가 사용 중인지 확인
            if ek.flow[u][v] == 1:
                # 일단 경기를 끊어본다
                ek.flow[u][v] = 0
                ek.flow[v][u] = 0
                
                # u에서 v로 가는 대체 경로가 있는지 확인 (BFS)
                path = ek.can_reroute_bfs(u, v, i, j, n, m)
                
                if path:
                    # 대체 경로가 있으면 능동적으로 경로 유량 업데이트
                    for k in range(len(path) - 1):
                        a, b = path[k], path[k + 1]
                        ek.flow[a][b] += 1
                        ek.flow[b][a] -= 1
                    result[i][j] = 0
                else:
                    # 대체 경로가 없으면 필수 간선 1 복구
                    ek.flow[u][v] = 1
                    ek.flow[v][u] = -1
                    result[i][j] = 1
            else:
                result[i][j] = 0
    
    for row in result:
        print(''.join(map(str, row)))

if __name__ == "__main__":
    main()