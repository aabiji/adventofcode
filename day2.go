package main

import (
    "fmt"
    "os"
    "strings"
    "strconv"
)

func row_min_max(row []string) (int, int) {
    var min int = 1000
    var max int = 0
    for _, v := range row {
        val, _ := strconv.Atoi(v)
        if val > max {
            max = val
        }
        if val < min {
            min = val
        }
    }
    return min, max
}

func row_div(row []string) int {
    var dividend int = 0
    var stop bool = false

    for y, _ := range row {

        x := y

        for i := 0; i < len(row) - 1; i++ {
            if (x + 1 < len(row)) {
                x = x + 1
            } else {
                x = 0
            }

            val, _ := strconv.Atoi(row[y])
            check, _ := strconv.Atoi(row[x])
            dividend = val / check

            if ((val % check) == 0) {
                stop = true
                break
            }
        }

        if stop {
            break
        }

    }

    return dividend
}

func main() {
    data, _ := os.ReadFile("day2-inputs.txt")
    spreadsheet := strings.Split(string(data), "\r\n")
    var checksum int = 0

    for _, line := range spreadsheet {
        row := strings.Fields(line)
        //min, max := row_min_max(row)
        //checksum += max - min
        checksum += row_div(row)
    }  

    fmt.Println(checksum)
}

// Part 1 -> Checksum of the spreadsheet? Answer: 53978
// Part 2 -> Different check, same thing. Answer: 314