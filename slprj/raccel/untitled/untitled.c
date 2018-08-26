#include "__cf_untitled.h"
#include "rt_logging_mmi.h"
#include "untitled_capi.h"
#include <math.h>
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.11 (R2016b) 25-Aug-2016" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\untitled\\untitled_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . fk2oyjr4no = rtP .
Integrator1_IC ; rtX . bfd4jj5a33 = rtP . Integrator2_IC ; rtX . orieyygbnn =
rtP . Integrator3_IC ; } void MdlStart ( void ) { { void * *
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ; const char *
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , pOSigstreamManagerAddr ) ; if (
errorCreatingOSigstreamManager != ( NULL ) ) { * pOSigstreamManagerAddr = (
NULL ) ; ssSetErrorStatus ( rtS , errorCreatingOSigstreamManager ) ; return ;
} } if ( sdiIsUsingInlineAsyncQueues ( ) ) { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU loggedName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath
= sdiGetLabelFromChars ( "untitled/Integrator1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiAsyncRepoDataTypeHandle
hDT = sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ;
sdiComplexity sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . nrmukcfwfd .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "0ddd7849-f563-4350-8ea8-b0665d6e7cac" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiSetSignalSampleTimeString ( rtDW . nrmukcfwfd . AQHandles , "Continuous" )
; sdiSetRunStartTime ( rtDW . nrmukcfwfd . AQHandles , ssGetTaskTime ( rtS ,
1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . nrmukcfwfd . AQHandles ,
1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . nrmukcfwfd . AQHandles ,
loggedName , origSigName , propName ) ; sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; } } if
( sdiIsUsingInlineAsyncQueues ( ) ) { } else { } if (
sdiIsUsingInlineAsyncQueues ( ) ) { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU loggedName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath
= sdiGetLabelFromChars ( "untitled/Integrator2" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiAsyncRepoDataTypeHandle
hDT = sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ;
sdiComplexity sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . pexzeu3onk .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "c6b5cbc9-9af2-47cd-a304-d1b648212ac4" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiSetSignalSampleTimeString ( rtDW . pexzeu3onk . AQHandles , "Continuous" )
; sdiSetRunStartTime ( rtDW . pexzeu3onk . AQHandles , ssGetTaskTime ( rtS ,
1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . pexzeu3onk . AQHandles ,
1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . pexzeu3onk . AQHandles ,
loggedName , origSigName , propName ) ; sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; } } if
( sdiIsUsingInlineAsyncQueues ( ) ) { } else { } if (
sdiIsUsingInlineAsyncQueues ( ) ) { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU loggedName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath
= sdiGetLabelFromChars ( "untitled/Integrator3" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiAsyncRepoDataTypeHandle
hDT = sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ;
sdiComplexity sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . npbtknd4kc .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "4552d7c7-caa4-4687-aaa0-5cba42cb70ba" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiSetSignalSampleTimeString ( rtDW . npbtknd4kc . AQHandles , "Continuous" )
; sdiSetRunStartTime ( rtDW . npbtknd4kc . AQHandles , ssGetTaskTime ( rtS ,
1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . npbtknd4kc . AQHandles ,
1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . npbtknd4kc . AQHandles ,
loggedName , origSigName , propName ) ; sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; } } if
( sdiIsUsingInlineAsyncQueues ( ) ) { } else { } rtDW . igwhvclklu = 0 ; rtDW
. dhc3dpq4ce = 0 ; rtDW . l44sr0fk2n = 0 ; rtDW . jjm2zmdhpu = 0 ; rtDW .
gn120idec4 = 0 ; MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { real_T iajfspemga ; rtB . iujc0na3l0 =
rtX . fk2oyjr4no ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput
( rtS ) ) { if ( sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . nrmukcfwfd .
AQHandles ) { sdiWriteSignal ( rtDW . nrmukcfwfd . AQHandles , ssGetTaskTime
( rtS , 1 ) , ( void * ) & rtB . iujc0na3l0 ) ; } } else { { double time =
ssGetTaskTime ( rtS , 1 ) ; void * pData = ( void * ) & rtB . iujc0na3l0 ;
int32_T size = 1 * sizeof ( real_T ) ; sendToAsyncQueueTgtAppSvc (
3376594790U , time , pData , size ) ; } } } } rtB . e1zptrpsbh = rtX .
bfd4jj5a33 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS
) ) { if ( sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . pexzeu3onk .
AQHandles ) { sdiWriteSignal ( rtDW . pexzeu3onk . AQHandles , ssGetTaskTime
( rtS , 1 ) , ( void * ) & rtB . e1zptrpsbh ) ; } } else { { double time =
ssGetTaskTime ( rtS , 1 ) ; void * pData = ( void * ) & rtB . e1zptrpsbh ;
int32_T size = 1 * sizeof ( real_T ) ; sendToAsyncQueueTgtAppSvc (
3809732676U , time , pData , size ) ; } } } } rtB . lnmdnbaomd = rtX .
orieyygbnn ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS
) ) { if ( sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . npbtknd4kc .
AQHandles ) { sdiWriteSignal ( rtDW . npbtknd4kc . AQHandles , ssGetTaskTime
( rtS , 1 ) , ( void * ) & rtB . lnmdnbaomd ) ; } } else { { double time =
ssGetTaskTime ( rtS , 1 ) ; void * pData = ( void * ) & rtB . lnmdnbaomd ;
int32_T size = 1 * sizeof ( real_T ) ; sendToAsyncQueueTgtAppSvc (
2723703572U , time , pData , size ) ; } } } } rtB . jqsw5kn4sj = rtB .
lnmdnbaomd - rtB . iujc0na3l0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
rtB . jqsw5kn4sj > 0.0 ) { rtDW . msfc3xs1lc = 1 ; } else if ( rtB .
jqsw5kn4sj < 0.0 ) { rtDW . msfc3xs1lc = - 1 ; } else { rtDW . msfc3xs1lc = 0
; } rtB . jyoizzkluv = rtDW . msfc3xs1lc ; } if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . fdjghdue04 = ( rtB . jqsw5kn4sj >= 0.0 ) ; } rtB . feb1f05yr5 = rtDW
. fdjghdue04 > 0 ? rtB . jqsw5kn4sj : - rtB . jqsw5kn4sj ; rtB . c3cmi10xe4 =
rtP . ug1_Gain * rtB . feb1f05yr5 ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . igwhvclklu != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . igwhvclklu
= 0 ; } iajfspemga = muDoubleScalarSqrt ( rtB . c3cmi10xe4 ) ; } else { if (
rtB . c3cmi10xe4 < 0.0 ) { iajfspemga = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . c3cmi10xe4 ) ) ; } else { iajfspemga =
muDoubleScalarSqrt ( rtB . c3cmi10xe4 ) ; } if ( rtB . c3cmi10xe4 < 0.0 ) {
rtDW . igwhvclklu = 1 ; } } rtB . oelf3tcxfv = rtP . az1_Gain * iajfspemga ;
rtB . lq2fx2s4t1 = rtP . Sn1_Gain * rtB . oelf3tcxfv ; rtB . cr3lgfj2ca = rtB
. jyoizzkluv * rtB . lq2fx2s4t1 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
oayxabvikl = ( rtB . e1zptrpsbh >= 0.0 ) ; } rtB . inkn31zdwm = rtDW .
oayxabvikl > 0 ? rtB . e1zptrpsbh : - rtB . e1zptrpsbh ; rtB . ge4oajan3j =
rtP . ug2_Gain * rtB . inkn31zdwm ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . dhc3dpq4ce != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . dhc3dpq4ce
= 0 ; } iajfspemga = muDoubleScalarSqrt ( rtB . ge4oajan3j ) ; } else { if (
rtB . ge4oajan3j < 0.0 ) { iajfspemga = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . ge4oajan3j ) ) ; } else { iajfspemga =
muDoubleScalarSqrt ( rtB . ge4oajan3j ) ; } if ( rtB . ge4oajan3j < 0.0 ) {
rtDW . dhc3dpq4ce = 1 ; } } rtB . m23hfxrvdt = rtP . az2_Gain * iajfspemga ;
rtB . c5xpkpvyn1 = rtP . Sn2_Gain * rtB . m23hfxrvdt ; rtB . lkkx42x1x4 = rtB
. iujc0na3l0 - rtB . e1zptrpsbh ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
rtB . lkkx42x1x4 > 0.0 ) { rtDW . lufpoabicg = 1 ; } else if ( rtB .
lkkx42x1x4 < 0.0 ) { rtDW . lufpoabicg = - 1 ; } else { rtDW . lufpoabicg = 0
; } rtB . dvczgqfdx4 = rtDW . lufpoabicg ; } if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . m3sggnfclu = ( rtB . lkkx42x1x4 >= 0.0 ) ; } rtB . alqpdj3dha = rtDW
. m3sggnfclu > 0 ? rtB . lkkx42x1x4 : - rtB . lkkx42x1x4 ; rtB . l10fmn3ead =
rtP . ug3_Gain * rtB . alqpdj3dha ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . l44sr0fk2n != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . l44sr0fk2n
= 0 ; } iajfspemga = muDoubleScalarSqrt ( rtB . l10fmn3ead ) ; } else { if (
rtB . l10fmn3ead < 0.0 ) { iajfspemga = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . l10fmn3ead ) ) ; } else { iajfspemga =
muDoubleScalarSqrt ( rtB . l10fmn3ead ) ; } if ( rtB . l10fmn3ead < 0.0 ) {
rtDW . l44sr0fk2n = 1 ; } } rtB . i5dqiboze2 = rtP . az3_Gain * iajfspemga ;
rtB . f5vffqa0oj = rtP . Sn3_Gain * rtB . i5dqiboze2 ; rtB . pfimpa0lha = rtB
. dvczgqfdx4 * rtB . f5vffqa0oj ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
rtB . jqsw5kn4sj > 0.0 ) { rtDW . iqowm2505o = 1 ; } else if ( rtB .
jqsw5kn4sj < 0.0 ) { rtDW . iqowm2505o = - 1 ; } else { rtDW . iqowm2505o = 0
; } rtB . grsqgrgg1x = rtDW . iqowm2505o ; } if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . lrcf2ja1a4 = ( rtB . jqsw5kn4sj >= 0.0 ) ; } rtB . dv3clbdhe3 = rtDW
. lrcf2ja1a4 > 0 ? rtB . jqsw5kn4sj : - rtB . jqsw5kn4sj ; rtB . d3yjyjuexb =
rtP . ug4_Gain * rtB . dv3clbdhe3 ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . jjm2zmdhpu != 0 ) { ssSetSolverNeedsReset ( rtS ) ; rtDW . jjm2zmdhpu
= 0 ; } iajfspemga = muDoubleScalarSqrt ( rtB . d3yjyjuexb ) ; } else { if (
rtB . d3yjyjuexb < 0.0 ) { iajfspemga = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . d3yjyjuexb ) ) ; } else { iajfspemga =
muDoubleScalarSqrt ( rtB . d3yjyjuexb ) ; } if ( rtB . d3yjyjuexb < 0.0 ) {
rtDW . jjm2zmdhpu = 1 ; } } rtB . iqlfpwdsnr = rtP . az4_Gain * iajfspemga ;
rtB . kgwcaqmntb = rtP . Sn4_Gain * rtB . iqlfpwdsnr ; rtB . pbiwlrykqd = rtB
. grsqgrgg1x * rtB . kgwcaqmntb ; rtB . m0ontgxet4 = ( rtP . Q1_Value - rtB .
pbiwlrykqd ) - rtB . cr3lgfj2ca ; rtB . hpup1s22uu = rtP . uA1_Gain * rtB .
m0ontgxet4 ; rtB . gbnlxbbpei = ( rtB . pfimpa0lha + rtP . Q2_Value ) - rtB .
c5xpkpvyn1 ; rtB . ilcsdugm0k = rtP . uA2_Gain * rtB . gbnlxbbpei ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . lkkx42x1x4 > 0.0 ) { rtDW .
oykjmnkwy1 = 1 ; } else if ( rtB . lkkx42x1x4 < 0.0 ) { rtDW . oykjmnkwy1 = -
1 ; } else { rtDW . oykjmnkwy1 = 0 ; } rtB . on1qfawxst = rtDW . oykjmnkwy1 ;
} if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . k3n23sxwwo = ( rtB . lkkx42x1x4
>= 0.0 ) ; } rtB . ketl1hbjme = rtDW . k3n23sxwwo > 0 ? rtB . lkkx42x1x4 : -
rtB . lkkx42x1x4 ; rtB . oejilp5ihn = rtP . ug5_Gain * rtB . ketl1hbjme ; if
( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . gn120idec4 != 0 ) {
ssSetSolverNeedsReset ( rtS ) ; rtDW . gn120idec4 = 0 ; } iajfspemga =
muDoubleScalarSqrt ( rtB . oejilp5ihn ) ; } else { if ( rtB . oejilp5ihn <
0.0 ) { iajfspemga = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtB .
oejilp5ihn ) ) ; } else { iajfspemga = muDoubleScalarSqrt ( rtB . oejilp5ihn
) ; } if ( rtB . oejilp5ihn < 0.0 ) { rtDW . gn120idec4 = 1 ; } } rtB .
irgn3hvtyh = rtP . az5_Gain * iajfspemga ; rtB . dbvtiwnz1d = rtP . Sn5_Gain
* rtB . irgn3hvtyh ; rtB . h4auhqthyd = rtB . on1qfawxst * rtB . dbvtiwnz1d ;
rtB . kapx1gh3qy = ( rtB . cr3lgfj2ca - rtB . h4auhqthyd ) - rtB . pfimpa0lha
; rtB . b4r3e0ajra = rtP . uA3_Gain * rtB . kapx1gh3qy ; UNUSED_PARAMETER (
tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> fk2oyjr4no = rtB . b4r3e0ajra ; _rtXdot -> bfd4jj5a33 =
rtB . ilcsdugm0k ; _rtXdot -> orieyygbnn = rtB . hpup1s22uu ; } void
MdlProjection ( void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ;
_rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV ->
pxa55roxq5 = rtB . jqsw5kn4sj ; _rtZCSV -> kvwhcuwko2 = rtB . jqsw5kn4sj ;
_rtZCSV -> pbeiroz5f5 = rtB . e1zptrpsbh ; _rtZCSV -> cjsfm22ztn = rtB .
lkkx42x1x4 ; _rtZCSV -> p4omop2cvt = rtB . lkkx42x1x4 ; _rtZCSV -> ohgz2pg53g
= rtB . jqsw5kn4sj ; _rtZCSV -> n2fvzqlrwd = rtB . jqsw5kn4sj ; _rtZCSV ->
e1d1nnq0jx = rtB . lkkx42x1x4 ; _rtZCSV -> eix2aswxnf = rtB . lkkx42x1x4 ; }
void MdlTerminate ( void ) { if ( sdiIsUsingInlineAsyncQueues ( ) ) { if (
rtDW . nrmukcfwfd . AQHandles ) { sdiTerminateStreaming ( & rtDW . nrmukcfwfd
. AQHandles ) ; } } if ( sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW .
pexzeu3onk . AQHandles ) { sdiTerminateStreaming ( & rtDW . pexzeu3onk .
AQHandles ) ; } } if ( sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW .
npbtknd4kc . AQHandles ) { sdiTerminateStreaming ( & rtDW . npbtknd4kc .
AQHandles ) ; } } rtwOSigstreamManagerSaveDatasetsToMatFile (
rt_GetOSigstreamManager ( ) , rt_GetMatSigstreamLoggingFileName ( ) ) ;
rtwOSigstreamManagerDestroyInstance ( rt_GetOSigstreamManager ( ) ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 3 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 53 ) ; ssSetNumBlockIO ( rtS , 39 ) ;
ssSetNumBlockParams ( rtS , 23 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
1655848680U ) ; ssSetChecksumVal ( rtS , 1 , 3945486467U ) ; ssSetChecksumVal
( rtS , 2 , 709520710U ) ; ssSetChecksumVal ( rtS , 3 , 4032626434U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = (
real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * )
x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
untitled_InitializeDataMapInfo ( rtS ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "untitled" ) ; ssSetPath
( rtS , "untitled" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 100.0
) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 1000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ; static
real_T absTol [ 3 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 3 ] = { 0U , 0U , 0U } ; static uint8_T zcAttributes [ 9 ] =
{ ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 4 ] = {
{ 1 * sizeof ( real_T ) , ( char * ) ( & rtB . on1qfawxst ) , ( NULL ) } , {
1 * sizeof ( real_T ) , ( char * ) ( & rtB . grsqgrgg1x ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . dvczgqfdx4 ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . jyoizzkluv ) , ( NULL ) } } ;
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 2.0 ) ;
ssSetSolverMaxOrder ( rtS , 5 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 4 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode15s" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 9 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 9 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1655848680U ) ; ssSetChecksumVal ( rtS , 1 ,
3945486467U ) ; ssSetChecksumVal ( rtS , 2 , 709520710U ) ; ssSetChecksumVal
( rtS , 3 , 4032626434U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; } const int_T gblParameterTuningTid = 2 ; void
MdlOutputsParameterSampleTime ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
