#include<vector>
#include <iostream>
#include <climits>
using namespace std;

// void max_heapify(vector<vector<int> >& arr, int i, int n) {
//     int l = 2*i +1;
//     int r = 2*i + 2;
//     int largest;
//     if (l < n && arr[l][1] > arr[i][1]) {
//         largest = l;
//     } else {
//         largest = i;
//     }
//     if ( r < n && arr[r][1] > arr[largest][1]) {
//         largest = r;
//     }
//     int first;
//     int second;
//     if (largest != i) {
//         first = arr[largest][0];
//         second = arr[largest][1];
//         arr[largest][0] = arr[i][0];
//         arr[largest][1] = arr[i][1];
//         arr[i][0] = first;
//         arr[i][1] = second;
//         if (largest <= i/2) {
//             max_heapify(arr, largest, n);
//         }
//     }
// }

// void build_max_heap(vector<vector<int> >& arr) {
//     int n = arr.size();
//     for (int i= arr.size()/2-1; i>=0; i--) {
//         max_heapify(arr, i, n);
//     }
// }

// void heapsort(vector<vector<int> >& arr) {
//     build_max_heap(arr);
//     int first;
//     int second;
//     for (int i=arr.size()-1; i>0; i--) {
//         first = arr[i][0];
//         second = arr[i][1];
//         arr[i][0] = arr[0][0];
//         arr[i][1] = arr[0][1];
//         arr[0][0] = first;
//         arr[0][1] = second;
//         int n = arr.size()-1;
//         max_heapify(arr, 0, n);
//     }
// }

void mergesort(vector<vector<int>>& v, int p, int r);
void merge(vector<vector<int>>& v, int p, int q, int r);

void mergesort(vector<vector<int>>& v, int p, int r) {
    if (p < r) {
        int q = (p+r) /2;
        mergesort(v, p, q);
        mergesort(v, q+1, r);
        merge(v, p, q, r);
    }
};

void merge(vector<vector<int>>& v, int p, int q, int r) {
    int n1 =  q - p + 1;
    int n2 = r - q;
    
    vector<vector<int>> L;
    vector<vector<int>> R;
    
    for (int i=0; i<n1; i++) {
        int first = v[p+i][0];
        int second = v[p+i][1];
        L.push_back({first, second});
    }
    for (int j=0; j<n2; j++) {
        int first = v[q+j+1][0];
        int second = v[q+j+1][1];
        R.push_back({first, second});
    }
    
    int d = INT_MAX;
    L.push_back({d, d});
    R.push_back({d, d});
    
    int i = 0;
    int j = 0;
    
    for (int k=p; k< r+1; k++) {
        if (L[i][1] <= R[j][1]) {
            v[k] = L[i];
            i = i + 1;
        } else {
            v[k] = R[j];
            j = j + 1;
        }
    }
};

int main()
{
    int answer = 0;
    vector<vector<int>> arr = {{1, 4}, {2, 6}, {4, 7}};
    mergesort(arr, 0, arr.size()-1);
    vector<int> s;
    vector<int> f;
    for (int i=0; i<arr.size(); i++) {
        s.push_back(arr[i][0]);
        f.push_back(arr[i][1]);
    }
    int n = s.size();
    answer = 1;
    int k = 0;
    for (int m = 1; m<n; m++) {
        if (s[m] >= f[k]) {
            answer++;
            k = m;
        }
    }
    cout << answer;
}