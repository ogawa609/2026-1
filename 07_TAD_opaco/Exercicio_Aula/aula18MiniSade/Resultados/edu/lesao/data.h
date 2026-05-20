
#ifndef _DATA_H
#define _DATA_H

//definicao da struct de data
typedef struct Data tData;

tData* leData();
void printData(tData* d);
int retornaAno(tData* inicio);
void liberaData(tData *d);

#endif
