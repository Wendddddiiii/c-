#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int age = 21;
    int *pAge = &age;
    double gpa = 4.0;
    double *pGpa = &gpa;
    string name = "Mike";
    string *pName = &name;
    cout << fixed << setprecision(1) << *pGpa << endl;
    cout << *pAge << endl;
    cout << *pName << endl;
    return 0;
}