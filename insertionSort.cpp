#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
    int n;
    vector<pair<int, string> > v;
    
    cin >> n;
    
    for (int i=0; i<n; i++){
        int d;
        string s;
        cin >> d >> s;  
        v.push_back(pair<int,string>(d,s));
    }
    
    // insertion sort

    pair<int, string> key;

    for (int j=1; j<v.size(); j++) {
        key = v[j];
        int i = j-1;
        while (i >=0 and v[i].first > key.first) {
            v[i+1] = v[i];
            i = i -1;
        }
        v[i+1] = key;
    }
    
    // output 
    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;          
    }

    return 0;
}