#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> vect;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    vect.push_back(make_pair(i, a));
  }
  sort(vect.begin(), vect.end());

  sort(vect.begin(), vect.end(), sortbysec);

  int temp = vect[0].second;
  int max = 5 - (temp % 5) + temp;

  if (vect[0].second == 2) {
    cout << n << " " << endl;
  int max = 2;
    cout << "1 " << 0<< endl;
    for (int i = 1; i < n; i++) {
      if (vect[i].second <= max) {
        cout << i + 1 << " " << max - vect[i].second << endl;
      } else {
        if (vect[i].second < max * 2) {
          int p = max * 2 - vect[i].second;
          cout << i + 1 << " " << p << endl;
          max = max * 2;
        }
        if (vect[i].second > max * 2) {
          int p = 2 - (temp % 2);
          cout << i + 1 << " " << p << endl;
        }
      }
    }
  } else {
    cout << n << " " << endl;
    cout << "1 " << 5 - (temp % 5) << endl;
    for (int i = 1; i < n; i++) {
      if (vect[i].second <= max) {
        cout << i + 1 << " " << max - vect[i].second << endl;
      } else {
        if (vect[i].second < max * 2) {
          int p = max * 2 - vect[i].second;
          cout << i + 1 << " " << p << endl;
          max = max * 2;
        }
        if (vect[i].second > max * 2) {
          int p = 5 - (temp % 5);
          cout << i + 1 << " " << p << endl;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
