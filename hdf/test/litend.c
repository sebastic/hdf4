#include "tproto.h"

/* External Variables */
extern int num_errs;
extern int Verbocity;

/* Internal Variables */
#define CDIM_X  7
#define CDIM_Y  9

#define FILENAME    "litend.dat"
#define TMPFILE     "temp.hdf"

#ifdef TEST_PC
#define FAR far
#else
#define FAR /* */
#endif

static int8 FAR cdata_i8[CDIM_Y][CDIM_X];
static uint8 FAR cdata_u8[CDIM_Y][CDIM_X];
static int16 FAR cdata_i16[CDIM_Y][CDIM_X];
static uint16 FAR cdata_u16[CDIM_Y][CDIM_X];
static int32 FAR cdata_i32[CDIM_Y][CDIM_X];
static uint32 FAR cdata_u32[CDIM_Y][CDIM_X];
static float32 FAR cdata_f32[CDIM_Y][CDIM_X];
static float64 FAR cdata_f64[CDIM_Y][CDIM_X];

VOID init_cdata()
{
    int i,j;


    for (i=0; i< CDIM_Y; i++)
       for (j=0; j< CDIM_X; j++) {
            cdata_i8[i][j]=(int8)(i*10+j);
            cdata_u8[i][j]=(uint8)(i*10+j);
            cdata_i16[i][j]=(int16)(i*10+j);
            cdata_u16[i][j]=(uint16)(i*10+j);
            cdata_i32[i][j]=(int32)(i*10+j);
            cdata_u32[i][j]=(uint32)(i*10+j);
            cdata_f32[i][j]=(float32)(i*10+j);
            cdata_f64[i][j]=(float64)(i*10+j);
          } /* end for */
}   /* end init_cdata() */

VOID wrapup_cdata()
{
}   /* end wrapup_cdata() */

VOID test_little_read()
{
    intn rank;
    int32 dimsizes[2];
    int32 numbertype;
    int8 *data_i8;
    uint8 *data_u8;
    int16 *data_i16;
    uint16 *data_u16;
    int32 *data_i32;
    uint32 *data_u32;
    float32 *data_f32;
    float64 *data_f64;
    int ret;

    MESSAGE(5,printf("Testing Little-Endian Read Routines\n"););

    MESSAGE(10,printf("Testing Little-Endian INT8 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for INT8 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LINT8) {
            fprintf(stderr, "Numbertype for INT8 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_i8=(int8 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(int8));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_i8);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_i8,data_i8,CDIM_X*CDIM_Y*sizeof(int8))) {
                fprintf(stderr,"INT8 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_i8);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian UINT8 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for UINT8 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LUINT8) {
            fprintf(stderr, "Numbertype for UINT8 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_u8=(uint8 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(uint8));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_u8);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_u8,data_u8,CDIM_X*CDIM_Y*sizeof(uint8))) {
                fprintf(stderr,"UINT8 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_u8);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian INT16 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for INT16 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LINT16) {
            fprintf(stderr, "Numbertype for INT16 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_i16=(int16 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(int16));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_i16);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_i16,data_i16,CDIM_X*CDIM_Y*sizeof(int16))) {
                fprintf(stderr,"INT16 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_i16);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian UINT16 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for UINT16 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LUINT16) {
            fprintf(stderr, "Numbertype for UINT16 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_u16=(uint16 *)HDgetspace(dimsizes[0]*
		    dimsizes[1]*sizeof(uint16));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_u16);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_u16,data_u16,CDIM_X*CDIM_Y*sizeof(uint16))) {
                fprintf(stderr,"UINT16 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_u16);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian INT32 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for INT32 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LINT32) {
            fprintf(stderr, "Numbertype for INT32 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_i32=(int32 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(int32));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_i32);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_i32,data_i32,CDIM_X*CDIM_Y*sizeof(int32))) {
                fprintf(stderr,"INT32 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_i32);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian UINT32 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for UINT32 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LUINT32) {
            fprintf(stderr, "Numbertype for UINT32 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_u32=(uint32 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		    sizeof(uint32));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_u32);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_u32,data_u32,CDIM_X*CDIM_Y*sizeof(uint32))) {
                fprintf(stderr,"UINT32 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_u32);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian FLOAT32 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for FLOAT32 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LFLOAT32) {
            fprintf(stderr, "Numbertype for FLOAT32 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_f32=(float32 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		    sizeof(float32));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_f32);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_f32,data_f32,CDIM_X*CDIM_Y*sizeof(float32))) {
                fprintf(stderr,"FLOAT32 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_f32);
          } /* end else */
      } /* end else */

    MESSAGE(10,printf("Testing Little-Endian FLOAT64 Reading Routines\n"););

    ret=DFSDgetdims(FILENAME,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for FLOAT64 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LFLOAT64) {
            fprintf(stderr, "Numbertype for FLOAT64 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_f64=(float64 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		    sizeof(float64));
            ret=DFSDgetdata(FILENAME,rank,dimsizes,(VOIDP)data_f64);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_f64,data_f64,CDIM_X*CDIM_Y*sizeof(float64))) {
                fprintf(stderr,"FLOAT64 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_f64);
          } /* end else */
      } /* end else */
}   /* end test_little_read */

VOID test_little_write()
{
    intn rank;
    int32 dimsizes[2];
    int32 numbertype;
    int8 *data_i8;
    uint8 *data_u8;
    int16 *data_i16;
    uint16 *data_u16;
    int32 *data_i32;
    uint32 *data_u32;
    float32 *data_f32;
    float64 *data_f64;
    int ret;

    MESSAGE(5,printf("Testing Little-Endian Write Routines\n"););

    rank = 2;
    dimsizes[0]=CDIM_Y;
    dimsizes[1]=CDIM_X;

    MESSAGE(10,printf("Testing Little-Endian INT8 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LINT8);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_i8);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian UINT8 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LUINT8);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_u8);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian INT16 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LINT16);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_i16);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian UINT16 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LUINT16);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_u16);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian INT32 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LINT32);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_i32);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian UINT32 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LUINT32);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_u32);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian FLOAT32 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LFLOAT32);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_f32);
    RESULT("DFSDadddata");

    MESSAGE(10,printf("Testing Little-Endian FLOAT64 Writing Routines\n"););

    ret=DFSDsetdims(2,dimsizes);
    RESULT("DFSDsetdims");
    ret=DFSDsetNT(DFNT_LFLOAT64);
    RESULT("DFSDsetNT");
    ret=DFSDadddata(TMPFILE, rank, dimsizes, (VOIDP)cdata_f64);
    RESULT("DFSDadddata");

    ret=DFSDrestart();
    RESULT("DFSDrestart");

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for INT8 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LINT8) {
            fprintf(stderr, "Numbertype for INT8 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_i8=(int8 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(int8));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_i8);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_i8,data_i8,CDIM_X*CDIM_Y*sizeof(int8))) {
                fprintf(stderr,"INT8 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_i8);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for UINT8 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LUINT8) {
            fprintf(stderr, "Numbertype for UINT8 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_u8=(uint8 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(uint8));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_u8);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_u8,data_u8,CDIM_X*CDIM_Y*sizeof(uint8))) {
                fprintf(stderr,"UINT8 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_u8);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for INT16 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LINT16) {
            fprintf(stderr, "Numbertype for INT16 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_i16=(int16 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(int16));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_i16);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_i16,data_i16,CDIM_X*CDIM_Y*sizeof(int16))) {
                fprintf(stderr,"INT16 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_i16);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for UINT16 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LUINT16) {
            fprintf(stderr, "Numbertype for UINT16 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_u16=(uint16 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		   sizeof(uint16));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_u16);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_u16,data_u16,CDIM_X*CDIM_Y*sizeof(uint16))) {
                fprintf(stderr,"UINT16 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_u16);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for INT32 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LINT32) {
            fprintf(stderr, "Numbertype for INT32 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_i32=(int32 *)HDgetspace(dimsizes[0]*dimsizes[1]*sizeof(int32));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_i32);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_i32,data_i32,CDIM_X*CDIM_Y*sizeof(int32))) {
                fprintf(stderr,"INT32 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_i32);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for UINT32 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LUINT32) {
            fprintf(stderr, "Numbertype for UINT32 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_u32=(uint32 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		    sizeof(uint32));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_u32);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_u32,data_u32,CDIM_X*CDIM_Y*sizeof(uint32))) {
                fprintf(stderr,"UINT32 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_u32);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for FLOAT32 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LFLOAT32) {
            fprintf(stderr, "Numbertype for FLOAT32 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_f32=(float32 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		    sizeof(float32));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_f32);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_f32,data_f32,CDIM_X*CDIM_Y*sizeof(float32))) {
                fprintf(stderr,"FLOAT32 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_f32);
          } /* end else */
      } /* end else */

    ret=DFSDgetdims(TMPFILE,&rank,dimsizes,2);
    RESULT("DFSDgetdims");
    if(dimsizes[0]!=CDIM_Y || dimsizes[1]!=CDIM_X) {
        fprintf(stderr, "Dimensions for FLOAT64 data were incorrect\n");
        num_errs++;
      } /* end if */
    else {
        ret=DFSDgetNT(&numbertype);
        RESULT("DFSDgetNT");
        if(numbertype!=DFNT_LFLOAT64) {
            fprintf(stderr, "Numbertype for FLOAT64 data were incorrect\n");
            num_errs++;
          } /* end if */
        else {
            data_f64=(float64 *)HDgetspace(dimsizes[0]*dimsizes[1]*
		    sizeof(float64));
            ret=DFSDgetdata(TMPFILE,rank,dimsizes,(VOIDP)data_f64);
            RESULT("DFSDgetdata");

            if(HDmemcmp(cdata_f64,data_f64,CDIM_X*CDIM_Y*sizeof(float64))) {
                fprintf(stderr,"FLOAT64 data was incorrect\n");
                num_errs++;
              } /* end if */
            HDfreespace((VOIDP)data_f64);
          } /* end else */
      } /* end else */
}   /* end test_little_write */

void test_litend()
{
    init_cdata();

    test_little_read();
    test_little_write();

    wrapup_cdata();
}   /* end test_litend() */

