
#[derive(PartialEq)]
enum Direction { Left, Right }

fn search_number(matrix: &Vec<String>, x: usize, y: usize, dir: Direction) -> String {
    let mut i = x as i32;
    let row_len = matrix[y].len() as i32;
    let mut result = String::new();
    let mut c = matrix[y].chars().nth(x).unwrap();

    while i >= 0 && i < row_len && !c.is_ascii_punctuation() {
        result += &c.to_string();

        if dir == Direction::Left { i -= 1; } else { i += 1; };
        if i < 0 || i == row_len { break; }

        c = matrix[y].chars().nth(i as usize).unwrap();
    }

    if dir == Direction::Left {
        result = result.chars().rev().collect();
    }

    result
}

fn str_to_int(string: &str) -> i32 {
    match string.parse::<i32>() {
        Ok(val) => val,
        Err(_) => 0
    }
}

fn get_surrounding_numbers(matrix: &Vec<String>, x: usize, y: usize) -> (i32, i32) {
    let start_y = if y > 0 { y - 1 } else { 0 };
    let end_y = if y < matrix.len() { y + 1 } else { y };

    let mut sum = 0;
    let mut ratio = 1;
    let mut adjacency_count = 0;

    for i in start_y..=end_y {
        let c = matrix[i].chars().nth(x).unwrap();
        let left  = search_number(matrix, x - 1, i, Direction::Left);
        let right = search_number(matrix, x + 1, i, Direction::Right);
        let full = &(left.clone() + &c.to_string() + &right);

        if left.len() > 0 {
            adjacency_count += 1;
        }
        if right.len() > 0 {
            adjacency_count += 1;
        }

        if i != y && c == '.' || y == i {
            let lval = str_to_int(&left);
            let rval = str_to_int(&right);
            sum += lval + rval;

            if lval > 0 { ratio *= lval }
            if rval > 0 { ratio *= rval }
        } else {
            let num = str_to_int(full);
            sum += num;

            if num > 0 { ratio *= num }
        }
    }

    println!("{} {} {}", matrix[y].chars().nth(x).unwrap(), ratio, adjacency_count);

    if adjacency_count != 2 {
        ratio = 0
    }
    (ratio, sum)
}

// get all the symbols, then find all the surrounding numbers
pub fn compute_puzzle(part: i32) -> i32 {
    let inputs = crate::utils::read_input_file("inputs/day3.txt");
    let mut answer = 0;

    let mut y = 0;
    for line in &inputs {
        let mut x = 0;
        while x < line.len() {
            let c = line.chars().nth(x).unwrap();
            if c.is_ascii_punctuation() && c != '.' {
                let (ratio, sum) = get_surrounding_numbers(&inputs, x, y);
                answer += if part == 1 { sum } else { ratio }
            }
            x += 1;
        }
        y += 1;
    }

    answer
}
