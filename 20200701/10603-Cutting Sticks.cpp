#include <bits/stdc++.h>
using namespace std;
#define LIMIT 9999

int main(){
    int length;
    while(cin>>length && length!=0){
        int cuts; // 欲做幾次切割
        cin >> cuts;

        int scale[cuts+2]; // 紀錄刻度(切割位置)之長度 (含頭尾)
        int maxIndex = cuts + 1; // DP table index最多到哪
        scale[0]=0; scale[maxIndex]=length;
        for(int i=1; i<=cuts; i++){
            cin >> scale[i];
        }

        // init DP table
        int cost[52][52];
        for(int i=0; i<52; i++){
            for(int j=0; j<52; j++){
                cost[i][j] = LIMIT;
            }
        }

        
        // ==== Bottom-up DP: 從左下到右上填表格 ====
        for(int i=0; i<=maxIndex; i++){
            cost[i][i] = 0;
        }
        for(int i=0; i<maxIndex; i++){
            cost[i][i+1] = 0;
        }

        for(int width=2; width<=maxIndex; width++){
            
            for(int i=0; i <= maxIndex-width; i++){

                int j = i + width;

                for(int k = i+1; k < j; k++){
                    cost[i][j] = min( cost[i][j], cost[i][k]+cost[k][j]+(scale[j] - scale[i]) );
                }
            }
        }

        // print DP table
        // for(int i=0; i<=maxIndex; i++){
        //     for(int j=0; j<=maxIndex; j++){
        //         cout<<cost[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }
        printf("The minimum cutting is %d.\n", cost[0][maxIndex]);
    }
    return 0;
}