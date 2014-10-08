#include <iostream>
using namespace std;

#define TIME_BOUND (100*100*100)
#define MIN(A, B) ((A)<(B) ? (A) : (B))

int M, N;
int heights[5][5] = {{1, 1, 1, 1, 1},
                 {9, 9, 9, 9, 1},
                 {1, 3, 3, 3, 1}, 
                 {1, 9, 9, 9, 9},
                 {1, 1, 1, 1, 1}};
int** times; // time to clear all cells on best path up to, 
                    // but not including, [i][j].
int** new_array() {
   int** arr = new int*[M];
   for(int i = 0; i < M; i++) {
      arr[i] = new int[N];
   } return arr;
} void get_heights() {
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         cin >> heights[i][j];
      }
   }
} void init_times() {
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         times[i][j] = TIME_BOUND;
      }
   } times[0][0] = 0; // crucial!
} void delete_array(int** arr) {
   for(int i = 0; i < M; i++) {
      delete arr[i];
   }
   delete[] arr;
}

/* Strategy: dynamic programming :)
*/
int get_cost_thru(int i, int j) {
   if(!(0<=i && i<M && 0<=j && j<N)) {
      return TIME_BOUND;
   } return (heights[i][j]-1) + times[i][j]; // since want to level to 1.
}
int revised_time(int i, int j) {
   int min = times[i][j];
   for(int y = i-1; y <= i+1; y++) {
      for(int x = j-1; x <= j+1; x++) {
         if((x+y)%2==0) {continue;} // neat way of getting only orthogonal neighbors.
         int cost = get_cost_thru(x, y);
         //cout << cost << ".";
         min = MIN(min, cost);
      }
   } /*cout << endl;*/ return min;
}
bool update_times() { // returns whether or not anything changed
   bool changed = false;
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         int old = times[i][j];
         times[i][j] = revised_time(i, j);
         changed = changed || (old != times[i][j]);
      }
   } return changed;
}
void print() {
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         cout << times[i][j] << "\t";
      } cout << endl;
   } cout << endl;
   for(int i = 0; i < M; i++) {
      for(int j = 0; j < N; j++) {
         cout << heights[i][j] << "\t";
      } cout << endl;
   } cout << endl;
}
int find_best_time() {
   while(update_times()) {
      cout << "!" << endl;
      print();
   } return get_cost_thru(M-1, N-1);;
}

void main() {
   cin >> M >> N;
   //heights = new_array();
   times = new_array();
   //get_heights();
   init_times();

   cout << find_best_time();

   delete_array(times);
   //delete_array(heights);

   cin >> M;
}
