#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double total = 0;
    double balance;
    for (int i = 0; i < 12; i++) {
        cin >> balance;
        total += balance;
    }
    cout << "$" << fixed << setprecision(2) << total / 12.0 << endl;
    return 0;
}