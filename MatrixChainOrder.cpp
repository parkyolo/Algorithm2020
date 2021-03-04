#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int main(void) {
    int n = 6;

    vector<int> v = {30, 35, 15, 5, 10, 20, 25}; //15125
    
    // solve here and print the result using cout 
    vector<vector<unsigned long>> m(n, vector<unsigned long>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<0; j++) {
            m[i][j] = 0;
        }
    }

    for (int l=1; l<n; l++) {
        for (int i=0; i<n-l; i++) {
            int j = i+l;
            m[i][j] = ULONG_MAX;
            for (int k = i; k< j; k++) {
                unsigned long q = m[i][k] + m[k+1][j] + v[i]*v[k+1]*v[j+1];
                if (q<m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    cout << m[0][n-1];
    return 0;
}