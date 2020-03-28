/*
Name: Ali Bokhari
ID: 0970498 / abokhari
Date: March 3, 2020
Assignment 3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 1024

void shiftTable(char *pattern, int table[]) {
  int m = strlen(pattern);
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = m;
  }
  for (int j = 0; j < m-1; j++) {
    table[(int)pattern[j]] = m-1-j;
  }
}

// int horspoolMatching(char *t, char *p) {
//   int i, k, n, m,totalMatches = 0;
//   int table[TABLE_SIZE];
//
//   shiftTable(p, table);
//   printf("done shirft\n");
//
//   i = strlen(p);
//   m = strlen(p);
//   n = strlen(t);
//   while (i <= n-1) {
//     k = 0;
//     while (k <= m-1 && p[m-1-k] == t[i-k]) {
//       k++;
//       printf("%d\n", k);
//     }
//     //printf("done first while\n");
//     if (k == m) {
//       //return i - m + 1;
//       totalMatches++;
//       //fprintf(stderr, "found one\n" );
//     }
//     i = i + table[(int)t[i]];
//
//   }
//   return totalMatches;
// }

void horspoolMatching(char *string, char *search, int total[]) {
   int j = 0, m, n, c, totalMatches=0, totalSwitches = 0;
   int table[TABLE_SIZE];

   shiftTable(search, table);

   m = strlen(search);
   n = strlen(string);

   while (j < n - m) {
      c = string[j + m - 1];
      if(c < 0){
            c++;
            c = string[c + m - 1];
      }
      if (search[m - 1] == c && memcmp(search, string + j, m - 1) == 0) {
        totalMatches++;
      }
      j = j + table[c];
      totalSwitches++;
   }
   total[0] = totalMatches;
   total[1] = totalSwitches;
}
