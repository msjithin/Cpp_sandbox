#include <helloutility.h>

using namespace std;

void myPrintHelloMake() {

   vector<string> msg {"Hello", "World", "from", "C++", "VS Code", "and the C++ extension!"};

   for (const string& word : msg)
   {
      cout << word << " ";
   }
   cout << endl;
  return;
}

void myNumbersAndOperators(){

   int x;
   float y;
   float z1;
   int overflow_int;
   double double_int;

   x = 10 / 4;
   y = 10.4 / 1.0;
   z1 = 6.6267E-34 ;
   overflow_int = 6.626E10;
   double_int = 6.626E10;

   cout << "x=" << x << " and y=" << y << endl;
   cout << "overflow_int=" << overflow_int <<endl;
   cout << "double_int=" << double_int <<endl;

   int i;
   float f;

   f = 1E10;
   i = f;
   cout << "i=" << i << " and f=" << f << endl;



   // Unary 
   int unminus_i, unminus_j;
   unminus_i = -100;
   unminus_j = -i;

   int uplus_i, uplus_j;

   uplus_i = 100;
   uplus_j = +i;
   cout << "unminus_i=" << unminus_i << " and unminus_j=" << unminus_j << endl;
   cout << "uplus_i=" << uplus_i << " and uplus_j=" << uplus_j << endl;


   return ;
}

void char_sum(char &mychar1, char &mychar2 ){

   mychar1 = mychar1 + mychar2;
   cout << "character=" << mychar1 << endl;
   return ;
}

void char_sum(char &mychar1, int myint ){

   mychar1 = mychar1 + myint;
   cout << "character=" << mychar1 << endl;
   return ;
}

void myCharacters(){
   char character;

   character = 'A';
   cout << "character=" << character << endl;

   char_sum(character, 32);

   char_sum(character, ' ');


   character = 65;
   cout << "character=" << character << endl;
   char_sum(character, ' ');
   
   char Char = 'X';
   int Int = Char;

   cout << Char << " " << (int)Char << " " << Int << " " << (char)Int << endl;



   return ;
}