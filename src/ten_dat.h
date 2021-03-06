#ifndef ten_dat_h
#define ten_dat_h
#include "ten.h"
#include "ten_types.h"

typedef struct DatInfo DatInfo;
struct DatInfo {
    DatInfo* next;
    
    ten_Var typeVar;
    Tup     typeTup;
    TVal*   typePtr;
    TVal    typeVal;
    size_t size;
    uint   nMems;
    void   (*destr)( void* buf );
};

struct Data {
    DatInfo* info;
    TVal*    mems;
    char     data[];
};

#define datSize( STATE, DAT ) (sizeof(Data) + (DAT)->info->size)
#define datTrav( STATE, DAT ) (datTraverse( STATE, DAT ))
#define datDest( STATE, DAT ) (datDestruct( STATE, DAT ))

void
datInit( State* state );

DatInfo*
datAddInfo( State* state, ten_DatConfig* config );

Data*
datNew( State* state, DatInfo* info );

void
datTraverse( State* state, Data* data );

void
datDestruct( State* state, Data* data );

#endif
