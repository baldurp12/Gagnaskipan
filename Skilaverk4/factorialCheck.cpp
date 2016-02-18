#include <iostream>
using namespace std;


int main(){
    int multiple = 1;
    int num = 6;
    for(int factorial = 1; factorial <= num; factorial++){
        multiple *= factorial;
    }
    cout << multiple << endl;

    return 0;
}
