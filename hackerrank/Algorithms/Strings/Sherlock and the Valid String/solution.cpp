string isValid(string s) {
    string isValidString = "NO";
    string uniques; 
    vector<int>freq;
    int countDiff = 0;
    int testFreq;

    //initialize uniques and frequencies
    for(int i=0; i<s.length(); i++){
        size_t found;
        found=uniques.find(s[i]);
        if (found!=string::npos){ //if char is found in uniques, update the count in freq
        freq[found] ++;
        }
        else{
            uniques += s[i];
            freq.emplace_back(1);
        }   
    }

    //make sure that there's at least 2 occurrences of the frequency we're checking the others against
    //this way, we avoid errors if the first frequency is the one making the string invalid
    if (uniques.length()>2){
        if(freq[0]==freq[1]){
            testFreq = freq[0];
        }
        else{
            testFreq = freq[2];
        }
    }
    else{
        testFreq = freq[0];
    }

    for(int k=0; k<uniques.length(); k++){
        countDiff += abs(testFreq - freq[k]);
    }
    if (countDiff < 2){
        isValidString = "YES";
    }
    if ((testFreq - countDiff) == 1){
        isValidString = "YES";
    }

    // if(equal(freq.begin()+1, freq.end(), freq.begin())){
    //     isValidString = "YES";
    // }

    return isValidString;
}
