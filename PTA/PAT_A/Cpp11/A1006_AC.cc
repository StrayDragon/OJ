// ---
// id         : 1006
// title      : Sign In and Sign Out
// difficulty : Medium
// score      : 25
// tag        : Simple Simulation
// keyword    : minimax
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
#define ALL(x) begin(x), end(x)

struct Time {
  int hour, minute, second;
};

bool operator<(const Time& my, const Time& other) {
  return (my.hour != other.hour)
             ? my.hour < other.hour
             : (my.minute != other.minute) ? my.minute < other.minute
                                           : my.second < other.second;
}

istream& operator>>(istream& in, Time& time) {
  char _;
  return in >> time.hour >> _ >> time.minute >> _ >> time.second;
}

struct Person {
  string id;
  Time signin_time, signout_time;
};

int main() {
  int n;
  cin >> n;
  vector<Person> persons;
  for (Person t; n--;) {
    cin >> t.id >> t.signin_time >> t.signout_time;
    persons.push_back(t);
  }

  auto unlockitr =
      std::min_element(ALL(persons), [](const Person& lhs, const Person& rhs) {
        return lhs.signin_time < rhs.signin_time;
      });

  auto lockitr =
      std::max_element(ALL(persons), [](const Person& lhs, const Person& rhs) {
        return lhs.signout_time < rhs.signout_time;
      });

  cout << unlockitr->id << " " << lockitr->id << '\n';

  return 0;
}
