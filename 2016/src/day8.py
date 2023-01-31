WIDTH = 50
HEIGHT = 6
grid = [[0] * WIDTH for i in range(HEIGHT)]

def rect(grid: list, width: int, height: int):
    for y in range(0, height):
        for x in range(0, width):
            grid[y][x] = 1

def horizantal_rotate(grid: list, row: int, offset: int):
    ring = []
    temp_row = [i for i in grid[row]]

    for i in range(WIDTH):
        new_index = i + offset

        if new_index >= WIDTH:
            ring.append(temp_row[i])
            continue
        
        grid[row][new_index] = temp_row[i]
        
    for i in range(len(ring)):
        grid[row][i] = ring[i]

def vertical_rotate(grid: list, column: int, offset: int):
    ring = []
    temp_column = [grid[i][column] for i in range(HEIGHT)]

    for i in range(HEIGHT):
        new_index = (i + offset)
        
        if new_index >= HEIGHT:
            ring.append(temp_column[i])
            continue
        
        grid[new_index][column] = temp_column[i]

    for i in range(len(ring)):
        grid[i][column] = ring[i]

if __name__ == '__main__':
    calls = [i for i in open("../inputs/day8.txt", "r").read().split("\n") if i != ""]
    for i in calls:
        i = i.split(" ")
        if i[0] == "rect":
            dimensions = i[1].split("x")
            rect(grid, int(dimensions[0]), int(dimensions[1]))
        elif i[0] == "rotate":
            axis = int(i[2].split("=")[1])
            offset = int(i[4])
            
            if i[1] == "row":
                horizantal_rotate(grid, axis, offset)
            else:
                vertical_rotate(grid, axis, offset)
        
    lit_count = 0
    for y in range(HEIGHT):
        print()
        for x in range(WIDTH):
            pixel = "#" if grid[y][x] == 1 else " "
            if grid[y][x] == 1:
                lit_count += 1
            print(pixel, end="")

    print(lit_count)
