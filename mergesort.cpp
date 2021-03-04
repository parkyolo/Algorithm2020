#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

void mergesort(vector<pair<int, string> >& v, int p, int r);
void merge(vector<pair<int, string> >& v, int p, int q, int r);

void mergesort(vector<pair<int, string> >& v, int p, int r) {
    if (p < r) {
        int q = (p+r) /2;
        mergesort(v, p, q);
        mergesort(v, q+1, r);
        merge(v, p, q, r);
    }
};

void merge(vector<pair<int, string> >& v, int p, int q, int r) {
    int n1 =  q - p + 1;
    int n2 = r - q;
    
    vector<pair<int, string>> L;
    vector<pair<int, string>> R;
    
    for (int i=0; i<n1; i++) {
        int d = v[p+i].first;
        string s = v[p+i].second;
        L.push_back(pair<int,string>(d,s));
    }
    for (int j=0; j<n2; j++) {
        int d = v[q+j+1].first;
        string s = v[q+j+1].second;
        R.push_back(pair<int,string>(d,s));
    }
    
    int d = INT_MIN;
    string s = "a";
    L.push_back(pair<int,string>(d,s));
    R.push_back(pair<int,string>(d,s));
    
    int i = 0;
    int j = 0;
    
    for (int k=p; k< r+1; k++) {
        if (L[i].first >= R[j].first) {
            v[k] = L[i];
            i = i + 1;
        } else {
            v[k] = R[j];
            j = j + 1;
        }
    }
};

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

    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}