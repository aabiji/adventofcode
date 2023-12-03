
pub fn read_input_file(filename: &str) -> Vec<String> {
    let file_contents = std::fs::read_to_string(filename).unwrap();
    file_contents.to_owned().lines().map(String::from).collect()
}

pub fn split_string<'a>(string: &'a str, delim: &'a str) -> Vec<&'a str> {
    string.split(delim).collect::<Vec<&str>>()
}

