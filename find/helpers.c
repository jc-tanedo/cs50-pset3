/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

void merge(int A[], int L[], int lCount, int R[], int rCount);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int mid = n/2;
    //printf("\nSize: %i Index: %i - %i", n, mid, values[mid]);
    
    if (values[mid]==value) {
        return true;
    }else if (mid == 0 || values[mid] < 0){
        return false;
    } else {
        if (values[mid]>value) {
            int L[mid];
            for (int ctr=0; ctr<mid; ctr++){
                L[ctr]=values[ctr];
                //printf("\nL: %i", L[ctr]);
            }
            return search(value, L, mid);
        } else {
            int R[n-mid];
            for (int ctr=mid; ctr<n; ctr++){
                R[ctr-mid]=values[ctr];
                //printf("\nR: %i", R[ctr-mid]);
            }
            return search(value, R, n-mid);
        }
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    if (n < 2) {
        return;
    }

    int mid = n/2;
    int L[mid], R[n-mid];
    
    for (int ctr=0; ctr<mid; ctr++){
        L[ctr]=values[ctr];
    }
    for (int ctr=mid; ctr<n; ctr++){
        R[ctr-mid]=values[ctr];
    }
    
    sort(L,mid);
    sort(R,n-mid);
    
    merge(values, L, mid, R, n-mid);
    
    return;
}

void merge(int A[], int L[], int lCount, int R[], int rCount){
    int ctrA, ctrL, ctrR;
    
    ctrA=0; ctrL=0; ctrR=0;
    
    while(ctrL<lCount && ctrR<rCount){
        if (L[ctrL] < R[ctrR]){
            A[ctrA] = L[ctrL];
            ctrA++;
            ctrL++;
        } else {
            A[ctrA] = R[ctrR];
            ctrA++;
            ctrR++;
        }
    }
    while(ctrL<lCount){
        A[ctrA]=L[ctrL];
        ctrA++;
        ctrL++;
    }
    while(ctrR<rCount){
        A[ctrA]=R[ctrR];
        ctrA++;
        ctrR++;
    }

}
