// FIFOhead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "global.h"
#include <iostream>

using namespace std;

int main()
{
	FQueue q;

	QfCreate( &q );

	for ( int i = 1; i < 11; i++ )
	{
		QFEnqueue( &q, i );
	}

	printf( "Kolejka pierwotna: \n" );
	QFPrint( &q );

	QFDequeue( &q );
	printf( "Kolejka po usunieciu elementu: \n" );
	QFPrint( &q );

	QFDequeue( &q );
	printf( "Kolejka po usunieciu elementu: \n" );
	QFPrint( &q );

	QFRemove( &q );
	QFPrint( &q );
}

