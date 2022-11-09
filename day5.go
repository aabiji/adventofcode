package main

import (
    "fmt"
    "strconv"
    "os"
    "strings"
)

// Part 1 -> How many steps until you leave maze using jump offsets? Answer: 358131
// Part 2 -> Same question, diffent rules. Answer: 25558839

func main() {
    file, _ := os.ReadFile("inputs/day5-inputs.txt")
    inputs := strings.Split(string(file), "\r\n")
    jump_offsets := []int{}
    for _, v := range inputs {
        int_v, _ := strconv.Atoi(v)
        jump_offsets = append(jump_offsets, int_v)
    }
    index := 0
    steps := 0
    part := 2

    for index < len(jump_offsets) && index >= 0 {
        prev_index := index
        index += jump_offsets[index]
        if part == 1 {
            jump_offsets[prev_index] += 1
        } else {

            if jump_offsets[prev_index] >= 3 {
                jump_offsets[prev_index] -= 1
            } else {
                jump_offsets[prev_index] += 1
            }

        }
        steps += 1
    }
    fmt.Println(steps)

}
