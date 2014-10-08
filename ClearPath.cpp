#include <iostream>
using namespace std;

#define TIME_BOUND (100*100*100)
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
         travel_times[i][j] = TIME_BOUND+1;
      }
   }
} void delete_array(int** arr) {
   for(int i = 0; i < M; i++) {
      delete arr[i];
   }
   delete[] arr;
}

int get_cost(int i, int j) {
   if(!(0<=i && i<M && 0<=j && j<N)) {
      return TIME_BOUND;
   } return travel_times[i][j]; 
   heights[i][j] - 1; // since want to level to 1.
}
int revised_time(int i, int j) {
   int min = travel_times[i][j];
   for(int y = i-1; y < i+1; y++) {
      for(int x = j-1; x < j+1; x++) {
         int cost = get_cost(x, y);
         min = MIN(min, cost);
      }
   } return min;
}
void fill_() {
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         travel_times[i][j] = revised_time(i, j);
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
