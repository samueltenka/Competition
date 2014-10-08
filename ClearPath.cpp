#include <iostream>
using namespace std;

#define MIN(A, B) ((A)<(B) ? (A) : (B))

int M, N;
int** heights;
void new_heights() {
   heights = new int*[M];
   for(int i = 0; i < M; i++) {
      heights[i] = new int[N];
   }
} void get_heights() {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> heights[i][j];
      }
   }
} void delete_heights() {
   for(int i = 0; i < M; i++) {
      delete heights[i];
   }
   delete[] heights;
}

void main() {
   int M, N;
   cin >> M, N;
   int* cards = new int[N];
   get_cards(N, cards);
   cout << count_flips(N, cards);
   delete[] cards;
} // TODO: find clever way!
