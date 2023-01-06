#include <bits/stdc++.h> 
#define ll long long
ll Helper(int*arr,int n){
     ll curr_max=0;
    ll curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum=curr_sum+arr[i];
        if(curr_sum>curr_max) curr_max=curr_sum;
        if(curr_sum<0) curr_sum=0;
    }
    return curr_max;
}


long long maxSubarraySum(int arr[], int n)
{
    
    return Helper(arr,n);
}
