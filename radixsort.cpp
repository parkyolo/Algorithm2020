#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int digit16(int v, int d){
// 양의 정수 v 의 16진수 d 번째 숫자를 반환하는 함수
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 1 이라면 6 을 반환
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 4 라면 11 (= 0xb) 을 반환
  v = v >> d*4;
  return v & 0xf;
}

void countingSort16(vector<pair<int, string> >& v,int d) {
    vector<int> a(v.size());
    vector<pair<int, string> > b;
    vector<int> c(16);

    for (int i=0; i<v.size(); i++) {
        a[i] = digit16(v[i].first, d);
    }
    for (int i=0; i<v.size(); i++) {
        b.push_back(pair<int,string>(0, ""));
    }
    for (int i=0; i<v.size(); i++) {
        c[a[i]] ++;
    }
    for (int i=1; i<c.size(); i++) {
        c[i] = c[i] + c[i-1];
    }
    for (int i=v.size()-1; i>=0; i--) {
        b[c[a[i]]-1].first = v[i].first;
        b[c[a[i]]-1].second = v[i].second;
        c[a[i]] = c[a[i]]-1;
    }

    v = b;

}

int main(void) {
    int n = 5;
    vector<pair<int, string> > v;

    v.push_back(pair<int,string>(10000, "mac"));
    v.push_back(pair<int,string>(10000, "debian"));
    v.push_back(pair<int,string>(10000, "redhat"));
    v.push_back(pair<int,string>(5555555, "windows"));
    v.push_back(pair<int,string>(99, "ubuntu"));

    // 99 ubuntu
    // 10000 mac
    // 10000 debian
    // 10000 redhat
    // 5555555 windows

    //radixsort
    for (int d=2; d<5; d++) countingSort16(v, d);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}