#include <iostream>
#include <vector>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // return the minimum number of intervals you need to
    // remove to make the rest of the intervals non-overlapping.

    vector<vector<int>> arr;
    arr.push_back(intervals[0]);

    int index = 0;

    for (int i = 1; i < intervals.size(); i++) {
        if (arr[index][1] >= intervals[i][0]) {
            arr[index][1] = arr[index][1] > intervals[i][1] ? arr[index][1] : intervals[i][1];
        } else {
            index++;
            arr.push_back(intervals[i]);
        }
    }

    return intervals.size() - arr.size();

}


int main() {
    vector<vector<int>> intervals =  {{1,2},{2,3},{3,4},{1,3}};
    int result = eraseOverlapIntervals(intervals);

    cout << result;

    return 0;
}
