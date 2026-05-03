#include <bits/stdc++.h>
using namespace std;

unordered_map<string , vector<string>>graph;

bool alreadyFriend(string a , string b){
    for(auto &f : graph[a]){
        if(f == b)return true;
    }
    return false;
}

void addUser(string user){
    if(graph.find(user) != graph.end()){
        cout<<"User Already Exists!!"<<endl;
        return;
    }
    graph[user] = {};
}

void addFriend(string a , string b){
    if(graph.find(a) == graph.end() || graph.find(b) == graph.end()){
        cout<<"User Not Found!!"<<endl;
        return;
    }
    if(alreadyFriend(a,b)){
        cout<<"Already a Friend!!"<<endl;
        return;
    }
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void display(){
    for(auto &p : graph){
        cout<<p.first<<"->";
        for(auto &f : p.second){
            cout<<f<<" ";
        }
        cout<<endl;
    }
}



int main(){
    int choice;
    string u , v;

    while(true){
        cout<<"\n1. Add User\n2. Add Friend\n3. Display\n4. Exit\n";
        cin>>choice;

        if(choice == 1){
            cin>>u;
            addUser(u);
        }
        else if(choice == 2){
            cin>>u>>v;
            addFriend(u , v);
        }
        else if(choice == 3){
            display();
        }
        else break;
    }
}
