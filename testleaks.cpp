#include <iostream>

using namespace std;

class A{
public:
    A() { a = new int[10]; };
    ~A() { delete[] a; };
private:
    int* a;
};

int main(int argc, char** argv)
{
    A a;

    return 0;
}