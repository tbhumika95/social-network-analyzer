#include <bits/stdc++.h>
using namespace std;

unordered_map<string , vector<string>>graph;

pair<vector<string> , int>getShortestPath(string start , string end);

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

void suggestFriends(string user){
    if(graph.find(user) == graph.end()){
        cout<<"User does not Exists!"<<endl;
        return;
    }

    unordered_set<string> visited;
    unordered_set<string> suggestion;

    visited.insert(user);
    for(auto &f : graph[user]){
        visited.insert(f);
    }

    for(auto &f : graph[user]){
        for(auto &fof : graph[f]){
            if(!visited.count(fof)){
                suggestion.insert(fof);
            }
        }
    }

    cout<<"Friend Suggestions :\n";
    for(auto &s : suggestion){
        cout<<s<<endl;
    }
}

void suggestFriendSmart(string user){
    if(graph.find(user) == graph.end()){
        cout<<"Invalid User!\n";
        return;
    }

    unordered_set<string> directFriends ;
    unordered_map<string , int> mutualCount;

    for(auto &f : graph[user]){
        directFriends.insert(f);
    }

    for(auto &f : graph[user]){
        for(auto &fof : graph[f]){
            if(fof != user && !directFriends.count(fof)){
                mutualCount[fof]++;
            }
        }
    }

    if(mutualCount.empty()){
        cout<<"No Smart Suggestions Available!";
        return;
    }

    vector<pair<string,int>>result(mutualCount.begin() , mutualCount.end());
    sort(result.begin() , result.end() ,[](auto &a , auto &b){
        return a.second > b.second;
    });

    cout<<"Smart Suggestions :\n";
    for(auto &p : result){
        string suggestuser = p.first;

        auto pathData = getShortestPath(user , suggestuser);

        cout<<suggestuser<<" (Mutual : "<<p.second<<" , Level : "<<pathData.second<<")\n";

        cout<<"Connection : ";
        for(auto &node : pathData.first){
            cout<<node<<" ";
        }
        cout<<"\n\n";
    }
}

pair<vector<string> , int>getShortestPath(string start , string end){
    unordered_map<string , string>parent;
    unordered_set<string>visited;
    queue<string>q;

    q.push(start);
    visited.insert(start);

    bool found = false;

    while(!q.empty()){
        string curr = q.front();
        q.pop();

        if(curr == end){
            found = true;
            break;
        }

        for(auto &neighbor : graph[curr]){
            if(!visited.count(neighbor)){
                visited.insert(neighbor);
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    if(!found)return{{} , -1};

    vector<string>path;
    string curr = end;

    while(curr != start){
        path.push_back(curr);
        curr = parent[curr];
    }

    path.push_back(start);

    reverse(path.begin() , path.end());

    return{path , (int)path.size() -1};
}


int main(){
    int choice;
    string u , v;

    while(true){
        cout<<"\n1. Add User\n2. Add Friend\n3. Display\n4. Suggest Friends\n5. Smart Suggestion\n6. Exit\n";
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
        else if(choice == 4){
            cin>>u;
            suggestFriends(u);
        }
        else if(choice == 5){
            cin>>u;
            suggestFriendSmart(u);
        }
        else break;
    }
}
