#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

struct Element {
    int max_i;
    int max_j;
    int max;
};

void find_maximum_subarray(vector<int>& a, int low, int high, Element &e);
void find_max_crossing_subarray(vector<int>& a, int low, int mid, int high, Element &e);

void find_maximum_subarray(vector<int>& a, int low, int high, Element &e){
    if (high == low) {
        e.max_i = low;
        e.max_j = high;
        e.max = a[low];
    }
    else {
        int mid = (low+high)/2;
        find_maximum_subarray(a, low, mid, e);
        int left_low = e.max_i;
        int left_high = e.max_j;
        int left_sum = e.max;
        find_maximum_subarray(a, mid+1, high, e);
        int right_low = e.max_i;
        int right_high = e.max_j;
        int right_sum = e.max;
        find_max_crossing_subarray(a, low, mid, high, e);
        int cross_low = e.max_i;
        int cross_high = e.max_j;
        int cross_sum = e.max;

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            e.max_i = left_low;
            e.max_j = left_high;
            e.max = left_sum;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum) {
            e.max_i = right_low;
            e.max_j = right_high;
            e.max = right_sum;
        }
        else {
            e.max_i = cross_low;
            e.max_j = cross_high;
            e.max = cross_sum;
        }

    }
};

void find_max_crossing_subarray(vector<int>& a, int low, int mid, int high, Element &e){
    int left_sum = INT_MIN;
    int max_left;
    int sum = 0;

    for (int i= mid; i >= low; i--) {
        sum = sum + a[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right;

    for (int j=mid+1; j<=high; j++) {
        sum = sum + a[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    e.max_i = max_left;
    e.max_j = max_right;
    e.max = left_sum + right_sum;
};

int solution(vector<int> param0) {
    int answer = 0;

    Element e;
    find_maximum_subarray(param0, 0, param0.size()-1, e);
    answer = e.max;
    return answer;
}

int main() {
    int aa[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    //43
    vector<int> a(aa, aa+16);

    int answer = solution(a);

    cout << answer << endl;
}