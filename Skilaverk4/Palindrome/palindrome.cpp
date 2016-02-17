#include "palindrome.h"


bool palindrome(const char a[], int first, int last){

    if(a[first] == a[last] && last > first){
        return palindrome(a, first+1, last-1);
    }
    else if(first >= last){
        return true;
    }
    return false;

}
