/*
Name: Ali Bokhari
Date: March 21, 2019
*/

#include "head.h"

int sum(Node **array, int i, int j) {
    int s = 0;
    for (int k = i; k <=j; k++)
       s += array[k]->freq;
    return s;
}

int** OptimalBST(Node **array, int n) {
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
                 //printf("%s\n", array[k]->word);
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

Node *buildTree(int *re, int *c, Node **array, int size, int i, int j) {
  if (i > size) {
    printf("oof\n");
  }
  if (i > j) {
    return NULL;
  }
  if (i==j) {
    Node *retu = array[re[i*size + j]];
    retu->avg = c[i*size + j];
    retu->left = NULL;
    retu->right = NULL;
    return retu;
  }

  int index = re[i*size + j];
  //printf("%d\n", index);
  Node *root = array[index];
  root->avg = (float)(c[i*size + j])/2045.0f;

  root->left = buildTree(re, c, array, size, i, index-1);
  root->right = buildTree(re, c, array, size, index+1, j);

  return root;
}

int findHighest(Node **array, int i, int j) {
  int high = 0, highest = 0;
  if(i==j) {
    return i;
  }
  for (int k = i; k <= j; k++) {
    if (array[k]->freq > highest) {
      highest = array[k]->freq;
      high = k;
    }
  }
  //printf("%s\n", array[high]->word);
  return high;
}

Node *buildTreeGreedy(Node **array, int i, int j) {
  if (i > j) {
    return NULL;
  }
  int index = findHighest(array, i, j);
  Node *root = malloc(sizeof(Node));
  strcpy(root->word, array[index]->word);
  root->freq = array[index]->freq;
  root->avg = (float)(root->freq)/2045.0f;

  root->left = buildTreeGreedy(array, i, index-1);
  root->right = buildTreeGreedy(array, index+1, j);

  return root;
}

void searchBST( char *input, Node *tree) {
  if (!input || !tree) {
    printf("Not found.\n");
    return;
  }
  int cmp = strcmp(input, tree->word);
  printf("Compared with %s (%.2f), ", tree->word, tree->avg);
  if ( cmp == 0) {
    printf("found.\n");
  } else if ( cmp > 0 ) {
    printf("go right subtree.\n");
    searchBST(input, tree->right);
  } else {
    printf("go left subtree.\n");
    searchBST(input, tree->left);
  }
}

void searchBSTGreedy( char *input, Node *tree) {
  if (!input || !tree) {
    printf("Not found.\n");
    return;
  }
  int cmp = strcmp(input, tree->word);
  printf("Compared with %s (%.4f), ", tree->word, tree->avg);
  if ( cmp == 0) {
    printf("found.\n");
  } else if ( cmp > 0 ) {
    printf("go right subtree.\n");
    searchBSTGreedy(input, tree->right);
  } else {
    printf("go left subtree.\n");
    searchBSTGreedy(input, tree->left);
  }
}
