#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector <string> participant, vector<string> completion) 
{
    string answer = "";
    for(int i=0; i<participant.size(); i++) {
        answer = participant[i];
        auto it = find(completion.begin(), completion.end(), answer);
        if (it == completion.end() ) break; // completion.end() == blank. 찾는게 없을 때
        else completion.erase(it);
    }

    return answer;
    
}