#include <bits/stdc++.h>
using namespace std;

int check(vector<int> &nums, int numCount){
    int sum = 0;

    // 從最大的d開始找起
    for(int d = numCount-1; d >= 0; d--){
        for(int a = 0; a < numCount; a++){
            for(int b = a + 1; b < numCount; b++){
                for(int c = b + 1; c < numCount; c++){
                    if(a!=d && b!=d && c!=d 
                        && nums[a] + nums[b] + nums[c] == nums[d]){
                            return nums[d];
                    }
                }
            }
        }
    }
    return INT_MAX;
}

int main(){
    int numCount;
    while(cin>>numCount){
        if(numCount == 0) break;

        vector<int> nums(numCount, 0);
        for(int i=0; i<numCount; i++){
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        /* find d = a + b + c */
        int result = check(nums, numCount);
        if(result == INT_MAX)
            printf("no solution\n");
        else
            printf("%d\n", result);
    }
    return 0;
}