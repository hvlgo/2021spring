#include "Test.h"
int Test::count = 0;
const Test& F(const Test& a){
    Test b = a;
    return Test(1);
}
int main() {
    Test a;
    const Test &A = F(std::move(a));
    return 0;
}