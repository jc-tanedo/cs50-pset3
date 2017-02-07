#include <cs50.h>
#include <stdio.h>

const int MAX = 65536;

void sort(int values[], int n);
void merge(int A[], int L[], int lCount, int R[], int rCount);

int main(void) {
    int size;
    int numbers[MAX];
    
    for (size = 0; size < MAX; size++) {
        // printf("\nNumber %i: ", size+1);
        int val = get_int();
        if (val == INT_MAX){
            break;
        }
        numbers[size]=val;
    }
    
    sort(numbers, size);
    
    for (int ctr = 0; ctr<size; ctr++){
        printf("%i\n", numbers[ctr]);
    }
    return 0;
}

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