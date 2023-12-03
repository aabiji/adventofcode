use regex::Regex;
use std::collections::HashMap;

pub fn compute_puzzle(part: u32) -> i32 {
    let inputs = crate::utils::read_inputs("inputs/day1.txt");
    let mut answer: i32 = 0;

    let mut pattern = String::from("[0-9]");
    let numbers = HashMap::from([
        ("one", "1"), ("two", "2"), ("three", "3"), ("four", "4"), ("five", "5"),
        ("six", "6"), ("seven", "7"), ("eight", "8"), ("nine", "9")
    ]);

    if part == 2 {
        pattern += &String::from("|one|two|three|four|five|six|seven|eight|nine|ten");
    }

    let re = Regex::new(&pattern).unwrap();
    for line in inputs {

        let mut last_match = "";
        let mut first_match = "";

        for i in 0..line.len() {
            let end = if i + 5 < line.len() { i + 5 } else { line.len() };
            let window = &line[i..end];
            let matches: Vec<&str> = re.find_iter(&window).map(|s| s.as_str()).collect();

            if matches.len() == 0 {
                continue;
            }

            if first_match == "" {
                first_match = matches[0];
            }

            last_match = matches[matches.len() - 1];
        }

        if first_match.len() > 1 {
            first_match = numbers[first_match];
        }

        if last_match.len() > 1 {
            last_match = numbers[last_match];
        }


        let score = (first_match.parse::<u32>().unwrap() * 10) + last_match.parse::<u32>().unwrap();
        answer += score as i32;
     }

     answer
}