#ifndef _DATA_H
#define _DATA_H

typedef struct Data tData;
tData* CriaData(int dia,int mes,int ano);
void LiberaData(tData* data);


#endif