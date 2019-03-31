#ifndef GLOBAL_H
#define GLOBAL_H

typedef struct TagQFIFOitem
{
	int nKey;
	TagQFIFOitem* pNext;
} qfifoItem;

typedef struct
{
	qfifoItem* pTail;
	qfifoItem* pHead;
}FQueue;

void QfCreate( FQueue* q );
int QFEmpty( FQueue* q );
void QFEnqueue( FQueue* q, int pInfo );
int QFDequeue( FQueue* q );
//void QFClear( FQueue* q ); //czysci wszystkie podlaczone elementy dynamiczne
void QFRemove( FQueue* q );
void QFPrint( FQueue* q );



#endif

