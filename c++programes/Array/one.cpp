#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateArray(vector<int> arr,int n){
    int size=arr.size();
    vector<int> ans(size);

    for(int i=0;i<size;i++){
        ans[(i+n)%size]=arr[i];
    }
    return ans;
}

bool checkIfSortedAndRotated(vector<int> arr){
    int cnt=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]>arr[i+1]){
            cnt++;
        }
    }
    if( cnt==0 || (cnt==1 && arr[arr.size()-1]<arr[0]) ){
        return true;
    }
    return false;
}

vector<int> findSum(vector<int> arr1,vector<int> arr2){
    reverse(arr1.begin(),arr1.end());
    reverse(arr2.begin(),arr2.end());
    int carry=0;
    int size1=arr1.size();
    int size2=arr2.size();
    int maxSize;
    int minSize;
    int greaterArray;
    if(size1>size2){
        maxSize=size1;
        minSize=size2;
        greaterArray=1;
    }
    else{
        minSize=size1;
        maxSize=size2;
        greaterArray=2;
    }
    vector<int> ans(maxSize+1);

    for(int i=0;i<minSize;i++){
        ans[i]=(arr1[i]+arr2[i]+carry)%10;
        carry=(carry+arr1[i]+arr2[i])/10;
    }
    if(greaterArray==1){
        for(int i=minSize;i<maxSize;i++){
            ans[i]=(arr1[i]+carry)%10;
            carry=(carry+arr1[i])/10;
        }
    }
    else{
        for(int i=minSize;i<maxSize;i++){
            ans[i]=(arr2[i]+carry)%10;
            carry=(carry+arr2[i])/10;
        }
    }
    if(carry){
        ans[maxSize]=carry;
    }
    else{
        ans.pop_back();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// Given an array of size n+1 it has elements in range (1,n) and exactly one lement which is repeated find the repeating element

// Approch used here is known as flloyds cycle detection algorithm //Here it is important to find that we need to treat the array as a linked list and try to return the start of cycle as answer
int detectRepeatingElement(vector<int> arr){

}


int main(){
    vector<int> arr={3,4,6,7};
    vector<int> ans=rotateArray(arr,3);
    // for(auto i : ans){
    //     cout<<i<<" ";
    // }
    vector<int> arr2={2,4,5,7,8};
    ans=findSum(arr,arr2);
    for(auto i : ans){
        cout<<i<<" ";
    }
}