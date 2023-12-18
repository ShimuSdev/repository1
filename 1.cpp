//Algorithm Lab 8
//Cycle finding and printing
#include <bits/stdc++.h>
using namespace std;
const int n = 100005;
vector<int> grph[n];
vector<int> cycles[n];
int color[n];
int par[n];
int mark[n];
int flag = 0;

void DFS_cycle(int u, int p, int &cycleNumber){
    if (color[u] == 2){
        return;
    }

    if (color[u] == 1){
        cycleNumber++;
        int cur = p;
        mark[cur] = cycleNumber;

        while (cur != u){
            cur = par[cur];
            mark[cur] = cycleNumber;
        }
        return;
    }

    par[u] = p;
    color[u] = 1;

    for (int v : grph[u]){
        if (v == par[u]){
            continue;
        }
        DFS_cycle(v, u, cycleNumber);
    }
    color[u] = 2;
}

void printCycles(int edges, int &cycleNumber){
    for (int i = 1; i <= edges; i++){
        if (mark[i] != 0){
            cycles[mark[i]].push_back(i);
        }
    }

    for (int i = 1; i <= cycleNumber; i++){
        cout << "YES" << endl;
        flag = 1;
        for (int x : cycles[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        grph[u].push_back(v);
        grph[v].push_back(u);
    }

    int cycleNumber = 0;

    DFS_cycle(1, 0, cycleNumber);
    printCycles(E, cycleNumber);

    if(!flag){
        cout<<"NO"<<endl;
    }
}
