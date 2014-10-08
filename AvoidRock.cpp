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

int num_fences(int goal_length, int num_pieces, int N, int* segs) {
   if(num_pieces==0) {
      return (int)(goal_length==0);
   } // else, num_pieces >= 1:

   int base_length = 0;
   int num_fences_of_extra_length[100];
   for(int i = 0; i < 100; i++) {
      num_fences_of_extra_length[i] = num_segs_of_length[i];
   } num_pieces--;
   while(num_pieces > 0) {
      
   }
}

void main() {
   int K;
   cin >> segs.N, K;
   get_segment_lengths();
   count_segs_by_length();


   delete_segs();
   cin >> N;
}
