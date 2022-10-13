#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long sumn2(long long v) {
  return v * (v + 1) * (2 * v + 1) / 6;
}

int main() {
  int N; cin >> N;
  vector<long long> A(N);

  int c = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    c = max(0ll, c + A[i] - 1);
  }
    cout << c << "\n";
  for (int i = 0; ; i++) {
    if (c == 0) {
      rotate(A.begin(), A.begin() + i, A.begin() + N);
      for (int a : A) {
        cout << a << " ";
      }
      cout << "\n";
      break;
    }
    c = max(0ll, c + A[i] - 1);
  }

    cout << c << "\n";
  long long result = 0;
  for (int i = 0; i < N; i++) {
    result += sumn2(A[i] + c - 1) - sumn2(c - 1);
    cout << A[i] + c - 1 << " " << c - 1 << "\n";
    c = max(0ll, c + A[i] - 1);
  }
  cout << result << endl;
}