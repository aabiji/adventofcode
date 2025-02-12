/*
Example:

2333133121414131402

The index (in the input sequence) encodes the type (even index for block,
odd index for space) We want to go right to left, moving blocks into free spaces

last_even_index = length is odd ? length - 1 : length;
last_even_index -= 2
*/