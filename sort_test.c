#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
double drand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
void test(){
    int len = 8189;
    int a[len];
    double b[len];
    int err = 0;

    for(int i = 0; i < len; i++) a[i] = rand()%len;
    for(int i = 0; i < len; i++) b[i] = drand(0, len);
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, BUBBLE, UP);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, BUBBLE, DOWN);
    for(int j = 0; j < len--; j++) {if (a[j] > a[j+1]) err++;}
    for(int j = 0; j < len--; j++) {if (b[j] < b[j+1]) err++;}
    if(err == 0) printf("bubble sorted!\n");
    else printf("bubble doesn't sorted with %d errs(\n", err);

    err = 0;
    for(int i = 0; i < len; i++) a[i] = rand()%len;
    for(int i = 0; i < len; i++) b[i] = drand(0, len);
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, COMB, DOWN);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, COMB, UP);
    for(int j = 0; j < len--; j++) {if (a[j] < a[j+1]) err++;}
    for(int j = 0; j < len--; j++) {if (b[j] > b[j+1]) err++;}
    if(err == 0) printf("comb sorted!\n");
    else printf("comb doesn't sorted with %d errs(\n", err);

    err = 0;
    for(int i = 0; i < len; i++) a[i] = rand()%len;
    for(int i = 0; i < len; i++) b[i] = drand(0, len);
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, SHELL, UP);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, SHELL, UP);
    for(int j = 0; j < len--; j++) {if (a[j] > a[j+1]) err++;}
    for(int j = 0; j < len--; j++) {if (b[j] > b[j+1]) err++;}
    if(err == 0) printf("shell sorted!\n");
    else printf("shell doesn't sorted with %d errs(\n", err);
    
    err = 0;
    for(int i = 0; i < len; i++) a[i] = rand()%len;
    for(int i = 0; i < len; i++) b[i] = drand(0, len);
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, QUICK, DOWN);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, QUICK, DOWN);
    for(int j = 0; j < len--; j++) {if (a[j] < a[j+1]) err++;}
    for(int j = 0; j < len--; j++) {if (b[j] < b[j+1]) err++;}
    if(err == 0) printf("quick sorted!\n");
    else printf("quick doesn't sorted with %d errs(\n", err);
    
    err = 0;
    for(int i = 0; i < len; i++) a[i] = rand()%len;
    for(int i = 0; i < len; i++) b[i] = drand(0, len);
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, MERGE, UP);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, MERGE, DOWN);
    for(int j = 0; j < len--; j++) {if (a[j] > a[j+1]) err++;}
    for(int j = 0; j < len--; j++) {if (b[j] < b[j+1]) err++;}
    if(err == 0) printf("merge sorted!\n");
    else printf("merge doesn't sorted with %d errs(\n", err);
    
    err = 0;
    for(int i = 0; i < len; i++) a[i] = rand()%len;
    for(int i = 0; i < len; i++) b[i] = drand(0, len);
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, HEAP, DOWN);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, HEAP, UP);
    for(int j = 0; j < len--; j++) {if (a[j] < a[j+1]) err++;}
    for(int j = 0; j < len--; j++) {if (b[j] > b[j+1]) err++;}
    if(err == 0) printf("heap sorted!\n");
    else printf("heap doesn't sorted with %d errs(\n", err);
}
int main(){
    /*
    int a[] = {1, 7, 4, 0, 9, 4, 8, 8, 2, 4};
    double b[] = {1, 14, 9, 12, 30, 11, 2};
    sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, BUBBLE, UP);
    sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, HEAP, DOWN);
    for (int i = 0; i < sizeof(a)/sizeof(int); i++){printf("%d ", a[i]);}
    printf("\n");
    for (int i = 0; i < sizeof(b)/sizeof(double); i++){printf("%.1f ", b[i]);}*/
    test();
}