/*
Name: Ali Bokhari
ID: 0970498 / abokhari
Date: March 21, 2020
Assignment 4
*/

#include "head.h"

int sum(Node **array, int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += array[k]->freq;
    return s;
}

int** optimalSearchTree(Node **array, int n)
{
    int *c = calloc(n*n, sizeof(int));
    int *r = calloc(n*n, sizeof(int));

    for (int i = 0; i < n; i++) {
      c[i*n + i] = array[i]->freq;
      r[i*n + i] = i;
    }

    for (int d=2; d<=n; d++) {
        for (int i=0; i<n-d+1; i++) {
            int j = i+d-1;
            c[i*n + j] = 2147483647;
            for (int k=i; k<=j; k++) {
               int cost = 0;
               if (k > i) {
                 cost += c[i*n + k-1];
               }
               if (k < j) {
                 cost += c[((k+1)*n) + j];
               }
               cost += sum(array, i, j);

               if (cost < c[i*n + j]) {
                 r[i*n + j] = k;
                 c[i*n + j] = cost;
               }
            }
        }
    }
    //print2D(r, n);
    int **re = malloc(sizeof(int*) * 2);
    re[0]=c;
    re[1]=r;
    return re;
}

// int sum(int freq[], int i, int j)
// {
//     int s = 0;
//     for (int k = i; k <=j; k++)
//        s += freq[k];
//     return s;
// }
//
// int** optimalSearchTree(int keys[], int freq[], int n)
// {
//     int *c = calloc(n*n, sizeof(int));
//     int *r = calloc(n*n, sizeof(int));
//
//     for (int i = 0; i < n; i++) {
//       c[i*n + i] = freq[i];
//       r[i*n + i] = i+1;
//     }
//
//     for (int d=2; d<=n; d++) {
//         for (int i=0; i<n-d+1; i++) {
//             int j = i+d-1;
//             c[i*n + j] = 2147483647;
//             for (int k=i; k<=j; k++) {
//                int cost = 0;
//                if (k > i) {
//                  cost += c[i*n + k-1];
//                }
//                if (k < j) {
//                  cost += c[((k+1)*n) + j];
//                }
//                cost += sum(freq, i, j);
//
//                if (cost < c[i*n + j]) {
//                  r[i*n + j] = k+1;
//                  c[i*n + j] = cost;
//                }
//             }
//         }
//     }
//     //print2D(r, n);
//     int **re = malloc(sizeof(int*) * 2);
//     re[0]=c;
//     re[1]=r;
//     return re;
// }
