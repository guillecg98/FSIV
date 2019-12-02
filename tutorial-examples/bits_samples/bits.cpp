//! \file bits.cpp
//! Bit-wise operations
//! (c) MJMJ/2019

#include <iostream>
#include <bitset>

using namespace std;

int main(int argc, char * argv[])
{
   unsigned char anumber=1;
   
   cout << "Size of uchar: " << sizeof(anumber)*8 << " bits" << endl;
   cout << std::bitset<8>(anumber) << endl;
   
   /// Let's see how shifting works
   
   for (int i = 0; i < 8; i++)
   {
      anumber = anumber << 1;      
      cout << "# Displaced: " << i+1 << "--> ";
      cout << std::bitset<8>(anumber) << " ";
      cout << std::hex << anumber << endl;
   }

   /// Let's see how bit-wise binary operators work
   cout << endl << "Using OR operator" << endl;
   // Let's place a 1 in position 5th (starting from right side)
   anumber = anumber | (1 << 4);
   cout << std::bitset<8>(anumber) << endl;
   
   // Let's place a 1 in position 8th (starting from right side)
   anumber = anumber | (1 << 7);
   cout << std::bitset<8>(anumber) << endl;
	
   return 0;
}
