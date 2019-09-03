// ---
// id         : 1025
// title      : PAT Ranking
// difficulty : Medium
// score      : 25
// tag        : Primary Algorithm
// keyword    : sort
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)

struct Testee {
  int score, local_num, local_rank, final_rank;
  long long id;

  bool operator<(const Testee& other) {
    return (score != other.score ? score > other.score : id < other.id);
  }
};

int main() {
  vector<Testee> ranklist;
  int n;
  scanf("%d", &n);
  for (int local_num = 1; local_num <= n; ++local_num) {
    vector<Testee> local_ranklist;
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      Testee t;
      t.local_num = local_num;
      scanf("%lld%d", &t.id, &t.score);
      local_ranklist.push_back(t);
    }
    std::sort(ALL(local_ranklist));
    local_ranklist[0].local_rank = 1;
    for (int i = 1; i < local_ranklist.size(); ++i) {
      if (local_ranklist[i].score == local_ranklist[i - 1].score)
        local_ranklist[i].local_rank = local_ranklist[i - 1].local_rank;
      else
        local_ranklist[i].local_rank = i + 1;
    }

    std::copy(ALL(local_ranklist), back_inserter(ranklist));
  }

  std::sort(ALL(ranklist));
  ranklist[0].final_rank = 1;
  for (int i = 1; i < ranklist.size(); ++i) {
    if (ranklist[i].score == ranklist[i - 1].score)
      ranklist[i].final_rank = ranklist[i - 1].final_rank;
    else
      ranklist[i].final_rank = i + 1;
  }

  printf("%d\n", ranklist.size());
  for (auto t : ranklist) {
    // PS:注意这个013lld 是最后一个case
    printf("%013lld %d %d %d\n", t.id, t.final_rank, t.local_num, t.local_rank);
  }
  return 0;
}