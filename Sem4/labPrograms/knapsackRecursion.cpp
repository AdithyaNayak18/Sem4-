#include <iostream>
using namespace std;

int max(int a,int b){
    return (a>b)? a:b;
}
int knapsack(int w,int wt[], int val[], int n){
    if(n==0 || w==0)
        return 0;
    if(val[n-1]>w)
        return knapsack(w,wt,val,n-1);
    else
        return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
}

int main(){
    int weights[]={110,140,150,130};
    int profit[]={20,18,19,25};
    int maxW=300;
    int n=sizeof(weights)/sizeof(weights[0]);
    
    cout << knapsack(maxW,weights,profit,n);
    return 0;
}
