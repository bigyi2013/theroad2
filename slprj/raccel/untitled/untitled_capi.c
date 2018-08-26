#include "__cf_untitled.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "untitled_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "untitled.h"
#include "untitled_capi.h"
#include "untitled_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"untitled/Abs" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "untitled/Abs1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 2 , 0 , TARGET_STRING ( "untitled/Abs2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "untitled/Abs3" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING ( "untitled/Abs4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"untitled/1//A1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 ,
TARGET_STRING ( "untitled/1//A2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 7 , 0 , TARGET_STRING ( "untitled/1//A3" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING ( "untitled/2g1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING ( "untitled/2g2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"untitled/2g3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 ,
TARGET_STRING ( "untitled/2g4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 12 , 0 , TARGET_STRING ( "untitled/2g5" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING ( "untitled/Sn1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING ( "untitled/Sn2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"untitled/Sn3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 ,
TARGET_STRING ( "untitled/Sn4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 17 , 0 , TARGET_STRING ( "untitled/Sn5" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING ( "untitled/az1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING ( "untitled/az2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"untitled/az3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 ,
TARGET_STRING ( "untitled/az4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 22 , 0 , TARGET_STRING ( "untitled/az5" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING ( "untitled/Integrator1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"untitled/Integrator2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25
, 0 , TARGET_STRING ( "untitled/Integrator3" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING ( "untitled/Divide" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"untitled/Divide1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0
, TARGET_STRING ( "untitled/Divide2" ) , TARGET_STRING ( "Q10" ) , 0 , 0 , 0
, 0 , 0 } , { 29 , 0 , TARGET_STRING ( "untitled/Divide3" ) , TARGET_STRING (
"Q20" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING ( "untitled/Sign1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
"untitled/Sign2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 0 ,
TARGET_STRING ( "untitled/Sign3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 33 , 0 , TARGET_STRING ( "untitled/Sign4" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING ( "untitled/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"untitled/Sum1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 0 ,
TARGET_STRING ( "untitled/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 37 , 0 , TARGET_STRING ( "untitled/Sum3" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 38 , 0 , TARGET_STRING ( "untitled/Sum4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 39 , TARGET_STRING ( "untitled/Q1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"untitled/Q2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 41 ,
TARGET_STRING ( "untitled/1//A1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 42 , TARGET_STRING ( "untitled/1//A2" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 43 , TARGET_STRING ( "untitled/1//A3" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 44 , TARGET_STRING ( "untitled/2g1" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING ( "untitled/2g2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"untitled/2g3" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 47 ,
TARGET_STRING ( "untitled/2g4" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
48 , TARGET_STRING ( "untitled/2g5" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 49 , TARGET_STRING ( "untitled/Sn1" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 50 , TARGET_STRING ( "untitled/Sn2" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 51 , TARGET_STRING ( "untitled/Sn3" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 52 , TARGET_STRING ( "untitled/Sn4" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING (
"untitled/Sn5" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 54 ,
TARGET_STRING ( "untitled/az1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
55 , TARGET_STRING ( "untitled/az2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 56 , TARGET_STRING ( "untitled/az3" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 57 , TARGET_STRING ( "untitled/az4" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 58 , TARGET_STRING ( "untitled/az5" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING ( "untitled/Integrator1" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"untitled/Integrator2" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 }
, { 61 , TARGET_STRING ( "untitled/Integrator3" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 }
} ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , (
NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . feb1f05yr5 , & rtB . alqpdj3dha ,
& rtB . inkn31zdwm , & rtB . dv3clbdhe3 , & rtB . ketl1hbjme , & rtB .
hpup1s22uu , & rtB . ilcsdugm0k , & rtB . b4r3e0ajra , & rtB . c3cmi10xe4 , &
rtB . ge4oajan3j , & rtB . l10fmn3ead , & rtB . d3yjyjuexb , & rtB .
oejilp5ihn , & rtB . lq2fx2s4t1 , & rtB . c5xpkpvyn1 , & rtB . f5vffqa0oj , &
rtB . kgwcaqmntb , & rtB . dbvtiwnz1d , & rtB . oelf3tcxfv , & rtB .
m23hfxrvdt , & rtB . i5dqiboze2 , & rtB . iqlfpwdsnr , & rtB . irgn3hvtyh , &
rtB . iujc0na3l0 , & rtB . e1zptrpsbh , & rtB . lnmdnbaomd , & rtB .
cr3lgfj2ca , & rtB . pfimpa0lha , & rtB . pbiwlrykqd , & rtB . h4auhqthyd , &
rtB . jyoizzkluv , & rtB . grsqgrgg1x , & rtB . dvczgqfdx4 , & rtB .
on1qfawxst , & rtB . m0ontgxet4 , & rtB . jqsw5kn4sj , & rtB . lkkx42x1x4 , &
rtB . kapx1gh3qy , & rtB . gbnlxbbpei , & rtP . Q1_Value , & rtP . Q2_Value ,
& rtP . uA1_Gain , & rtP . uA2_Gain , & rtP . uA3_Gain , & rtP . ug1_Gain , &
rtP . ug2_Gain , & rtP . ug3_Gain , & rtP . ug4_Gain , & rtP . ug5_Gain , &
rtP . Sn1_Gain , & rtP . Sn2_Gain , & rtP . Sn3_Gain , & rtP . Sn4_Gain , &
rtP . Sn5_Gain , & rtP . az1_Gain , & rtP . az2_Gain , & rtP . az3_Gain , &
rtP . az4_Gain , & rtP . az5_Gain , & rtP . Integrator1_IC , & rtP .
Integrator2_IC , & rtP . Integrator3_IC , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals
, 39 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 23 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1655848680U , 3945486467U , 709520710U , 4032626434U } , ( NULL ) , 0 , 0
} ; const rtwCAPI_ModelMappingStaticInfo * untitled_GetCAPIStaticMap ( ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void untitled_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void untitled_host_InitializeDataMapInfo ( untitled_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
