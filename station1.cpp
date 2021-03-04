#include <iostream>
#include <vector>
using namespace std;


void fill(vector<int>& apt, int station, int n, int w) {
    for (int j=0; j<w; j++) {
        if (station+j+1 <= n) {
            apt[station+j+1] = 1;
        }
        if (station-j-1 >= 0) {
            apt[station-j-1] = 1;
        }
    }
    apt[station] = 1;
}

int check0(vector<int>& apt) {
    for (int i=0; i<apt.size(); i++) {
        if (apt[i] == 0) {
            return i;
        }
    }
    return -1;
}

int check1(vector<int>& apt, int where0) {
    for (int i=where0; i<apt.size(); i++) {
        if (apt[i] == 1) {
            return i;
        }
    }
    return -1;
}

void find(vector<int>& apt, int n, int w, int& count) {
    int where0 = check0(apt);
    int where1 = check1(apt, where0);
    if (where1 == -1) {
        where1 = n+1;
    }
    int find = (where0+where1-1)/2;
    fill(apt, find, n , w);
    count++;
}

int solution(int n, vector<int> stations, int w)
{
    vector<int> apt(n);
    int idx = n-1;
    for(int i=0; i<stations.size(); i++) {
        int station = stations[i]-1;
        fill(apt, station, idx , w);
    }

    int count = 0;
    while(check0(apt)!=-1) {
        find(apt, idx, w, count);
    }
    

    return count;
}

int main() {
    int n = 16;
    
    vector<int> stations = {9};

    int w = 2;

    int answer = solution(n, stations, w);

    cout << answer << endl;
}