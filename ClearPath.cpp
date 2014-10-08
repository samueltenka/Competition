#include <iostream>
using namespace std;

#define MIN(A, B) ((A)<(B) ? (A) : (B))

int M, N;
int** heights;
int** travel_times;
int** new_array() {
   int** arr = new int*[M];
   for(int i = 0; i < M; i++) {
      arr[i] = new int[N];
   }
} void init_arrays() {
   cin >> M, N;
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         cin >> heights[i][j]; 
         travel_times[i][j] = 101;
      }
   }
} void delete_array(int** arr) {
   for(int i = 0; i < M; i++) {
      delete arr[i];
   }
   delete[] arr;
}

void revised_time(int i, int j) {
   return 
}
void fill_() {
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         cin >> heights[i][j];
      }
   }
} // Strategy: dynamic programming :)

void main() {
   heights = new_array();
   travel_times = new_array();
   init_arrays();

   cout << heights[M-1][N-1];

   delete_array(travel_times);
   delete_array(heights);
}
