#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
int a[1001][1001];

int main() {
  // ! nhập n, m là số đỉnh, số cạnh của đồ thị
  // ! m dòng tiếp theo là nhập dạng danh sách cạnh
  // ? Đầu| Cuối
  // ?   1|   2
  // ?   1|   3
  // ?   2|   3
  // ?   2|   4
  // ! đầu ra là ma trận kề của đồ thị
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}