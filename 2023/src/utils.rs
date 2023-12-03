
pub fn read_inputs(filename: &str) -> Vec<String> {
    let file_contents = std::fs::read_to_string(filename).unwrap();
    file_contents.to_owned().lines().map(String::from).collect()
}