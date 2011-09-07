
#include <iostream>
#include "MyRngStream.h"
using namespace std;


void test2() {
        RngStream g1 ("g1");
        RngStream g2 ("g2");
        RngStream g3 ("g3");

        cout << "0-511" << endl << endl;
        for ( int i = 0; i < 512; ++i) {
                cout << g1.U01() << endl;
                g1.ResetNextSubstream();
        }
        cout << endl << "512-1023" << endl << endl;
        for ( int i = 0; i < 512; ++i) {
                cout << g2.U01() << endl;
                g2.ResetNextSubstream();
        }
        cout << endl << "1024-1535" << endl << endl;
        for ( int i = 0; i < 512; ++i) {
                cout << g3.U01() << endl;
                g3.ResetNextSubstream();
        }
}


int main(int, char**) {
        //      test1();
        test2();
        return 0;
}

