// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int a, b;
    cin >> a >> b;
    
    for(int i = 0; i < b; i++){
        if(i == 0 || i == (b - 1)){
            for(int j = 0; j < b; j++){
                cout << "=";
            }
        } else {
            for(int k = 0; k <= a; k++){
                if(k == 0 || k == (a)){
                    cout << "=";
                } else{
                    cout << "x";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
