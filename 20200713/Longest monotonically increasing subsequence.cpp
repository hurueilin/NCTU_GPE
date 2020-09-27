#include <bits/stdc++.h>
using namespace std;

/***
Description:
Please find the longest monotonically increasing subsequence (LMIS) of a sequence of n numbers (each number m, 1≤ m ≤ 232-1)and indicate its length of the sequence. For example, the sequence

    2, 5, 3, 1, 6, 4

has three LMISs of length 3, namely,

   (2, 5, 6),  (2, 3, 6),  (2, 3, 4).

Sample Input
4
6
2 5 3 1 6 4
9
2 6 1 9 7 3 5 4 8
7
1 2 3 4 5 6 7
7
7 6 5 4 3 2 1

Sample Output
3
2 5 6
2 3 6
2 3 4
5
2 6 7 8
2 3 5 8
2 3 4 8
1 3 5 8
1 3 4 8
1
1 2 3 4 5 6 7
7
7
6
5
4
3
2
1
***/

// 作法: 先Enumerate Combinations後，再檢查sequence是否遞增
// Time complexity: 最差2^9 (因為題目n最多到9，可暴力法)

vector< vector<int> > LIS;
int LISlength = 0;

bool isIncreasing(vector<int> &tmpSeq){
    if(tmpSeq.size() == 0) return false;
    if(tmpSeq.size() == 1) return true;

    for(int i=0; i<tmpSeq.size()-1; i++){
        if(tmpSeq[i] >= tmpSeq[i+1])
            return false;
    }
    return true;
}

void addToLIS(vector<int> &tmpSeq){
    if(tmpSeq.size() >= LISlength){
        if(tmpSeq.size() > LISlength){
            LIS.clear();
            LISlength = tmpSeq.size();
        }
        LIS.push_back(tmpSeq);
    }
}

void backtrack(int index, vector<bool> &selected, vector<int> &nums)
{
    // 每次進backtrack()就是一種組合
    vector<int> tmpSeq;
    for(int i=0; i<nums.size(); i++){
        if(selected[i]){
            tmpSeq.push_back(nums[i]);
        }
    }
    if(isIncreasing(tmpSeq)){
        addToLIS(tmpSeq);
    }
    
    // 遞迴處理
    for (; index<nums.size(); index++)
    {
        // 選取位於index的數字
        selected[index] = true;
    
        // 然後繼續枚舉後面的數字
        backtrack(index+1, selected, nums);
    
        // 回復原狀
        selected[index] = false;
    }
}
     
int main(){
    int Cases;
    cin>>Cases;
    while (Cases--){
        int numCount;
        cin>>numCount;

        vector<int> nums(numCount, 0);
        for(int i=0; i<numCount; i++){
            cin>>nums[i];
        }


        // init
        LIS.clear();
        LISlength = 0;
        vector<bool> selected(numCount, false);  // 索引儲存
        
        backtrack(0, selected, nums);

        
        // print output
        cout<<LIS.size()<<endl;
        for(int i=0; i<LIS.size(); i++){
            for(int j=0; j<LIS[i].size(); j++){
                cout << LIS[i][j];
                if(j != LIS[i].size()-1) cout << " ";
            }
            cout << endl;
        }
    }
}