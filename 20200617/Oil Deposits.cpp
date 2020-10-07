#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

Point* newPoint(int a, int b){
    Point *p = new Point();
    p->x = a;
    p->y = b;

    return p;
}

void BFS(int i, vector<Point*> &oil,  bool isVisited[]){
    // 將i的鄰近點設為已拜訪
    for(int j=0; j<oil.size(); j++){
        if(isVisited[j]) continue;

        if( (abs(oil[i]->x - oil[j]->x) <= 1) && (abs(oil[i]->y - oil[j]->y) <= 1) ){
            isVisited[j] = true;
            BFS(j, oil, isVisited);
        }
    }
}

int countOilPockets(vector<Point*> &oil){
    if(oil.size() == 0) return 0;

    int pockets = 0;
    bool isVisited[oil.size()];
    memset(isVisited, false, sizeof(isVisited));
   
    
    for(int i=0; i<oil.size(); i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            pockets++;
            BFS(i, oil, isVisited);
        }
    }

    return pockets;
}

int main(){
    int m, n;
    while(cin>>m>>n){
        if(m == 0 || n == 0) break;

        char c;
        vector<Point*> oil;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>c;
                if(c == '@'){
                    oil.push_back(newPoint(i, j));
                }
            }
        }
        
        cout<<countOilPockets(oil)<<endl;
    }
    return 0;
}