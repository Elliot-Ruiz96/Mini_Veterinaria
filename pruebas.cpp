#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 string s;
 ifstream f( "salida.txt" );
 if ( f.is_open() ) {
 getline( f, s );

 while( !f.eof() ) {
 cout << s << endl;

 getline( f, s );
 }
 }
 else cerr << "Error de apertura del archivo." << endl;
}
