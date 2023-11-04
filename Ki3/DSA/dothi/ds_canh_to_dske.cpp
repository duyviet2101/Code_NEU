#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
vector<int> adj[1000];
// ! adj[i] luư danh sách kề của đỉnh i

int main() {
  // ! nhập n, m là số đỉnh, số cạnh của đồ thị
  // ! m dòng tiếp theo là nhập dạng danh sách cạnh
  // ? Đầu| Cuối
  // ?   1|   2
  // ?   1|   3
  // ?   2|   3
  // ?   2|   4
  // ! đầu ra là danh sách kề của đồ thị
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " : ";
    for (int x : adj[i]) {
      cout << x << " ";
    }
    cout << endl;
  }

}