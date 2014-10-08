#include <iostream>
using namespace std;

#define MIN(A, B) ((A)<(B) ? (A) : (B))


struct {
   int N;
   int* lengths;
} segs;
void get_segment_lengths() {
   segs.lengths = new int[segs.N];
   for(int i = 0; i < segs.N; i++) {
      cin >> segs[i];
   }
} void delete_segs() {
   delete[] segs.lengths;
}

int num_segs_of_length[100];
void count_segs_by_length() {
   for(int length = 0; length < 100; length++) {
      num_segs_of_length[length] = 0;
   } for(int i = 0; i < segs.N; i++) {
      num_segs_of_length[segs.lengths[i]] += 1;
   }
}

int num_fences_helper(int goal_length, int goal_num_pieces) {
   if(goal_num_pieces == 1) {
      for(int N = 0;)
   }
}
int num_fences(int length, int num_pieces, int N, int* segs) {

}

void main() {
   int K;
   cin >> segs.N, K;
   get_segment_lengths();
   count_segs_by_length();


   delete_segs();
   cin >> N;
}
