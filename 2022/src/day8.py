
inputs = open("../inputs/day8.txt", "r").read().split("\n")
grid = [[int(x) for x in line] for line in inputs]

WIDTH, HEIGHT = len(grid[0]), len(grid)
visible = 2 * (WIDTH + HEIGHT) - 4

def sscore(x: int, y: int) -> int:
    global WIDTH, HEIGHT, grid
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    tree = grid[y][x]
    score = 1

    for d in directions:
        t_x = x + d[0]
        t_y = y + d[1]
        count = 0

        while t_x >= 0 and t_x < WIDTH and t_y >= 0 and t_y < HEIGHT:
            count += 1
            t = grid[t_y][t_x]
            t_x += d[0]
            t_y += d[1]
            if t >= tree:
                break
    
        score *= count
    
    return score

scenic_scores = []
for y in range(1, HEIGHT - 1):
    for x in range(1, WIDTH - 1):
        scenic_scores.append(sscore(x, y))

print(scenic_scores)
print(max(scenic_scores))
