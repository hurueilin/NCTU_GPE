#include <bits/stdc++.h>
using namespace std;

int main(){
    int Case;
    cin>>Case;
    cin.ignore();

    stringstream ss;
    while(Case--){
        // stringstream初始化
        ss.str("");
        ss.clear();

        string input;
        getline(cin, input);
        ss << input;

        vector<int> Weight;
        int weightSum=0;
        int tmp;
        while(ss >> tmp){
            Weight.push_back(tmp);
            weightSum += tmp;
        }

        if(weightSum % 2){
            cout<<"NO\n";
            continue;
        }
        else{
            // 先試試用一個背包可以裝出哪些重量，再找看有沒有總重為weightSum/2的可能
            vector<bool> knapsack(weightSum+1, false);
            knapsack[0] = true; // 一定可以裝出背包總重為0
            
            for(unsigned int i=0; i<Weight.size(); i++){
                for(int k = weightSum; k >= Weight[i]; k--){
                    if( knapsack[k - Weight[i]] == true){ // 如果背包重量為(k-物品i)的狀況存在，表示可以讓物品i放
                        knapsack[k] = true; // 可以裝出重量為k的背包
                    }
                }
            }

            if(knapsack[weightSum/2] == true) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}