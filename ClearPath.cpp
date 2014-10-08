#include <iostream>
using namespace std;

#define TIME_BOUND (100*100*100)
#define MIN(A, B) ((A)<(B) ? (A) : (B))

int M, N;
int** heights;
int** times; // time to clear all cells on best path up to, 
                    // but not including, [i][j].
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
         times[i][j] = TIME_BOUND;
      }
   }
} void delete_array(int** arr) {
   for(int i = 0; i < M; i++) {
      delete arr[i];
   }
   delete[] arr;
}

/* Strategy: dynamic programming :)
*/
int get_cost_of_clearing(int i, int j) {
   if(!(0<=i && i<M && 0<=j && j<N)) {
      return TIME_BOUND;
   } heights[i][j] - 1; // since want to level to 1.
}
int revised_time(int i, int j) {
   int min = times[i][j];
   for(int y = i-1; y < i+1; y++) {
      for(int x = j-1; x < j+1; x++) {
         if((x+y)%2==0) {continue;} // neat way of getting only orthogonal neighbors.
         int cost = get_cost_of_clearing(x, y) + times[x][y];
         min = MIN(min, cost);
      }
   } return min;
}
bool update_times() { // returns whether or not changed anything
   bool changed = false;
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         int old = times[i][j];
         times[i][j] = revised_time(i, j);
         if(old != times[i][j]) {
            changed = true;
         }
      }
   } return changed;
}

void main() {
   heights = new_array();
   times = new_array();
   init_arrays();

   cout << heights[M-1][N-1];

   delete_array(times);
   delete_array(heights);
}
