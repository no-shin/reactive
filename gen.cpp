#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Usage: gen testcase_id\n";
    return 1;
  }

  int id = stoi(argv[1]);

  // idを使えばケースごとに内容を変えられる
  // [1, 100] の整数（両端を含む）
  uniform_int_distribution<int> dist(1, 100);

  // 他の型の場合:
  //
  // long long: 型を変えるだけ。ただし 2^32 を超える範囲なら rng を mt19937_64 にする
  //   uniform_int_distribution<long long> dist_ll(1, 1'000'000'000'000'000'000LL);
  //
  // double: uniform_real_distribution を使う。範囲は [a, b)（b は含まない）
  //   uniform_real_distribution<double> dist_d(0.0, 1.0);
  //
  // char: <char> は使えない（未定義動作）ので int で生成してキャストする
  //   uniform_int_distribution<int> dist_c('a', 'z');
  //   char c = (char)dist_c(rng);
  //
  // bool: bernoulli_distribution(p) で確率 p で true
  //   bernoulli_distribution dist_b(0.5);
  //
  // 文字列: 1文字ずつ生成して足す
  //   string s;
  //   for (int i = 0; i < n; i++) s += (char)dist_c(rng);
  //
  // 配列の中から1つ選ぶ: 添字を生成する
  //   uniform_int_distribution<int> dist_i(0, (int)v.size() - 1);
  //   auto x = v[dist_i(rng)];
  //
  // 順列: iota で並べて shuffle
  //   vector<int> p(n);
  //   iota(p.begin(), p.end(), 1);
  //   shuffle(p.begin(), p.end(), rng);
  //
  // 同じ範囲で何度も使うなら dist は1回作って dist(rng) を繰り返し呼べばよい

  cout << dist(rng) << '\n';
}
