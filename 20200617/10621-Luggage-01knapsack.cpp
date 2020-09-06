#include <bits/stdc++.h>
using namespace std;

int main(){
    int Case;
    cin>>Case;
    cin.ignore();


    stringstream ss;
    while(Case--){
        string str;
        getline(cin, str);
        
        ss.str("");
        ss.clear();
        ss << str;

        vector<int> Weight;
        int weightSum=0;
        int tmp;
        while(ss >> tmp){
            weightSum += tmp;
            Weight.push_back(tmp);
        }


        if(weightSum % 2 == 1){
            printf("NO\n");
            continue;
        }
        else{
            /** 標準的0/1背包做法 **/
            int dp[Weight.size()][weightSum+1];
            // init dp table
            for(int i=0; i<Weight.size(); i++){
                for(int k=0; k<=weightSum; k++){
                    dp[i][k] = 0;
                }
            }
            dp[0][0] = 1;

            for(int i=1; i < Weight.size(); i++){
                for(int k=0; k<=weightSum; k++){
                    if(k < Weight[i])
                        dp[i][k] = dp[i-1][k];
                    else
                        dp[i][k] = max( dp[i-1][k], dp[i-1][k - Weight[i]] );
                }
            }

            for(int i=0; i<Weight.size(); i++){
                for(int k=0; k<=weightSum; k++){
                    cout<< dp[i][k] << " ";
                }
                cout<<endl;
            }


            if(dp[Weight.size()-1][weightSum/2] == 1)   printf("YES\n");
            else    printf("NO\n"); 
        }
    }
    return 0;
}