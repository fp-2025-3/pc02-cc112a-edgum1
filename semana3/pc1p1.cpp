#include <iostream>

using namespace std;

void supdig(int n){
    while(n>=10){
        n = (n/1000%10)+(n/100%10)+(n/10%10)+(n%10);
    }
    cout << "El super digito es: " << n << endl;
}

int main(){
    int n;
    cout << "digite el numero: "<<endl;
    cin >>n;
    supdig(n);
    return 0;
}       