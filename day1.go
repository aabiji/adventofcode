package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    data, _ := os.ReadFile("day1-inputs.txt")
    str := string(data)

    same_as_next := []int{}

    for i, c := range str {
        next_index := 0
        halfway := len(str) / 2
        // FOR PART 1
        //if (i + 1) <= len(str) - 1 {
        //    nextIndex = i + 1
        //}
        if ((i + halfway) <= len(str) - 1) {
            next_index = i + halfway
        } else {
            next_index = (i + halfway) - len(str)
        }

        int_val, _ :=  strconv.Atoi(string(c))
        next_int_val, _ := strconv.Atoi(string(str[next_index]))
        if int_val == next_int_val {
            same_as_next = append(same_as_next, int_val)
        }
    }
    fmt.Println( sum_arr(same_as_next) )
}

func sum_arr(arr []int) int {
    var sum int
    for _, i := range arr {
        sum += i
    }
    return sum
}

// Part 1 -> Sum of values in which the value in front of it is the same. Answer: 1047
// Part 2 -> Sum of values in which the value halfway in front is the same. Answer: 982
