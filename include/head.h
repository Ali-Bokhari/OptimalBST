/*
Name: Ali Bokhari
ID: 0970498 / abokhari
Date: March 21, 2020
Assignment 4
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

typedef struct node{
  char word[30];
  int freq;
  float avg;
  struct node *left;
  struct node *right;
}Node;

typedef struct instanceVars{
    char fileName[99];
    Node** array1;
    int arraySize1;
    Node *tree;
    Node *tree2;
}Instance;

//helper fucnctions
Instance* initInstance();
char* userInput(char* input);
int** OptimalBST(Node **array, int n);
Node *buildTree(int *re, int *c, Node **array, int size, int i, int j);
Node *buildTreeGreedy(Node **array, int i, int j);
void searchBST( char *input, Node *tree);
void searchBSTGreedy( char *input, Node *tree);
//functions to load the data
void getData(Instance* vars);
void loadDataP(Instance* vars);
//options for the menu
void print2D(int *arr, int size);
double o1(Instance* vars);
double o2(Instance* vars);
