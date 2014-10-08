#include <iostream>
using namespace std;

#define MIN(A, B) ((A)<(B) ? (A) : (B))


int K;
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

void count_segs_by_length(int* segs_of_length) {
   for(int length = 0; length < 101; length++) {
      segs_of_length[length] = 0;
   } for(int i = 0; i < segs.N; i++) {
      segs_of_length[segs.lengths[i]] += 1;
   }
}
void kill_fences_on_rock(int base_length, int* fences_dl_longer) {
   int dl = K-base_length;
   if(0<=dl && dl<100) {
      fences_dl_longer[dl] = 0;
   }
}

int count_fences() {
   int pieces_left = segs.N;
   int base_length = 1;
   int fences_dl_longer[100]; // `fences_dl_longer[dl]` = num. fences of length `base_length+dl`
   for(int i = 0; i < 100; i++) {
      fences_dl_longer[i] = 0;
   }

   do {
      for(int i = 0; i < segs.N; i++) {
         segs_of_length[segs.lengths[i]] += 1;
      }
      
      pieces_left -= 1;
      kill_fences_on_rock(base_length, fences_dl_longer);
   } while(pieces_left > 0);
}

void main() {
   int K;
   cin >> segs.N, K;
   get_segment_lengths();
   count_segs_by_length();


   delete_segs();
   cin >> N;
}
