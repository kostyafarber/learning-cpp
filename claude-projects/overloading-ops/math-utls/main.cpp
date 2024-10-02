#include <format>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

class MathUtils {
public:
  vector<double> arr{};

  static double avg(vector<double> a) {
    return reduce(a.begin(), a.end()) / a.size();
  };

  vector<double> &operator+=(double i) {
    arr.push_back(i);
    return arr;
  };

  MathUtils() {};
  MathUtils(vector<double> a) { arr = a; };

  string to_string() const {
    ostringstream oss;
    oss << "[ ";

    for (auto n : arr) {
      oss << n << " ";
    }

    oss << "]";

    return oss.str();
  }
};

int main() {
  MathUtils m({1, 2, 3});
  auto avg = m.avg(m.arr);

  cout << format("Current array is: {}\n", m.to_string());
  cout << format("Average of 1, 2 and 3 is: {}\n", avg);

  m += 2;

  cout << format(
      "Testing += operator adding two to the array, array is now, {}\n",
      m.to_string());
}