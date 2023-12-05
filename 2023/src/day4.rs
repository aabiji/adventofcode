use std::collections::HashMap;

pub fn compute_puzzle(part: i32) -> i32 {
    let inputs = crate::utils::read_input_file("inputs/day4.txt");
    let mut answer = 0;

    for line in inputs {
        let num_list = crate::utils::split_string(&line, ": ")[1];
        let numbers = crate::utils::split_string(&num_list, "|");
        let winning_numbers = crate::utils::split_string(&numbers[0], " ");
        let my_numbers = crate::utils::split_string(&numbers[1], " ");

        let mut winning: HashMap<i32, i32> = HashMap::new();
        for num in winning_numbers {
            if let Ok(n) = num.parse::<i32>() {
                winning.insert(n, 0);
            }
        }

        let mut point = 0;
        for num in my_numbers {
            if let Ok(n) = num.parse::<i32>() {
                if winning.contains_key(&n) {
                    if point == 0 { point = 1; } else { point *= 2; }
                }
            }
        }

        answer += point;
    }

    answer
}
