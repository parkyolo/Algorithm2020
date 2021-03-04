#include <iostream>
#include <vector>
using namespace std;


void fill(vector<int>& apt, int station, int n, int w) {
    
    if (station > n-w) {
        for (int j=station; j<n; j++) {
            apt[j+1] = 1;
        }
        if (station >= w) {
            for (int j=0; j<w; j++) {
                apt[station-j-1] = 1;
            }
        } else {
            for (int j=0; j<station; j++) {
                apt[j] = 1;
            }
        }
    }
    if (station < w) {
        for (int j=0; j<station; j++) {
            apt[j] = 1;
        }
        if (station <= n-w) {
            for (int j=0; j<w; j++) {
                apt[station+j+1] = 1;
            }
        } else {
            for (int j=station; j<n; j++) {
                apt[j] = 1;
            }
        }
    }
    if (station <= n-w && station >= w) {
        for (int j=0; j<w; j++) {
            apt[station-j-1] = 1;
            apt[station+j+1] = 1;
        }
    }
    apt[station] = 1;
}

bool check0(vector<int>& apt) {
    for (int i=0; i<apt.size(); i++) {
        if (apt[i] == 0) {
            return true;
        }
    }
    return false;
}

int find(vector<int>& apt, int n, int w) {
    int max, min;
    int i = 0;
    int find = 0;
    int count = 0;
    bool check;
    while(check = check0(apt)) {
        do {
            min = i;
            i++;
        } while(apt[i-1] != 0);
        do {
            max = i;
            i++;
            if (i>n) {
                max = n;
                i=n;
                break;
            }
        } while(apt[i] != 1);
        if (max-min == 1) {
            find = (max+min)/2;
            fill(apt, find, n , w);
        }
        else {
            find = (max+min)/2;
            fill(apt, find, n , w);
        }
        count++;
        i = find + w ;       

    }
    return count;
}

int solution(int n, vector<int> stations, int w)
{
    vector<int> apt(n);
    int idx = n-1;
    for(int i=0; i<stations.size(); i++) {//size=16
        int station = stations[i]-1; //8 혹은 14
        fill(apt, station, idx , w);
    }

    int count = find(apt, idx, w);

    return count;
}

int main() {
    int n = 16;
    
    vector<int> stations = {9};

    int w = 2;

    int answer = solution(n, stations, w);

    cout << answer << endl;
}