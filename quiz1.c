#include<stdio.h>
#include<stdlib.h>
void Q1(){
    int A[5] = {4,8,12,16,20}, *p;
    p = A+ A[0];
    printf("%d\n",*p);
}
void Q2(){
   int *p;
   p = (int*)malloc(20);
   printf("%d\n", sizeof(p));
   free(p);
}
void Q3(int A[], int n){
    int i,j,k;
    for(i=0;i<n; ++i){
        for(j=i; j<=i;++j) A[j]-= A[j-1];
        for(k=j; k<n/2; ++k) A[k]+= A[k+1];
    }
}
int main(){
    int A[] = {1,2,3,4,5,6,7,8,9};
    Q1();
    Q2();
    Q3(A, sizeof(A)/sizeof(A[0]));
    for(int i=0; i<sizeof(A)/sizeof(A[0]); ++i){
        printf("%d\t", A[i]);
    }
   return 0;
}



struct Node{
    int data;
    Node* next;

    Node(int data1, Node*next1){
        data = data1;
        next = next1;
    }

};