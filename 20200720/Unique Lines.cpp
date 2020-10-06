#include <bits/stdc++.h>
using namespace std;

int countUniqueLines(vector<int> &X, vector<int> &Y, int num_points){
    float slope, slope2;

    vector<float> gradient;
    vector<int> poolX;
    vector<int> poolY;
    int output = 0;
    int flag = 0;

    for(int i=0; i<num_points-1; i++){
        for(int j=i+1; j<num_points; j++){
            flag = 0;

            if(X[i] == X[j]){
                slope = (float)INT_MAX;
            }
            else if(Y[i] == Y[j]){
                slope = 0;
            }
            else{
                slope = (float)(Y[j]-Y[i]) / (float)(X[j]-X[i]);
            }
            // printf("(%d, %d) and (%d, %d) slope: %f\n", X[i], Y[i], X[j], Y[j], slope);


            for(int k=0; k<output; k++){ // 算出斜率後去檢查之前有沒有一樣的(這題平行算不同條所以只檢查從同點出發且斜率一樣的)
                if(poolX[k] == X[j]){
                    slope2 = (float)INT_MAX;
                }
                else if(poolY[k] == Y[j]){
                    slope2 = 0;
                }
                else{
                    slope2 = (float)(poolY[k]-Y[j]) / (float)(poolX[k]-X[j]);
                }

                if(slope == slope2 && gradient[k] == slope){
                    flag = 1;
                    break;
                }        
            }
            
            if(!flag)//都沒一樣則儲存起來
            {
                poolX.push_back(X[j]);
                poolY.push_back(Y[j]);
                gradient.push_back(slope);
                output++;
            }
        }
    }
    for(int i=0; i<output; i++){
        printf("(%d , %d)\n", poolX[i], poolY[i]);
    }

    return output;
}

int main(){
    int Cases;
    cin >> Cases;

    while (Cases--)
    {
        int num_points;
        cin >> num_points;

        vector<int> X;
        vector<int> Y;
        int n;
        for(int i=0; i<num_points; i++){
            cin >> n;
            X.push_back(n);
            cin >> n;
            Y.push_back(n);
        }

        cout<<countUniqueLines(X, Y, num_points)<<endl;
    }
    return 0;
}