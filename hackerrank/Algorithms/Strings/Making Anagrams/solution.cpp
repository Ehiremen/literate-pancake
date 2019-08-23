https://www.hackerrank.com/challenges/ctci-making-anagrams/

int makeAnagram(string a, string b) {
    int numToDelete = 0;
    string temp = a;
    
    for(int i=0; i<temp.length(); i++){
        size_t found = b.find(temp[i]);
        if(found != string::npos){ //if string was found
            a.erase(a.begin() + a.find(temp[i]));
            b.erase(b.begin() + b.find(temp[i]));
        }
    }
    numToDelete = a.length() + b.length();
    return numToDelete;
}
