#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node
{
  int data;
  node *next, *prev;
};

void insert(node *L, node *R, node *M, int X) {
  node *newNode = new node;
  newNode->data = X;
  if (R == NULL) {
    newNode->next = NULL;
    newNode->prev = NULL;
    L = R = newNode;
    return;
  }
  if (M == L) {
    M->prev = newNode;
    newNode->next = M;
    newNode->prev = NULL;
    L = newNode;
    return;
  } else {
    newNode->next = M;
    newNode->prev = M->prev;
    M->prev = newNode;
    newNode->prev->next = newNode;
    return;
  }
}

void ddelete(node *L, node *R, node *M) {
  if (R = NULL) {
    return;
  }
  if (R = L) L = R = NULL;
  else if (M = L) {
    L = L->next;
    L->prev = NULL;
  } else if (M = R) {
    R = R->prev;
    R->next = NULL;
  } else {
    M->prev->next = M->next;
    M->next->prev = M->prev;
  }
  delete M;
  return;
}

int main() {
  
}