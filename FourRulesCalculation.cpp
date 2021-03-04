#include <vector>
#include <string>
#include <climits>

using namespace std;

int solution(vector<string> arr)
{
    vector<int> num;
    vector<char> oper;
    
    for (size_t i = 0; i < arr.size(); ++i)
        if (i % 2 == 0)
            num.push_back(stoi(arr[i]));
        else
            oper.push_back(arr[i].front());
    
    vector<vector<int>> s(num.size(), vector<int>(num.size(), INT_MAX));
    vector<vector<int>> m(num.size(), vector<int>(num.size(), INT_MIN));
    for (int i = 0; i < num.size(); ++i)
        s[i][i] = m[i][i] = num[i];
    
    for (int d = 1; d < num.size(); ++d) {
        for (int i = 0, k = d; k < num.size(); ++i, ++k) {
            for (int j = i; j < k; ++j) {
                if (oper[j] == '+') {
                    s[i][k] = min(s[i][k], s[i][j] + s[j + 1][k]);
                    m[i][k] = max(m[i][k], m[i][j] + m[j + 1][k]);
                } else if (oper[j] == '-') {
                    s[i][k] = min(s[i][k], s[i][j] - m[j + 1][k]);
                    m[i][k] = max(m[i][k], m[i][j] - s[j + 1][k]);
                }
            }
        }
    }
    return m[0][num.size() - 1];
}
