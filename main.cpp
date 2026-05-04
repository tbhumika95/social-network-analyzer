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
    cout<<"Added "<<user<<" successfully !!\n";
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

    cout<<a<<" and "<<b<<" are Friends Now!!\n";

}

void display(){
    if(graph.empty()){
    cout<<"No users in network!\n";
    return;
    }
    cout<<"Social Network : \n";
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
        cout<<"User: "<<s<<endl;
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
        return a.second > b.second || 
      (a.second == b.second && a.first < b.first);
    });

    cout<<"Smart Suggestions :\n";
    for(auto &p : result){
        string suggestuser = p.first;

        auto pathData = getShortestPath(user , suggestuser);

        cout<<"User : "<<suggestuser<<"\n";
        cout<<"Mutual Friends : "<<p.second<<"\n";
        cout<<"Connection Level : "<<pathData.second<<"\n";
        cout<<"Path : ";
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


void dfs(string user , unordered_set<string>&visited ,vector<string>&cluster){
    visited.insert(user);
    cluster.push_back(user);

    for(auto &neighbor : graph[user]){
        if(!visited.count(neighbor)){
            dfs(neighbor , visited , cluster);
        }
    }
}

int getInfluenceScore(string user){
    unordered_set<string> indirect;
    unordered_set<string> directSet(graph[user].begin(), graph[user].end());

    int direct = graph[user].size();

    for(auto &f : graph[user]){
        for(auto &fof : graph[f]){
            if(fof != user && !directSet.count(fof)){
                indirect.insert(fof);
            }
        }
    }

    return 2*direct + indirect.size();
}


void findClusters(){
    if(graph.empty()){
    cout<<"No users in network!\n";
    return;
    }
    unordered_set<string>visited;

    int globalMax = -1;
    vector<string> globalUsers;

    cout<<"\n=====Communities=====\n";
    for(auto &p : graph){
        string user = p.first;

        if(!visited.count(user)){
            vector<string>cluster;

            dfs(user , visited , cluster);

            cout<<"\nCluster : ";
            for(auto &u : cluster){
                cout<<u<<" ";
            }
            cout<<"\n";

            string topUser = "";
            int maxScore = -1;

            for(auto & u : cluster){
                int score = getInfluenceScore(u);
                cout<<"User : "<<u<<" | Influence Score: "<<score<<"\n";

                if(score > maxScore){
                    maxScore = score;
                    topUser=u;
                }

                if(score > globalMax){
                    globalMax = score;
                    globalUsers.clear();
                    globalUsers.push_back(u);
                }
                else if(score == globalMax){
                    globalUsers.push_back(u);
                }
            }

            cout<<"Top Influencer : "<<topUser<<"(Score : "<<maxScore<<")\n";
        }
    }
    cout<<"\nGlobal Top Influencer(s): ";
    for(auto &u : globalUsers){
        cout<<u<<" ";
    }
    cout<<"(Score : "<<globalMax<<")\n";
}

int main(){
    int choice;
    string u , v;

    while(true){
        cout<<"\n=====Social Network Analyzer=====\n";
        cout<<"1. Add User\n2. Add Friendship\n3. Display Network\n4. Suggest Friends\n5. Smart Suggestion\n6. Show Community with Influence\n7. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice == 1){
            cout<<"Enter User : ";
            cin>>u;
            addUser(u);
        }
        else if(choice == 2){
            cout<<"Enter First User : ";
            cin>>u;
            cout<<"Enter Second User : ";
            cin>>v;
            addFriend(u , v);
        }
        else if(choice == 3){
            display();
        }
        else if(choice == 4){
            cout<<"Enter your name :";
            cin>>u;
            suggestFriends(u);
        }
        else if(choice == 5){
            cout<<"Enter your name :";
            cin>>u;
            suggestFriendSmart(u);
        }
        else if(choice == 6){
            findClusters();
        }
        else break;
    }
}
