/* idea: https://knightzone.studio/2020/05/09/4944/uva%EF%BC%9A11286%EF%BC%8Dconformity/ */
#include <bits/stdc++.h>
using namespace std;

// to_string alternative
template <typename T>
std::string to_string(const T& value){
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int main(){
    int totalFrosh;
    while(cin>>totalFrosh){
        if(totalFrosh==0) break;

        string courseChosen[totalFrosh];
        for(int frosh=0; frosh<totalFrosh; frosh++){
            string key=""; // use the sorted-course-concatenation to be the key

            // making frosh's key
            int courseid;
            vector<int> tmp(5, 0);
            for(int i=0; i<5; i++){
                cin>>courseid;
                tmp[i] = courseid;
            }
            sort(tmp.begin(), tmp.end());
            for(unsigned int i=0; i<tmp.size(); i++){
                key += to_string(tmp[i]);
            }
            // for(int x:tmp){
            //     key += to_string(x);
            // }

            courseChosen[frosh] = key;
        }

        
        map<string, int> combTable;// courseCombinationTable: count the occurrance of each course combination
        map<string, int>::iterator iter;
        for(int frosh=0; frosh<totalFrosh; frosh++){
            iter = combTable.find(courseChosen[frosh]);
            if( iter  == combTable.end() ){
                combTable.insert( make_pair(courseChosen[frosh], 1) );
            }
            else{
                iter->second++;
            }
        }

        int max=1;
        for(iter=combTable.begin(); iter!=combTable.end(); iter++){
            if(iter->second > max){
                max = iter->second;
            }
        }
        // for(pair<string, int> x : combTable){
        //     // cout<<x.first<<": "<<x.second<<endl;
        //     if(x.second > max){
        //         max = x.second;
        //     }
        // }

        if(max == 1){
            cout<<totalFrosh<<endl;
        }
        else{
            cout<<max<<endl;
        }
    }
    return 0;
}