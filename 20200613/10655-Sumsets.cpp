#include <bits/stdc++.h>
using namespace std;

int check(int numCount, vector<int> &nums){
    int max = -1;

    for(int a=0; a<numCount; a++){
        for(int b=0; b<numCount; b++){
            if(a == b) continue;
            for(int c=0; c<numCount; c++){
                if(b == c || a == c) continue;
                for(int d=0; d<numCount; d++){
                    if(a == d || b == d || c == d) continue;
                    
                    if(nums[a] + nums[b] + nums[c] == nums[d]){
                        if(nums[d] > max)
                            max = nums[d];
                    }
                }
            }
        }
    }
    return max;
}

int main(){
    int numCount;
    while(cin>>numCount){
        if(numCount == 0) break;

        vector<int> nums(numCount, 0);
        for(int i=0; i<numCount; i++){
            cin >> nums[i];
        }
    
        int result = check(numCount, nums);
        if(result == -1)
            printf("no solution\n");
        else
            printf("%d\n", result);
    }
    return 0;
}