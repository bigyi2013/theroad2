#include "__cf_untitled.h"
#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "untitled_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME untitled
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (39) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T iujc0na3l0 ; real_T e1zptrpsbh ; real_T lnmdnbaomd ;
real_T jqsw5kn4sj ; real_T jyoizzkluv ; real_T feb1f05yr5 ; real_T c3cmi10xe4
; real_T oelf3tcxfv ; real_T lq2fx2s4t1 ; real_T cr3lgfj2ca ; real_T
inkn31zdwm ; real_T ge4oajan3j ; real_T m23hfxrvdt ; real_T c5xpkpvyn1 ;
real_T lkkx42x1x4 ; real_T dvczgqfdx4 ; real_T alqpdj3dha ; real_T l10fmn3ead
; real_T i5dqiboze2 ; real_T f5vffqa0oj ; real_T pfimpa0lha ; real_T
grsqgrgg1x ; real_T dv3clbdhe3 ; real_T d3yjyjuexb ; real_T iqlfpwdsnr ;
real_T kgwcaqmntb ; real_T pbiwlrykqd ; real_T m0ontgxet4 ; real_T hpup1s22uu
; real_T gbnlxbbpei ; real_T ilcsdugm0k ; real_T on1qfawxst ; real_T
ketl1hbjme ; real_T oejilp5ihn ; real_T irgn3hvtyh ; real_T dbvtiwnz1d ;
real_T h4auhqthyd ; real_T kapx1gh3qy ; real_T b4r3e0ajra ; } B ; typedef
struct { struct { void * AQHandles ; } nrmukcfwfd ; struct { void * AQHandles
; } pexzeu3onk ; struct { void * AQHandles ; } npbtknd4kc ; struct { void *
LoggedData ; } i5sx51surl ; struct { void * LoggedData ; } anx2os24ml ;
struct { void * LoggedData ; } fi53mufowe ; struct { void * LoggedData ; }
kexz1qj4et ; int_T msfc3xs1lc ; int_T fdjghdue04 ; int_T oayxabvikl ; int_T
lufpoabicg ; int_T m3sggnfclu ; int_T iqowm2505o ; int_T lrcf2ja1a4 ; int_T
oykjmnkwy1 ; int_T k3n23sxwwo ; int8_T igwhvclklu ; int8_T dhc3dpq4ce ;
int8_T l44sr0fk2n ; int8_T jjm2zmdhpu ; int8_T gn120idec4 ; } DW ; typedef
struct { real_T fk2oyjr4no ; real_T bfd4jj5a33 ; real_T orieyygbnn ; } X ;
typedef struct { real_T fk2oyjr4no ; real_T bfd4jj5a33 ; real_T orieyygbnn ;
} XDot ; typedef struct { boolean_T fk2oyjr4no ; boolean_T bfd4jj5a33 ;
boolean_T orieyygbnn ; } XDis ; typedef struct { real_T fk2oyjr4no ; real_T
bfd4jj5a33 ; real_T orieyygbnn ; } CStateAbsTol ; typedef struct { real_T
pxa55roxq5 ; real_T kvwhcuwko2 ; real_T pbeiroz5f5 ; real_T cjsfm22ztn ;
real_T p4omop2cvt ; real_T ohgz2pg53g ; real_T n2fvzqlrwd ; real_T e1d1nnq0jx
; real_T eix2aswxnf ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ;
} DataMapInfo ; struct P_ { real_T Integrator1_IC ; real_T Integrator2_IC ;
real_T Integrator3_IC ; real_T ug1_Gain ; real_T az1_Gain ; real_T Sn1_Gain ;
real_T ug2_Gain ; real_T az2_Gain ; real_T Sn2_Gain ; real_T ug3_Gain ;
real_T az3_Gain ; real_T Sn3_Gain ; real_T ug4_Gain ; real_T az4_Gain ;
real_T Sn4_Gain ; real_T Q1_Value ; real_T uA1_Gain ; real_T Q2_Value ;
real_T uA2_Gain ; real_T ug5_Gain ; real_T az5_Gain ; real_T Sn5_Gain ;
real_T uA3_Gain ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern
B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * untitled_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
