#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> adj[1000];
//! adj[i] Lưu danh sách kề đỉnh i
int a[1001][1001];

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
      if (a[i][j] == 1) {
        adj[i].push_back(j);
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << i << " : ";
    for (int x : adj[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
  
}