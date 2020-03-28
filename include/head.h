/*
Name: Ali Bokhari
ID: 0970498 / abokhari
Date: March 3, 2020
Assignment 3
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

typedef struct node{
  char word[30];
  int freq;
  double prob;
}Node;

typedef struct instanceVars{
    char fileName[99];
    Node** array1;
    int arraySize1;
    char *word[30];
    int *freq;
}Instance;

//helper fucnctions
Instance* initInstance();
char* userInput(char* input);
int*** OptimalBST(Node **array, int n);
int** optimalSearchTree(Node **array, int n);
//functions to load the data
void getData(Instance* vars);
void loadDataP(Instance* vars);
//options for the menu
void print2D(int *arr, int size);
double o1(Instance* vars);
double o2(Instance* vars);
