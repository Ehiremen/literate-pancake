//https://www.hackerrank.com/challenges/alternating-characters/

int alternatingCharacters(string s) {
    int numToDelete = 0;
    char previousChar = s[0];

    for (int i=1; i<s.length(); i++){
        if(s[i]==previousChar){
            numToDelete++;
        }
        else {
            previousChar = s[i];
        }
    }
    return numToDelete;
    }
