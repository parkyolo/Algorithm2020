#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main() {
    vector<string> p, c;

    int n; string s;
    cin >> n;
    for (int i=0; i<n; i++) { cin >> s; p.push_back(s); }
    for (int i=1; i<n; i++) { cin >> s; c.push_back(s); }

    string answer = solution(p, c);
    cout << answer << endl;
}