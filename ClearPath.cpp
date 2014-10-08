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
   cin >> M, N;
   for(int i = 0; i < M; i++) {
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

void fill_heights() {

} // Strategy: dynamic programming :)

void main() {
   new_heights();
   get_heights();
   fill_heights();
   cout << heights[M-1][N-1];
   delete_heights();
}
