/*
Name: Ali Bokhari
ID: 0970498 / abokhari
Date: March 22, 2020
Assignment 3
*/

#include "head.h"

Instance* initInstance(){
    Instance* newVars = calloc(1, sizeof(Instance));
    newVars->array1 = NULL;
    newVars->arraySize1 = 0;
    return newVars;
}

char* userInput(char* input){
    fgets(input, 256, stdin);
    input[strcspn(input, "\r\n")] = '\0';
    return input;
}

int findN(Node **array, char* key, int size) {
  if(array==NULL) {
    return -1;
  }
  for(int i = 0; i < size; i++) {
    if (strcmp(key, array[i]->word) == 0) {
      return i;
    }
  }
  return -1;
}

void printNodes(Node **array, int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    printf("%s %d\n", array[i]->word, array[i]->freq);
    total += array[i]->freq;
  }
  printf("%d\n", total);
}

void getData(Instance* vars){
    const int arraySize = 2045;
    char tmp[30];
    int tmpIn, x;
    Node** array = malloc(sizeof(Node*)*arraySize);
    for (int i = 0; i < arraySize; i++) {
      array[i] = malloc(sizeof(Node));
    }
    FILE* filePointer = fopen("./files/data_7.txt", "r");
    for(x=0; x<arraySize; x++){
        if(fscanf(filePointer, "%s ", tmp)==EOF){
          break;
        }
        tmpIn = findN(array, tmp, x);
        if(tmpIn == -1) {
          strcpy(array[x]->word, tmp);
          array[x]->freq = 1;
        } else {
          (array[tmpIn]->freq)++;
          x--;
        }
    }
    /*for(int k = 0; k<x; k++){
      array[k]->prob = (array[k]->freq)/2045;
    }*/
    fclose(filePointer);
    vars->array1 = array;
    vars->arraySize1 = x;
}

double o1(Instance* vars){
    double start = 0, stop = 0, timeSpent = 0;
    //int totalAnagrams = 0;
    char* anag = calloc(256, sizeof(char)*256);
    printf("Enter a key:\n");
    anag = userInput(anag);
    //printf("Calculating...\n");
    start = clock();
    //totalAnagrams = countAnagram(vars->array1, vars->arraySize1, anag);
    searchBST(anag, vars->tree);
    stop = clock();
    timeSpent = (double)(stop - start)/CLOCKS_PER_SEC;
    printf("------------------------------------\n");
    //printf("Number of anagrams: %d\n", totalAnagrams);
    printf("Execution time: %f second\n", timeSpent);
    printf("------------------------------------\n");
    free(anag);
    return timeSpent;
}

double o2(Instance* vars){
    double start = 0, stop = 0, timeSpent1 = 0, timeSpent2 = 0;
    int totalInversion = 0;
    char* anag = calloc(256, sizeof(char)*256);
    printf("Input String to search for anagrams:\n");
    anag = userInput(anag);
    printf("calculating...\n");
    start = clock();
    //qsort(vars->array1, vars->arraySize1, sizeof(char*), strCompare);
    stop = clock();
    timeSpent1 = (double)(stop - start)/CLOCKS_PER_SEC;
    start = clock();
    //totalInversion = presortAnagram(vars->array1, vars->arraySize1, anag);
    stop = clock();
    timeSpent2 = (double)(stop - start)/CLOCKS_PER_SEC;
    printf("------------------------------------\n");
    printf("Number of anagrams: %d\n", totalInversion);
    printf("Sorting time: %f second\n", timeSpent1);
    printf("Execution time: %f second\n", timeSpent2);
    printf("------------------------------------\n");
    free(anag);
    return timeSpent2;
}

void print2D(int *arr, int size) {
  //size++;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d\t", arr[i*size + j]);
    }
    printf("\n");
  }
}

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->freq);

    // Process left child
    print2DUtil(root->left, space);
}

int cmpfunc (const void * a, const void * b) {
   return strcmp((*(Node**)a)->word, (*(Node**)b)->word);
}

int main(int argc, char** argv){
    char* menu = calloc(256, sizeof(char)*256);
    Instance* vars = initInstance();

    getData(vars);
    qsort(vars->array1, vars->arraySize1, sizeof(Node*), cmpfunc);
    //printNodes(vars->array1, vars->arraySize1);
    int **cost = OptimalBST(vars->array1, vars->arraySize1);

    vars->tree = buildTree(cost[1], vars->array1, vars->arraySize1, 0, vars->arraySize1 -1);
    //printNodes(vars->array1, vars->arraySize1);
    for(;;){
        printf("1: Question 1: OptimalBST dynamic programming\n");
        printf("2: Question 2\n");
        //printf("5: Compare inversion algorithms\n");
        //printf("6: Compare convex hull algorithms\n");
        printf("3: Exit\n");
        printf("Select option:\n");
        menu = userInput(menu);

        int num = strtol(menu, NULL, 10);

        if(num == 1){
            o1(vars);
        }else if(num == 2){
            o2(vars);
        }else if(num == 3){
            free(vars->array1);
            free(vars);
            free(menu);
            exit(0);
        }else{
            printf("------------------------------------\n");
            printf("Invalid input, enter number between 1-7.\n");
            printf("------------------------------------\n");
        }
        free(vars->array1);
        //free(vars->array2);
        //getData(vars);
    }

    //printNodes(vars->array1, vars->arraySize1);
    // Node key1 = {"A", 213, 0};
    // Node key2 = {"B", 20, 0};
    // Node key3 = {"C", 547, 0};
    // Node key4 = {"D", 100, 0};
    // Node key5 = {"E", 120, 0};
    // Node *array[5];
    // array[0] = &key1;
    // array[1] = &key2;
    // array[2] = &key3;
    // array[3] = &key4;
    // array[4] = &key5;
    //int keys[] = {4, 5, 1, 6, 4};
    //int freq[] = {213, 20, 547, 100, 120};
    //int n = sizeof(keys)/sizeof(keys[0]);


    //printNodes(vars->array1, vars->arraySize1);
    //printf("%s\n", vars->array1[cost[1][0 + vars->arraySize1 - 1]]->word);
    //print2D(cost[1], 5);
    //vars->tree = buildTree(cost[1], vars->array1, vars->arraySize1, 0, vars->arraySize1 -1);
    //print2DUtil(root, 0);
    //printf("Cost of Optimal BST is %d\n", optimalSearchTree(keys, freq, n));
    //optimalSearchTree2(keys, freq, n);
    //int tmp = re[1][0][(vars->arraySize1) - 1];
    //printf("%d %s %d\n", tmp, vars->array1[tmp]->word, vars->array1[tmp]->freq);

    return 0;
}
/*menu not part of assignemnt so not original*/
