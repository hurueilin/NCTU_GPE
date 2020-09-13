#include <bits/stdc++.h>
using namespace std;

// {top, north, west, east, south, bottom}
vector<int> die;

void north(vector<int> &die){
    int tmp = die[0];
    die[0] = die[4];
    die[4] = die[5];
    die[5] = die[1];
    die[1] = tmp;
}

void south(vector<int> &die){
    int tmp = die[0];
    die[0] = die[1];
    die[1] = die[5];
    die[5] = die[4];
    die[4] = tmp;
}

void west(vector<int> &die){
    int tmp = die[0];
    die[0] = die[3];
    die[3] = die[5];
    die[5] = die[2];
    die[2] = tmp;
}

void east(vector<int> &die){
    int tmp = die[0];
    die[0] = die[2];
    die[2] = die[5];
    die[5] = die[3];
    die[3] = tmp;
}


int main(){
    int spinCount;
    while(cin>>spinCount){
        if(spinCount == 0) break;
        
        die.clear();
        for(int i=1; i<=6; i++){
            die.push_back(i);
        }

        string command;
        while(spinCount--){
            cin>>command;
            if(command == "north") north(die);
            else if(command == "south") south(die);
            else if(command == "east")  east(die);
            else if(command == "west")  west(die);
        }
        cout<<die[0]<<endl;
    }

    return 0;
}