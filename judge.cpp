#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Usage: ./judge input.txt\n";
    return 1;
  }

  ifstream fin(argv[1]);

  int secret;
  fin >> secret;
  const int LIMIT = 20; // 最大20回

  cout << LIMIT << endl;
  cout.flush();

  for (int i = 0; i < LIMIT; i++) {
    int x;
    if (!(cin >> x))
      return 1; // 答えずに solve が終了した

    if (x == secret) {
      cout << "CORRECT" << endl;
      cout.flush();
      return 0;
    } else if (x < secret) {
      cout << "HIGHER" << endl;
    } else {
      cout << "LOWER" << endl;
    }
    cout.flush();
  }

  cout << "FAILED" << endl;
  cout.flush();
  return 1; // 不正解は 0 以外で終了する
}
