#include <iostream>
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::ostream;
#include <string>
using std::string;

class Base{
public:
    virtual int fcn() {cout << "Base::fcn" << endl; return EXIT_SUCCESS;};
};

class D1 : public Base {
public:
    int fcn() override {cout << "D1::fcn" << endl; return EXIT_SUCCESS;};
};

class D2 : public D1 {
public:
    int fcn() override {cout << "D2::fcn" << endl; return EXIT_SUCCESS;};
};

int main(){
    Base bobj;
    D1 d1obj;
    D2 d2obj;

    Base *bp1 = &bobj;
    D1 *bp2 = &d1obj;
    D2 *bp3 = &d2obj;

    bp1->fcn();
    bp2->fcn();
    bp3->fcn();
}