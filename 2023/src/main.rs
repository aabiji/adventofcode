#![allow(dead_code)]

mod day1;
mod day2;
mod day3;
mod day4;
mod utils;

fn main() {
    let answer = day3::compute_puzzle(1);
    println!("{}", answer);
}
