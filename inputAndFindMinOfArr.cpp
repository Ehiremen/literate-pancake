#include <iostream>
#include <vector>
#define QUIT_INPUT -99
using namespace std;


void readInput(vector<int> &arrToSort);
int recursiveMinimumArray(int *currentMin, int noOfUncheckedMembers, vector<int> arrToSort);

int main() {
	vector<int> arrToSort;
	int minOfArr, noOfUncheckedMembers;
	int *minPtr;
	minPtr = &minOfArr;
	
	cout << "Hi, we're going to take in your list of INTEGERS and fid the min." << endl;
	readInput(arrToSort);
	
	cout << "Your numbers: " << endl;
	for(int t=0; t<arrToSort.size(); ++t){
	    cout << arrToSort[t] << " ";
	}
	
	if (arrToSort.size() == 0){
	    cout << "No values entered; no minimum value" << endl;
	} else {
	    noOfUncheckedMembers = arrToSort.size();
	    minOfArr = arrToSort[0];
	    
	    int finalMin = recursiveMinimumArray(&minOfArr, noOfUncheckedMembers, arrToSort);
	    
	    cout << "\nThe minimum value is " << finalMin << endl;
	}

	return 0;
}

void readInput(vector<int> &arrToSort){
    int addValToArr;
    cout << "Input your INTEGERS; press ENTER after each number" << endl;
    cout << "Input -99 to terminate input" << endl;
    
    while (1){
        cin >> addValToArr;
        if (addValToArr == QUIT_INPUT) break;
        arrToSort.push_back(addValToArr);
    }
}

int recursiveMinimumArray(int *currentMin, int noOfUncheckedMembers, vector<int> arrToSort){
    if (*currentMin > arrToSort[0]){
            *currentMin = arrToSort[0];
        }
        arrToSort.erase(arrToSort.begin());
    if (noOfUncheckedMembers == 1){
        return (*currentMin);
    } else{
        return recursiveMinimumArray(currentMin, noOfUncheckedMembers-1, arrToSort);
    }
}