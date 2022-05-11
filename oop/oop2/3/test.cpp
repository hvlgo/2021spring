#include <iostream>
using namespace std;
int x;
int & getx()
{
    return x;
}
int & add()
{
    return getx();
}

int main()
{
    cin >> x;
    int & y = x;
    cout << x << ' ' << y << endl;
    y = 2;
    cout << x << " " << y << endl;
    add() = 15;
    cout << x << " " << y << endl;
}