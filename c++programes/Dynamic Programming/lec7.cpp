#include<iostream>
#include<vector>
using namespace std;

// Knapsack problem 
// recursion

void knapsack(vector<int> weights,vector<int> profits,int maxWeight,int weight,int profit,int &maxProfit,int index){
    if ((index >=weights.size() || weight>maxWeight)){
        return;
    }
    knapsack(weights,profits,maxWeight,weight,profit,maxProfit,index+1);
    if(weight+weights[index]<=maxWeight){
        maxProfit=max(maxProfit,profit+profits[index]);
        knapsack(weights,profits,maxWeight,weight+weights[index],profit+profits[index],maxProfit,index+1);
    }
}

int main(){
    vector<int> profits{10,343,45};
    vector<int> weights{1,3,7 };
    int maxProfit=0;
    knapsack(weights,profits,10,0,0,maxProfit,0);
    cout<<maxProfit;
}