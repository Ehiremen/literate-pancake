//
// Created by: Ehiremen Ekore on 11/19/2019.
// File name:  unsortedMedian.cpp
//

#include <iostream>
#include <vector>

using namespace std;

int median(vector<int>& nums);
int count_less_eq(int n, vector<int>& nums);
int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<int> numsTwo = {1,1,2,2,5};
    vector<int> numsThree = {1,2,3,3,3,4,5};

    vector<vector<int>> testCases = {nums, numsTwo, numsThree};
    for(vector<int> k: testCases){
        cout << median(k) << endl << endl;
    }
    return 0;
}

int median(vector<int>& nums){
    int medCnt = (nums.size()&1) ? ((nums.size()+1)/2) : (nums.size()/2);
    //what count represents the median.
    // Not the index of median in sorted array; array index starts at 0

    int med;
    int lClosest, lCountClosest = 0;            //let the leftCount be as small
    int rClosest, rCountClosest = INT32_MAX;    //as can be, and rightCount as
                                                //large as can be.
    for(int k: nums){
        int tempCount = count_less_eq(k, nums); //get its cumulative count
        if (tempCount==medCnt) return k;
        else{
            if ((lCountClosest<tempCount) && (tempCount-medCnt)<0) {
                lCountClosest = tempCount;
                lClosest = k;
            }
            if((rCountClosest>tempCount) && ((tempCount-medCnt)>0)){
                rCountClosest = tempCount;
                rClosest = k;
            }
        }
    }
    cout << "lClosest: " << lClosest << " rClosest: " << rClosest << endl;
    med = (abs(rCountClosest-medCnt) <= abs(lCountClosest-medCnt)) ? rClosest : lClosest;
    return med;
}

int count_less_eq(int n, vector<int>& nums){
    int count=0;
    for(int k: nums){
        if (k <= n) count++;
    }
    return count;
}