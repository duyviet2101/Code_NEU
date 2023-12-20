#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> adj[1000];
int a[1001][1001];
//! adj[i] Lưu danh sách kề đỉnh i
vector<pair<int, int>> edge;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
    {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 1 && i < j) {
        edge.push_back({i, j});
      }
    }
  }
  for (auto it : edge) {
    cout << it.first << " " << it.second << endl;
  }
}