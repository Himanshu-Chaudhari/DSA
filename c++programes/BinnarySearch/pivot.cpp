#include<iostream>
using namespace std;

// Find pivot in a sorted array
int pivot(int *arr,int size){
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    //can also return e
    return s;
}

//Search in a rotated sorted array
int BinarySearch(int *arr,int s,int e,int target){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int seachInRotated(int *arr,int target,int size){
    int p=pivot(arr,size);
    if(target<arr[0]){
        return BinarySearch(arr,p,size-1,target);
    }
    return BinarySearch(arr,0,p,target);
}

//Sqrt using binnary search

int sqrt(int n){

    // My Approach
    // if(n==1 || n==0){
    //     return n;
    // }
    // int s=0;
    // int e=n/2+1;
    // int mid=s+(e-s)/2;
    // while(s<=e){
    //     if(s==e){
    //         return mid-1;
    //     }
    //     if(mid*mid == n){
    //         return mid;
    //     }
    //     if(mid*mid > n){
    //         e=mid;
    //     }
    //     else{
    //         s=mid+1;
    //     }
    //     mid=s+(e-s)/2;
    //     cout<<mid<<endl;
    // }
    // return mid;

    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        int sq=mid*mid;
        if(sq==n){
            return mid;
        }
        if(sq<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

double morePresise(int n,int presiseDigits,int tempSol){

    double factor=1;
    double ans=tempSol;

    for(int i=0 ; i<presiseDigits;i++){
        factor=factor/10;
        for (double j = ans; j*j <n; j=j+factor){
            ans=j;
        }      
    }
    return ans;
}
int main(){
    int arr[8]={4,5,6,7,0,1,2};
    cout<<pivot(arr,8)<<endl;
    // // cout<<BinarySearch(arr,0,7,11);
    // cout<<seachInRotated(arr,5,8)<<endl;
    // cout<<sqrt(36)<<endl;
    // cout<<morePresise(59,4,7);
}