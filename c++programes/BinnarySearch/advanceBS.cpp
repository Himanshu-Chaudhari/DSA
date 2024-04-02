#include<iostream>
#include<vector>
using namespace std;

// Book alocation problem 
// n = number of books
// m = number of students 
// pages = no of pages in each book

// here we know that the max pages that can be allocated to a student will always be in between 0 and sum of all the pages thus we check the midle element and if the solution for middle element exists the we move end to middle-1 and if not then start to middle+1
// here basically to get the ans we need to check each possible sol and to get the most optimal we reduce the search space using binary search

bool isPossible(vector<int> arr,int n,int m,int mid){
    int stdAllocated=1;
    int oneStd=0;
    for(int i=0;i<n;i++){
        if(oneStd+arr[i]<=mid){
            oneStd+=arr[i];
        }
        else{
            stdAllocated++;
            if(stdAllocated>m || arr[i]>mid){
                return false;
            }
            oneStd=arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> pages,int n,int m){
    sort(pages.begin(),pages.end());
    int s=0;
    int maxPages=0;
    for(int i=0;i<pages.size();i++){
        maxPages+=pages[i];
    }
    int e=maxPages;
    int ans=-1;
    int mid=s+(e-s)/2;
    while (s<=e)
    {
        if(isPossible(pages,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}


// Aggresive cows

bool isPossibleAgressiveCows(vector<int> stalls,int n,int mid){
    int cowsPlaced=1;
    int distance=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-distance >= mid){
            cowsPlaced++;
            if(cowsPlaced==n){
                return true;
            }
            distance=stalls[i];
        }
    }
    return false;
}

int aggresiveCows(vector<int> stalls,int n){
    sort(stalls.begin(),stalls.end());
    int s=0;
    int maxDistance=-1;
    for(int i=0;i<stalls.size();i++){
        maxDistance=max(maxDistance,stalls[i]);
    }
    int e=maxDistance;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossibleAgressiveCows(stalls,n,mid)){
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


int main(){
    vector<int> arr{2,1,3};
    // cout<<allocateBooks(arr,4,3)<<endl;
    cout<<aggresiveCows(arr,2)<<endl;;
}