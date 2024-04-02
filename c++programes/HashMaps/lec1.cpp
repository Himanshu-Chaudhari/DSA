#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int maxFreqNumber(vector<int> numbers){
    int size=numbers.size();
    unordered_map<int,int> m;
    int maxFreq=INT_MAX;
    int ans=0;
    for(int i=0;i<size;i++){
        m[numbers[i]]++;
        maxFreq=max(maxFreq,numbers[i]);
    }
    
    for(int i=0;i<size;i++ ){
        if(maxFreq==m[numbers[i]]){
            ans=numbers[i];
            break;
        }
    }
    return ans;
}

int main(){
    //creation
    unordered_map<string, int> m;
    //insertion
    //1
    pair<string, int> p = make_pair("babbar", 3);
    m. insert(p);
    //2
    pair<string,int> pair2("love", 2);
    m.insert(pair2);
    //3
    m["mera"] = 1;

    //what will happen
    m["mera"] = 2;


    //Search
    cout << m["mera"] << endl; 
    cout << m.at ("babbar") << endl;

    cout << m["unknownKey"] << endl;
    cout << m.at ("unknownKey") << endl;

    //size
    cout << m.size() << endl;

    //to check presence 
    cout << m. count ("love")<< endl;

    //erase
    m. erase("love");
    cout << m.size() << endl;

    for(auto i: m){
        cout<<i.first<<" : "<<i.second<<endl;
    }
}
