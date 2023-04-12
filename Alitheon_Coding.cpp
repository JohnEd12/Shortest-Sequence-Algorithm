// John Edgar
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Define the range of 4-digit codes
const int kNumCodes = 10000;

// Check if a code is a subsequence of a given number
bool is_subsequence(int code, int number) {
  while (code > 0 && number > 0) {
    if (code % 10 == number % 10) {
      code /= 10;
    }
    number /= 10;
  }
  return code == 0;
}

// Generate the shortest sequence of digits
string generate_sequence() {
  unordered_set<int> missing_codes;
  for (int code = 0; code < kNumCodes; ++code) {
    missing_codes.insert(code);
  }
  string sequence;
  for (int number = 0; !missing_codes.empty(); ++number) {
    for (std::unordered_set<int>::iterator it = missing_codes.begin(); it != missing_codes.end(); ++it) {
      int code = *it;
      if (is_subsequence(code, number)) {
        sequence += to_string(number);
        missing_codes.erase(code);
        break;
      }
    }
  }
  return sequence;
}

int main() {
  string sequence = generate_sequence();
  cout << sequence << endl;
  return 0;
}
