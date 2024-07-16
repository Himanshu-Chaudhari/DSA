#include<iostream>
#include<unordered_map>

using namespace std;
int main(){
    unordered_map<pair<int,int>,int> p;
    p[{1,2}]=3;
    int f=p[{1,2}];
    cout<<f;
}