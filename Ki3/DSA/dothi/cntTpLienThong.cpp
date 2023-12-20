#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void inp() {
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(visited, false, sizeof(visited));
}

void dfs(int u) {
  cout << u << " ";
  visited[u] = true;
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

void bfs(int u) {
  queue<int> q;
  q.push(u);
  visited[u] = true;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    cout << v << " ";
    for (int x : adj[v]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = true;
      }
    }
  } 
}

void connectedComponent() {
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i]) {
      ++ans;
      cout << "Cac dinh thuoc tp lien thong thu " << ans << " ::: ";
      bfs(i);
      cout << endl;
    }
  }
  cout << "So thanh phan lien thong::: " << ans;
}

int main() {
  inp();
  connectedComponent();
}

// 10 8
// 1 2
// 2 3
// 2 4
// 3 6
// 6 7
// 3 7
// 5 8
// 8 9