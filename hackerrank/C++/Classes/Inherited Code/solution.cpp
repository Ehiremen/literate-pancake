//https://www.hackerrank.com/challenges/inherited-code/problem

#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException : public exception{
    int length;
    public:
        BadLengthException (int n){
            this->length = n;
        }
        int what(){
                return length;
        }
};
