package main

import (
	"fmt"
	"os"
	"strings"
)

func contained(slice string, match string) bool {
	for _, v := range slice {
		if match == string(v) {
			return true
		}
	}
	return false
}

func main() {
	file, _ := os.ReadFile("inputs/day3.txt")
	inputs := strings.Split(string(file), "\r\n")
	var matches []string


	// Part 2 
	for i := 0; i < len(inputs); i += 3 {
		match := ""
		for _, v := range inputs[i] {
			if contained(inputs[i + 1], string(v)) && contained(inputs[i + 2], string(v)) {
				match = string(v)
			}
		}
		matches = append(matches, match)
	}

	/*
	// Part 1
	for _, v := range inputs {
		match := ""
		half := len(v) / 2
		for i := 0; i < half; i++ {
			other_compartment := v[half: ]
			if contained(other_compartment, string(v[i])) {
				match = string(v[i])
			}
		}
		matches = append(matches, match)
	}
	*/

	var sum int
	for _, v := range matches {
		var priority int
		priority = int([]rune(v)[0]) - 96
		if strings.ToUpper(v) == v {
			priority = int([]rune(v)[0]) - 38
		}
		sum += priority
	}
	fmt.Println(sum)
}
