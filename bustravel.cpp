#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int start, int dest, vector<vector<int>>& stop) {    
    bool check[100] = {false};
    queue<int> q;

    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        check[u] = true; 
        for (int v = 0; v < stop[u].size(); v++) {
            if (stop[u][v] == dest) {
                return 1;
            } else if (check[stop[u][v]] == false) {
                check[stop[u][v]] = true;
                q.push(stop[u][v]);
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int> > signs = {{0,1,0}, 
                                {0,0,1}, 
                                {1,0,0}};
    int n = 3;
    vector<vector<int>> stop;
    vector<vector<int> > answer;

    

    for (int i=0; i<n; i++) {
        vector<int> tmp1;
        vector<int> tmp2;
        for (int j=0; j<n; j++) {
            if (signs[i][j] == 1) {
                tmp1.push_back(j);
                tmp2.push_back(0);
            }
        }
        stop.push_back(tmp1);
        answer.push_back(tmp2);
    }

    for (int i = 0; i<n; i++) {
        for (int j= 0; j<n; j++) {
            answer[i][j] = BFS(i, j, stop);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << stop[i][j] << " ";
        }
        cout << endl;
    }
}