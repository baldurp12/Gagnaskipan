#include "palindrome.h"
#include <iostream>
#include <cstring>
#include "palindrome.h"

using namespace std;

bool palindrome(const char a[], int first, int last){

    if(a[first] == a[last]){
        return palindrome(a, a[first+1], a[last-1]);
    }
    else if(first > last){
        return true;
    }
    return false;

}
