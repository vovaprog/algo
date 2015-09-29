#pragma once

void shellSort(int *list, int listSize);
void mergeSort(int *list,int listSize);
void insertionSort(int *list,int listSize);
void bubbleSort(int *list,int size);
void heapSort(int *list, int listSize);

int binarySearch(int *list, int listSize, int key);
int binarySearch2(int *list, int listSize, int key);

void radixSortMsd(int *list, int listSize,int maxBit);

int search(char *s,char *pattern);
void testSearch();

int searchBoyerMoore(const char *s,const unsigned char *pattern);
void testSearchBoyerMoore();
void testPrefixFunction();

void testReverseNeighbors();
