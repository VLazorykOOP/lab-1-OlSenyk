#include <iostream>
#include <vector>
using namespace std;

// Функція, що робить С з А і В
vector<int> makeC(vector<int> A, vector<int> B) {
  // Розміри масивів
  int N = A.size();
  int M = B.size();
  // Масив С
  vector<int> C(N+M);

  // Лічильники
  int i = 0, j = 0, k = 0;

  // Позитивні елементи А і В
  while (i < N && A[i] > 0) {
    C[k] = A[i];
    i = i + 1;
    k = k + 1;
  }
  while (j < M && B[j] > 0) {
    C[k] = B[j];
    j = j + 1;
    k = k + 1;
  }

  // Негативні елементи А і В
  while (i < N && A[i] < 0) {
    C[k] = A[i];
    i = i + 1;
    k = k + 1;
  }
  while (j < M && B[j] < 0) {
    C[k] = B[j];
    j = j + 1;
    k = k + 1;
  }
  return C;
}

// Функція, що друкує масив
void print(vector<int> arr) {
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  // Масиви А і В
  vector<int> A;
  vector<int> B;

  // Вводимо А і В
  cout << "Введіть А *5: ";
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    A.push_back(x);
  }
  cout << "Введіть В *5: ";
  for (int i = 0; i < 5; i++) {
    int x;
    cin >> x;
    B.push_back(x);
  }

  // Робимо С
  vector<int> C = makeC(A, B);

  // Друкуємо С
  cout << "С: ";
  print(C);

  return 0;
}