#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
  string hoten;
  int tuoi;
  Node *next;
};

void addNode(Node *L, Node *M, string hoten, int tuoi) {
  if (L == NULL) {
    L = new Node;
    L->hoten = hoten;
    L->tuoi = tuoi;
    L->next = NULL;
  } else {
    Node *newNode = new Node;
    newNode->hoten = hoten;
    newNode->tuoi = tuoi;
    newNode->next = NULL;

    newNode->next = M->next;
    M->next = newNode;
  }
}

void deleteNode(Node *L, Node *M) {
  if (L == NULL) {
    cout << 'Danh sach rong' << endl;
    return;
  } else {
    if (L == M) {
      L = L->next;
      delete M;
    } else {
      Node *p = L;
      while (p->next != M) {
        p = p->next;
      }
      p->next = M->next;
      delete M;
    }
  }
}

int countNode (Node *L) {
  if (L == NULL) return 0;
  int cnt = 0;
  Node *p = L;
  while (p != NULL) {
    cnt ++;
    p = p->next;
  }
  return cnt;
}

void concatList(Node *P, Node *Q) {
  if (Q == NULL) return;
  if (P == NULL) {
    P = Q;
    return;
  }
  Node *R = P;
  while (R->next != NULL) {
    R = R->next;
  }
  R->next = Q;
  return;
}
 

int main() {
  Node *L = new Node;
  Node *p = L;
  p->hoten = "Nguyen Van A";
  p->tuoi = 20;
  p->next = new Node;

  p = p->next;
  p->hoten = "Nguyen Van B";
  p->tuoi = 21;
  p->next = new Node;

  p = p->next;
  p->hoten = "Nguyen Van C";
  p->tuoi = 22;
  p->next = NULL;

  p = L;
  while (p != NULL)
  {
    cout << p->hoten << " " << p->tuoi << endl;
    p = p->next;
  }
  
}