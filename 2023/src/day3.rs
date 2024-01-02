
fn in_bounds(x: i32, y: i32, w: usize, h: usize) -> bool {
    if x < 0 || x as usize >= w {
        return false;
    }

    if y < 0 || y as usize >= h {
        return false;
    }

    return true;
}

fn scan_num(grid: &Vec<String>, x: i32, y: i32) -> Option<u32> {
    if !in_bounds(x, y, grid.len(), grid[y as usize].len()) {
        return None;
    }

    let mut i = x - 1;
    let mut left_num_str = String::new();
    while in_bounds(i, y, grid.len(), grid[y as usize].len()) {
        let c = grid[y as usize].chars().nth(i as usize).unwrap();
        if !c.is_digit(10) {
            break;
        }
        left_num_str += &format!("{}", c);
        i -= 1;
    }

    i = x + 1;
    let mut right_num_str = String::new();
    while in_bounds(i, y, grid.len(), grid[y as usize].len()) {
        let c = grid[y as usize].chars().nth(i as usize).unwrap();
        if !c.is_digit(10) {
            break;
        }
        right_num_str += &format!("{}", c);
        i += 1;
    }

    left_num_str = left_num_str.chars().rev().collect::<String>();
    let num_str = format!("{}{}{}", left_num_str, grid[y as usize].chars().nth(x as usize).unwrap(), right_num_str);
 
    if let Ok(n) = num_str.parse::<u32>() {
        return Some(n);
    }

    return None;
}

fn find_adjacent_nums(grid: &Vec<String>, x: i32, y: i32) -> u32 {
    let mut nums: Vec<u32> = Vec::new();

    for line in y-1..y+2 {
        if let Some(n) = scan_num(&grid, x, line) {
            nums.push(n);
            continue;
        }

        if let Some(n) = scan_num(&grid, x - 1, line) { 
            nums.push(n);
        }

        if let Some(n) = scan_num(&grid, x + 1, line) {
            nums.push(n);
        }
    }

    // part 1: return nums.iter().sum();
    if nums.len() == 2 {
        return nums[0] * nums[1];
    } else {
        return 0;
    }
}

pub fn compute_puzzle(_part: i32) -> u32 {
    let lines = crate::utils::read_input_file("inputs/day3.txt");
    let mut total = 0;

    for y in 0..lines.len() {
        for x in 0..lines[y].len() {
            let c = lines[y].chars().nth(x).unwrap();
            if c == '*' { // part 1: c.is_punctuation() && c != '.'
                let n = find_adjacent_nums(&lines, x as i32, y as i32);
                total += n;
            }
        }
    }

    return total; 
}
