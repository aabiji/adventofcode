#include <algorithm>
#include <cmath>
#include "lib.h"

int main() {
  /*
  std::vector<long> nums = split_num<long>(read_file("inputs/day9.txt"), "");
  long checksum = 0;

  long empty_index = 1;

  long block_index = nums.size() - 1;
  long block_id = ceil((float)nums.size() / 2) - 1;

  long checksum_index = nums[0];
  long checksum_length = 0; // only account for blocks, not spaces
  for (long i = 0; i < nums.size(); i += 2) {
    checksum_length += nums[i];
  }

  while (checksum_index < checksum_length) {
    // move blocks into the empty spaces
    while (nums[block_index] > 0 && nums[empty_index] > 0) {
      nums[empty_index]--;
      nums[block_index]--;
      checksum += block_id * checksum_index;
      checksum_index++;
    }

    // update the checksum and move on to the next empty space
    if (nums[empty_index] == 0) {
      long _block_id = (empty_index + 1) / 2;
      for (long i = 0; i < nums[empty_index+1]; i++) {
        checksum += checksum_index * _block_id;
        checksum_index++;
      }
      empty_index += 2;
    }

    // move to the next block
    if (nums[block_index] == 0) {
      block_index -= 2;
      block_id--;
    }
  }

  std::cout << checksum << "\n";
  */

  // Part 2
  std::vector<long> nums = split_num<long>(read_file("inputs/day9.txt"), "");
  long checksum = 0, index = 0, file_id = 0;
  std::vector<std::tuple<long, long, long>> files; // (id, size, position)
  std::vector<std::pair<long, long>> spaces;

  for (long i = 0; i < nums.size(); i += 2) {
    files.emplace_back(file_id++, nums[i], index);
    if (i + 1 < nums.size() && nums[i + 1] > 0)
      spaces.emplace_back(index + nums[i], nums[i + 1]);
    index += nums[i] + (i + 1 < nums.size() ? nums[i + 1] : 0);
  }

  std::sort(files.rbegin(), files.rend());

  for (auto &[id, size, pos] : files) {
    for (auto &[start, length] : spaces) {
      if (length >= size && start < pos) {
        pos = start;
        start += size;
        length -= size;
        break;
      }
    }
  }

  for (const auto &[id, size, pos] : files)
    for (long i = 0; i < size; i++)
      checksum += id * (pos + i);

  std::cout << checksum << "\n";
}