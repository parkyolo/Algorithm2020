#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    
    int right, left;
    int start = 1;
    int count = 0;

    for(int i=0; i<stations.size(); i++) {
        int station = stations[i];
        left = station-w-1;
        right = station+w+1;
        if (start > left) {
            start = right;
        } else {
            count += (left-start)/(2*w+1) + 1;
            start = right;
        }
        
    }

    if (start < n) {
        count += (n-start)/(2*w+1) + 1;
    }   

    return count;
}

int main() {
    int n = 11;
    
    vector<int> stations = {4,11};

    int w = 1;

    int answer = solution(n, stations, w);

    cout << answer << endl;
}