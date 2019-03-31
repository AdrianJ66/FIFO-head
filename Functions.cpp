#include "global.h"
#include <iostream>

using namespace std;

void QfCreate( FQueue* q )
{	
	qfifoItem* v = ( qfifoItem* )malloc( sizeof( qfifoItem ) );
	if ( v )
	{
		v->nKey = 0;
		v->pNext = NULL;
		q->pHead = v;
		q->pTail = v;
	}
	else
	{
		printf( "Nie udalo sie utworzyc kolejki. \n" );
	}
}

int QFEmpty( FQueue* q )
{
	return !( q->pHead->pNext );
}

void QFEnqueue( FQueue* q, int pInfo )
{
	qfifoItem* v = ( qfifoItem* )malloc( sizeof( qfifoItem ) );

	if ( v )
	{
		v->nKey = pInfo;
		v->pNext = NULL;

		q->pTail->pNext = v;
		q->pTail = v;
	}
	else
	{
		perror( "ERROR: FIFO overflow!!\n" );
	}
}

int QFDequeue( FQueue* q )
{
	if ( !QFEmpty( q ) )
	{
		qfifoItem* v = q->pHead->pNext;		//wskaznik pomocniczy na element do sciagniecia
		int deitem = v->nKey;
		q->pHead->pNext = v->pNext;

		if ( !( q->pHead->pNext ) ) q->pTail = q->pHead;
		free( v );
		
		return deitem;
	}
	else
	{
		perror( "ERROR: FIFO underflow!!\n" );
		return -1;
	}
}

void QFRemove( FQueue* q )
{
	while ( !QFEmpty( q ) )
	{
		QFDequeue( q );
	}
	q = NULL;
}

void QFPrint( FQueue* q )
{
	if ( !QFEmpty( q ) )
	{
		qfifoItem* v = q->pHead;
		printf( "Kolejka sklada sie z nastepujacych elementow: \n" );
		while ( v )
		{
			printf( "%d ", v->nKey );
			v = v->pNext;
		}
		printf( "\n" );
	}
	else
	{
		printf( "Kolejka jest pusta. \n" );
	}
}