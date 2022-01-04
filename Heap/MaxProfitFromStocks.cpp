#include<iostream>
#include<vector>
#include<queue>


using namespace std;
/*
Stock Maximize problem
input: share price of certain duration of time is given
output: max profit

condition: Each day you can either buy one share of that stock or sell any number of that stock you own, or not make any 
        transaction at all.What is the maximum profit you can make with an optimum trading strategy?
*/
class Solution {

public:
    int maxProfit(vector<int >&price){
        int maxProfit = 0;
        int shares = 0;
        priority_queue<int> pq;
        for(int i = 0;i<price.size();i++){
            pq.push(price[i]);
        }
        int maxPrice = pq.top();
        int totalStocks = price.size();
        vector<int>count(maxPrice+1,0);
        for(int i=0;i<price.size();i++){
            count[price[i]]++;
        }
        for(int i=0;i<price.size();i++){
            int today = price[i];
            totalStocks--;//totalStocks is the number of stocks left so decrement them after selling ,buying or ignore it 
            if(today == maxPrice){
                //sell the stock if it is the max price and a transaction is completed
                maxProfit += today*shares;
                shares = 0;//reset shares
                if(totalStocks>0){
                    //remove the used stock from the queue and update the maxPrice 
                    //and also update the count of stocks
                    pq.pop();
                    count[today]--;
                    maxPrice = pq.top();
                }
            }else if(today < maxPrice and i!=price.size()-1){
                //buy the stock which less than the max price and not the last day
                shares++;//increment shares you have
                maxProfit -= today;//decrement the maxProfit as you are buying a share of that stock
            }

                    
        }

        return maxProfit<0?0:maxProfit;
    }

};

int main(){

    int arr[] = {5,3,2,1,2,100};
    int n = sizeof(arr)/sizeof(int);
    vector<int>price;
    for(int i=0;i<n;i++){
        price.push_back(arr[i]);
    }
    Solution s;
    cout<<s.maxProfit(price)<<endl;
    return 0;
}