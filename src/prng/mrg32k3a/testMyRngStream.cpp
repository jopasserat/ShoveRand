/*  Programme pour tester le generateur   RngStream.cpp         */

#include <iostream>
#include "MyRngStream.h"
using namespace std;

void test1 ()
{

   RngStream g1 ("g1");
   RngStream g2 ("g2");
   RngStream g3 ("g3");
   
   MySubstream myrng1(g1);
   MySubstream myrng2(g2);
   MySubstream myrng3(g3);

   const unsigned JUMP = 1000;
   
   
   cout << "Output for g1" << endl;
   
   for (unsigned i = 0; i < 20; ++i) {
      cout << g1.U01() << " ";
      if (i % 5 == 0) cout << endl;
   }
   cout << endl << endl << endl;

   
   cout << "Output for myrng1" << endl;
   
   for (unsigned i = 0; i < 20; ++i) {
      cout << myrng1.next() << " ";
      if (i % 5 == 0) cout << endl;
   }
   cout << endl << endl << endl;   
   
   
   
   cout << "Output for g1 after call to ResetNextSubstream *" << JUMP << endl;
   
   for (unsigned i = 0; i < JUMP; ++i) {
      g1.ResetNextSubstream();      
   }

   
   for (unsigned i = 0; i < 20; ++i) {
      cout << g1.U01() << " ";
      if (i % 5 == 0) cout << endl;
   }
   cout << endl << endl << endl;
   
   
   cout << "Output for myrng1 after call to jumpAhead *" << JUMP << endl;

   for (unsigned i = 0; i < JUMP; ++i) {
      myrng1.jumpAhead(i);   
   }
   
   
   for (unsigned i = 0; i < 20; ++i) {
      cout << myrng1.next() << " ";
      if (i % 5 == 0) cout << endl;
   }
   cout << endl << endl << endl;;   
   
   
   
   
   
   
   cout << "Output for g2 after call to ResetNextSubstream *" << JUMP << endl;
   
   for (unsigned i = 0; i < JUMP; ++i) {
      g2.ResetNextSubstream();      
   }
   
   
   for (unsigned i = 0; i < 100; ++i) {
      cout << g2.U01() << " ";
      if (i % 5 == 0) cout << endl;
   }
   cout << endl << endl << endl;
   
   cout << "Output for myrng2 after call to jumpAhead *" << JUMP << endl;
   
   for (unsigned i = 0; i < JUMP; ++i) {
      myrng2.jumpAhead(i);   
   }
   
   
   for (unsigned i = 0; i < 100; ++i) {
      cout << myrng2.next() << " ";
      if (i % 5 == 0) cout << endl;
   }
   cout << endl;   
   
}

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
	//	test1();
	test2();
	return 0;
}

