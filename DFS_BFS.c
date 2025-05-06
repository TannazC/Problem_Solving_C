'''
Graph Traversal and Pathfinding Practice
Author: Tannaz Chowdhury  
Date: 2025

This file implements various depth-first search (DFS), stack-based DFS, dynamic programming, and A* planning examples.
Each function is annotated to illustrate step-by-step reasoning and graph traversal strategies.
'''

# -----------------------------------------------------------------------------
# Question 1: Race to 21 Game Solver (Recursive DFS)
# -----------------------------------------------------------------------------
# Recursively determine if the current player can guarantee a win starting at 'current'.
def dfs(current, is_my_turn):
    if current == 21:
        return is_my_turn  # Whoever lands on 21 wins
    if current > 21:
        return False       # Invalid move

    for move in [1, 2, 3]:
        next_pos = current + move
        result = dfs(next_pos, not is_my_turn)  # Flip player turn

        if is_my_turn:
            if result:     # At least one path to win
                return True
        else:
            if not result: # Opponent can block
                return False

    return not is_my_turn  # No winning move

# -----------------------------------------------------------------------------
# Question 2: Race to 21 Game Solver (Stack-based DFS)
# -----------------------------------------------------------------------------
def dfs_with_stack(start):
    stack = [(start, True)]  # (position, is_my_turn)
    visited = {}  # Memoization table

    while stack:
        current, is_my_turn = stack.pop()

        if (current, is_my_turn) in visited:
            continue

        if current == 21:
            visited[(current, is_my_turn)] = is_my_turn
            continue

        if current > 21:
            visited[(current, is_my_turn)] = False
            continue

        children = [(current + m, not is_my_turn) for m in [1, 2, 3]]
        undecided = []
        result = None

        for child in children:
            if child in visited:
                child_result = visited[child]
            else:
                undecided.append(child)
                continue

            if is_my_turn and child_result:
                result = True
                break
            if not is_my_turn and not child_result:
                result = False
                break

        if result is not None:
            visited[(current, is_my_turn)] = result
        elif not undecided:
            visited[(current, is_my_turn)] = not is_my_turn
        else:
            stack.append((current, is_my_turn))
            stack.extend(undecided)

    return visited[(start, True)]


# -----------------------------------------------------------------------------
# Question 3: Least Cost Path Up a Staircase (Recursive DP)
# -----------------------------------------------------------------------------
def leastcost(cost, pos, n):
    if pos == n - 1:
        return cost[pos], []
    if pos >= n:
        return float('inf'), []  # Invalid

    min_cost = float('inf')
    best_path = []

    for step in [1, 2, 3]:
        next_pos = pos + step
        if next_pos >= n:
            continue

        total_cost, path = leastcost(cost, next_pos, n)
        total_cost += cost[next_pos]

        if total_cost < min_cost:
            min_cost = total_cost
            best_path = [step] + path

    return min_cost, best_path


# -----------------------------------------------------------------------------
# Question 4: Longest Friendship Chain Using Stack-Based DFS
# -----------------------------------------------------------------------------
def longest_chain(friends):
    max_length = 0

    for start in friends:
        stack = [(start, set([start]), 1)]  # (current, visited set, chain length)

        while stack:
            current, visited, length = stack.pop()
            max_length = max(max_length, length)

            for neighbor in friends[current]:
                if neighbor not in visited:
                    stack.append((neighbor, visited | set([neighbor]), length + 1))

    return max_length


# -----------------------------------------------------------------------------
# Question 5: Island Counter using DFS (Up/Down/Left/Right)
# -----------------------------------------------------------------------------
def island_count(grid):
    if not grid:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    visited = set()
    count = 0

    def neighbors(r, c):
        for dr, dc in [(0,1), (1,0), (-1,0), (0,-1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols:
                yield (nr, nc)

    for r in range(rows):
        for c in range(cols):
            if (r, c) not in visited and grid[r][c] == '1':
                stack = [(r, c)]
                while stack:
                    cr, cc = stack.pop()
                    if (cr, cc) in visited:
                        continue
                    visited.add((cr, cc))
                    for nr, nc in neighbors(cr, cc):
                        if (nr, nc) not in visited and grid[nr][nc] == '1':
                            stack.append((nr, nc))
                count += 1

    return count
