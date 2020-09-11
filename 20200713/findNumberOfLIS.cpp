#include <bits/stdc++.h>
using namespace std;

/***
Define:
    len[i]: the length of the Longest Increasing Subsequence which ends with nums[i].
    cnt[i]: the number of the Longest Increasing Subsequence which ends with nums[i].

recursion:
    len[i] = max(len[i], len[j]+1) , for j in range(i)
    cnt[i] += cnt[j]+1 , if len[i] == len[j]+1
***/

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int max_len = 0;
    int len[n];
    int cnt[n];

    for(int i=0; i<n; i++){
        len[i] = cnt[i] = 1;

        for(int j=0; j < i; j++){
            if(nums[j] < nums[i]){
                if(len[i] == len[j] + 1){
                    cnt[i] = cnt[j] + 1;
                }
                if(len[i] < len[j] + 1){
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                }
            }
        }

        if(max_len == len[i])
            res += cnt[i];
        if(max_len < len[i]){
            max_len = len[i];
            res = cnt[i];
        }
    }

    return res;
}


int main(){
    int n;
    cin>>n;

    vector<int> nums(n, 0);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    
    cout<<findNumberOfLIS(nums);

    return 0;
}