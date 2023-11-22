#include <iostream>
using namespace std;
int main() {
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
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
