/*
 * final.h
 *
 * Code generation for model "final".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Oct 31 11:17:10 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_final_h_
#define RTW_HEADER_final_h_
#ifndef final_COMMON_INCLUDES_
#define final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* final_COMMON_INCLUDES_ */

#include "final_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include <float.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DC;                           /* '<S46>/DC' */
  real_T w;                            /* '<S32>/Integrator' */
  real_T Efcem;                        /* '<S32>/Product' */
  real_T StateSpace_o1[3];             /* '<S135>/State-Space' */
  real_T StateSpace_o2[16];            /* '<S135>/State-Space' */
  real_T DC_p;                         /* '<S31>/DC' */
  real_T w_k;                          /* '<S22>/Integrator' */
  real_T Efcem_g;                      /* '<S22>/Product' */
  real_T StateSpace_o1_m[3];           /* '<S136>/State-Space' */
  real_T StateSpace_o2_p[16];          /* '<S136>/State-Space' */
  real_T DC_g;                         /* '<S30>/DC' */
  real_T StateSpace_o1_p;              /* '<S137>/State-Space' */
  real_T StateSpace_o2_a[16];          /* '<S137>/State-Space' */
  real_T SpeedSP;                      /* '<Root>/Gain7' */
  real_T TL;                           /* '<Root>/Step1' */
  real_T Gain9;                        /* '<Root>/Gain9' */
  real_T donotdeletethisgain;          /* '<S25>/do not delete this gain' */
  real_T Te;                           /* '<S22>/Product1' */
  real_T Iaref;                        /* '<Root>/Ia sat' */
  real_T A;                            /* '<S22>/Gain2' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T DataTypeConversion;           /* '<S88>/Data Type Conversion' */
  real_T gate;                         /* '<S86>/(gate)' */
  real_T DataTypeConversion_j;         /* '<S95>/Data Type Conversion' */
  real_T gate_j;                       /* '<S93>/(gate)' */
  real_T DataTypeConversion_e;         /* '<S102>/Data Type Conversion' */
  real_T gate_h;                       /* '<S100>/(gate)' */
  real_T DataTypeConversion_h;         /* '<S130>/Data Type Conversion' */
  real_T gate_d;                       /* '<S128>/(gate)' */
  real_T SpeedSP_h;                    /* '<Root>/Gain17' */
  real_T donotdeletethisgain_p;        /* '<S35>/do not delete this gain' */
  real_T DataTypeConversion_g;         /* '<S59>/Data Type Conversion' */
  real_T gate_do;                      /* '<S57>/(gate)' */
  real_T DataTypeConversion_jf;        /* '<S66>/Data Type Conversion' */
  real_T gate_m;                       /* '<S64>/(gate)' */
  real_T DataTypeConversion_ef;        /* '<S52>/Data Type Conversion' */
  real_T gate_n;                       /* '<S50>/(gate)' */
  real_T DataTypeConversion_m;         /* '<S73>/Data Type Conversion' */
  real_T gate_jm;                      /* '<S71>/(gate)' */
  real_T donotdeletethisgain_e;        /* '<S45>/do not delete this gain' */
  real_T TL_k;                         /* '<Root>/Step3' */
  real_T Gain19;                       /* '<Root>/Gain19' */
  real_T Te_k;                         /* '<S32>/Product1' */
  real_T A_j;                          /* '<S32>/Gain2' */
  real_T Gain15;                       /* '<S14>/Gain15' */
  real_T Gain16;                       /* '<S15>/Gain16' */
  real_T TL_l;                         /* '<Root>/Step5' */
  real_T SpeedSP_f;                    /* '<Root>/Gain20' */
  real_T Iaref_d;                      /* '<Root>/Ia sat1' */
  real_T Gain22;                       /* '<Root>/Gain22' */
  real_T Eafeedforward;                /* '<Root>/Gain11' */
  real_T Gain16_a;                     /* '<Root>/Gain16' */
  real_T Gain18;                       /* '<Root>/Gain18' */
  real_T DataTypeConversion_l;         /* '<S81>/Data Type Conversion' */
  real_T gate_a;                       /* '<S79>/(gate)' */
  real_T DataTypeConversion_jl;        /* '<S109>/Data Type Conversion' */
  real_T gate_jv;                      /* '<S107>/(gate)' */
  real_T DataTypeConversion_jc;        /* '<S116>/Data Type Conversion' */
  real_T gate_hx;                      /* '<S114>/(gate)' */
  real_T DataTypeConversion_p;         /* '<S123>/Data Type Conversion' */
  real_T gate_ah;                      /* '<S121>/(gate)' */
  real_T donotdeletethisgain_a;        /* '<S20>/do not delete this gain' */
  real_T donotdeletethisgain_o;        /* '<S19>/do not delete this gain' */
} B_final_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T StateSpace_RWORK[2];          /* '<S135>/State-Space' */
  real_T StateSpace_RWORK_p[2];        /* '<S136>/State-Space' */
  real_T StateSpace_RWORK_h[2];        /* '<S137>/State-Space' */
  void *StateSpace_PWORK[22];          /* '<S135>/State-Space' */
  void *StateSpace_PWORK_e[22];        /* '<S136>/State-Space' */
  void *StateSpace_PWORK_m[22];        /* '<S137>/State-Space' */
  int_T StateSpace_IWORK[23];          /* '<S135>/State-Space' */
  int_T StateSpace_IWORK_d[23];        /* '<S136>/State-Space' */
  int_T StateSpace_IWORK_c[23];        /* '<S137>/State-Space' */
  int_T StateSpace_MODE[9];            /* '<S135>/State-Space' */
  int_T StateSpace_MODE_h[9];          /* '<S136>/State-Space' */
  int_T StateSpace_MODE_i[9];          /* '<S137>/State-Space' */
} DW_final_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S32>/Integrator' */
  real_T StateSpace_CSTATE[2];         /* '<S135>/State-Space' */
  real_T Integrator_CSTATE_k;          /* '<S22>/Integrator' */
  real_T StateSpace_CSTATE_g[2];       /* '<S136>/State-Space' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn3_CSTATE;          /* '<S14>/Transfer Fcn3' */
  real_T TransferFcn5_CSTATE;          /* '<S15>/Transfer Fcn5' */
  real_T TransferFcn4_CSTATE;          /* '<Root>/Transfer Fcn4' */
  real_T TransferFcn3_CSTATE_a;        /* '<Root>/Transfer Fcn3' */
} X_final_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S32>/Integrator' */
  real_T StateSpace_CSTATE[2];         /* '<S135>/State-Space' */
  real_T Integrator_CSTATE_k;          /* '<S22>/Integrator' */
  real_T StateSpace_CSTATE_g[2];       /* '<S136>/State-Space' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn3_CSTATE;          /* '<S14>/Transfer Fcn3' */
  real_T TransferFcn5_CSTATE;          /* '<S15>/Transfer Fcn5' */
  real_T TransferFcn4_CSTATE;          /* '<Root>/Transfer Fcn4' */
  real_T TransferFcn3_CSTATE_a;        /* '<Root>/Transfer Fcn3' */
} XDot_final_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S32>/Integrator' */
  boolean_T StateSpace_CSTATE[2];      /* '<S135>/State-Space' */
  boolean_T Integrator_CSTATE_k;       /* '<S22>/Integrator' */
  boolean_T StateSpace_CSTATE_g[2];    /* '<S136>/State-Space' */
  boolean_T TransferFcn2_CSTATE;       /* '<Root>/Transfer Fcn2' */
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn3_CSTATE;       /* '<S14>/Transfer Fcn3' */
  boolean_T TransferFcn5_CSTATE;       /* '<S15>/Transfer Fcn5' */
  boolean_T TransferFcn4_CSTATE;       /* '<Root>/Transfer Fcn4' */
  boolean_T TransferFcn3_CSTATE_a;     /* '<Root>/Transfer Fcn3' */
} XDis_final_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_final_T_ {
  real_T IaN;                          /* Variable: IaN
                                        * Referenced by:
                                        *   '<Root>/Ia sat'
                                        *   '<Root>/Ia sat1'
                                        *   '<S15>/Ia sat1'
                                        */
  real_T KT;                           /* Variable: KT
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain10'
                                        *   '<Root>/Gain11'
                                        */
  real_T Kac;                          /* Variable: Kac
                                        * Referenced by:
                                        *   '<Root>/Gain13'
                                        *   '<Root>/Gain2'
                                        *   '<S14>/Gain12'
                                        */
  real_T Kas;                          /* Variable: Kas
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain12'
                                        *   '<S15>/Gain11'
                                        */
  real_T Kic;                          /* Variable: Kic
                                        * Referenced by:
                                        *   '<Root>/Gain16'
                                        *   '<Root>/Gain5'
                                        *   '<S14>/Gain15'
                                        */
  real_T Kis;                          /* Variable: Kis
                                        * Referenced by:
                                        *   '<Root>/Gain18'
                                        *   '<Root>/Gain6'
                                        *   '<S15>/Gain16'
                                        */
  real_T Kpc;                          /* Variable: Kpc
                                        * Referenced by:
                                        *   '<Root>/Gain15'
                                        *   '<Root>/Gain4'
                                        *   '<S14>/Gain14'
                                        */
  real_T Kps;                          /* Variable: Kps
                                        * Referenced by:
                                        *   '<Root>/Gain14'
                                        *   '<Root>/Gain3'
                                        *   '<S15>/Gain13'
                                        */
  real_T UaN;                          /* Variable: UaN
                                        * Referenced by:
                                        *   '<Root>/Gain21'
                                        *   '<Root>/Gain8'
                                        *   '<Root>/Ua sat'
                                        *   '<Root>/Ua sat1'
                                        *   '<S14>/Ua sat1'
                                        *   '<S16>/Gain18'
                                        *   '<S30>/DC'
                                        *   '<S31>/DC'
                                        *   '<S46>/DC'
                                        */
  real_T CoulombTfViscousBmwFrictionTorq;
                              /* Mask Parameter: CoulombTfViscousBmwFrictionTorq
                               * Referenced by: '<S27>/Gain'
                               */
  real_T CoulombTfViscousBmwFrictionTo_l;
                              /* Mask Parameter: CoulombTfViscousBmwFrictionTo_l
                               * Referenced by: '<S37>/Gain'
                               */
  real_T CoulombTfViscousBmwFrictionTo_i;
                              /* Mask Parameter: CoulombTfViscousBmwFrictionTo_i
                               * Referenced by: '<S27>/Gain1'
                               */
  real_T CoulombTfViscousBmwFrictionTo_g;
                              /* Mask Parameter: CoulombTfViscousBmwFrictionTo_g
                               * Referenced by: '<S37>/Gain1'
                               */
  real_T Triangle_rep_seq_y[3];        /* Mask Parameter: Triangle_rep_seq_y
                                        * Referenced by: '<S17>/Look-Up Table1'
                                        */
  real_T Triangle1_rep_seq_y[3];       /* Mask Parameter: Triangle1_rep_seq_y
                                        * Referenced by: '<S132>/Look-Up Table1'
                                        */
  real_T Triangle1_rep_seq_y_k[3];     /* Mask Parameter: Triangle1_rep_seq_y_k
                                        * Referenced by: '<S18>/Look-Up Table1'
                                        */
  real_T Integrator_IC;                /* Expression: SM.w0
                                        * Referenced by: '<S32>/Integrator'
                                        */
  real_T Constant_Value;               /* Expression: SM.Ke
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T StateSpace_P1_Size[2];        /* Computed Parameter: StateSpace_P1_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P1[351];           /* Expression: S.Mg
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P2_Size[2];        /* Computed Parameter: StateSpace_P2_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P2[4];          /* Expression: [S.nb.x S.nb.u S.nb.y S.nb.s]
                                     * Referenced by: '<S135>/State-Space'
                                     */
  real_T StateSpace_P3_Size[2];        /* Computed Parameter: StateSpace_P3_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P3[2];             /* Expression: S.x0
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P4_Size[2];        /* Computed Parameter: StateSpace_P4_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P4[1026];          /* Computed Parameter: StateSpace_P4
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P5_Size[2];        /* Computed Parameter: StateSpace_P5_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P5[16];            /* Expression: S.SwitchVf
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P6_Size[2];        /* Computed Parameter: StateSpace_P6_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P6[8];             /* Expression: S.SwitchType
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P7_Size[2];        /* Computed Parameter: StateSpace_P7_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P7[8];             /* Expression: S.SwitchGateInitialValue
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P8_Size[2];        /* Computed Parameter: StateSpace_P8_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P8[8];             /* Expression: S.SwitchTolerance
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P9_Size[2];        /* Computed Parameter: StateSpace_P9_Size
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P9;                /* Expression: S.SaveMatrices
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T StateSpace_P10_Size[2];      /* Computed Parameter: StateSpace_P10_Size
                                       * Referenced by: '<S135>/State-Space'
                                       */
  real_T StateSpace_P10;               /* Expression: S.BufferSize
                                        * Referenced by: '<S135>/State-Space'
                                        */
  real_T Integrator_IC_d;              /* Expression: SM.w0
                                        * Referenced by: '<S22>/Integrator'
                                        */
  real_T Constant_Value_b;             /* Expression: SM.Ke
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T StateSpace_P1_Size_d[2];    /* Computed Parameter: StateSpace_P1_Size_d
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P1_o[351];         /* Expression: S.Mg
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P2_Size_o[2];    /* Computed Parameter: StateSpace_P2_Size_o
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P2_j[4];        /* Expression: [S.nb.x S.nb.u S.nb.y S.nb.s]
                                     * Referenced by: '<S136>/State-Space'
                                     */
  real_T StateSpace_P3_Size_o[2];    /* Computed Parameter: StateSpace_P3_Size_o
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P3_e[2];           /* Expression: S.x0
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P4_Size_g[2];    /* Computed Parameter: StateSpace_P4_Size_g
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P4_f[810];         /* Computed Parameter: StateSpace_P4_f
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P5_Size_c[2];    /* Computed Parameter: StateSpace_P5_Size_c
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P5_h[16];          /* Expression: S.SwitchVf
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P6_Size_h[2];    /* Computed Parameter: StateSpace_P6_Size_h
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P6_j[8];           /* Expression: S.SwitchType
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P7_Size_h[2];    /* Computed Parameter: StateSpace_P7_Size_h
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P7_j[8];           /* Expression: S.SwitchGateInitialValue
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P8_Size_d[2];    /* Computed Parameter: StateSpace_P8_Size_d
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P8_d[8];           /* Expression: S.SwitchTolerance
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P9_Size_k[2];    /* Computed Parameter: StateSpace_P9_Size_k
                                      * Referenced by: '<S136>/State-Space'
                                      */
  real_T StateSpace_P9_m;              /* Expression: S.SaveMatrices
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P10_Size_p[2];  /* Computed Parameter: StateSpace_P10_Size_p
                                     * Referenced by: '<S136>/State-Space'
                                     */
  real_T StateSpace_P10_a;             /* Expression: S.BufferSize
                                        * Referenced by: '<S136>/State-Space'
                                        */
  real_T StateSpace_P1_Size_f[2];    /* Computed Parameter: StateSpace_P1_Size_f
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P1_l[162];         /* Expression: S.Mg
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P2_Size_p[2];    /* Computed Parameter: StateSpace_P2_Size_p
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P2_p[4];        /* Expression: [S.nb.x S.nb.u S.nb.y S.nb.s]
                                     * Referenced by: '<S137>/State-Space'
                                     */
  real_T StateSpace_P3_Size_g[2];    /* Computed Parameter: StateSpace_P3_Size_g
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P4_Size_i[2];    /* Computed Parameter: StateSpace_P4_Size_i
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P4_p[522];         /* Computed Parameter: StateSpace_P4_p
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P5_Size_i[2];    /* Computed Parameter: StateSpace_P5_Size_i
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P5_n[16];          /* Expression: S.SwitchVf
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P6_Size_p[2];    /* Computed Parameter: StateSpace_P6_Size_p
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P6_p[8];           /* Expression: S.SwitchType
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P7_Size_b[2];    /* Computed Parameter: StateSpace_P7_Size_b
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P7_d[8];           /* Expression: S.SwitchGateInitialValue
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P8_Size_j[2];    /* Computed Parameter: StateSpace_P8_Size_j
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P8_b[8];           /* Expression: S.SwitchTolerance
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P9_Size_c[2];    /* Computed Parameter: StateSpace_P9_Size_c
                                      * Referenced by: '<S137>/State-Space'
                                      */
  real_T StateSpace_P9_b;              /* Expression: S.SaveMatrices
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T StateSpace_P10_Size_e[2];  /* Computed Parameter: StateSpace_P10_Size_e
                                     * Referenced by: '<S137>/State-Space'
                                     */
  real_T StateSpace_P10_n;             /* Expression: S.BufferSize
                                        * Referenced by: '<S137>/State-Space'
                                        */
  real_T Step_Time;                    /* Expression: .15
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 3000
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: -2500
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1/9.55
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T Step1_Time;                   /* Expression: .3
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: -4
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Gain9_Gain;                   /* Expression: 10
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T donotdeletethisgain_Gain;     /* Expression: 1
                                        * Referenced by: '<S25>/do not delete this gain'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/SM.J
                                        * Referenced by: '<S22>/Gain2'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T Constant_Value_m;             /* Expression: period
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[3];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S17>/Look-Up Table1'
                                        */
  real_T gate_Value;                   /* Expression: 0
                                        * Referenced by: '<S86>/(gate)'
                                        */
  real_T gate_Value_m;                 /* Expression: 0
                                        * Referenced by: '<S93>/(gate)'
                                        */
  real_T gate_Value_j;                 /* Expression: 0
                                        * Referenced by: '<S100>/(gate)'
                                        */
  real_T gate_Value_c;                 /* Expression: 0
                                        * Referenced by: '<S128>/(gate)'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<S14>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<S14>/Transfer Fcn3'
                                        */
  real_T TransferFcn5_A;               /* Computed Parameter: TransferFcn5_A
                                        * Referenced by: '<S15>/Transfer Fcn5'
                                        */
  real_T TransferFcn5_C;               /* Computed Parameter: TransferFcn5_C
                                        * Referenced by: '<S15>/Transfer Fcn5'
                                        */
  real_T Step2_Time;                   /* Expression: .01
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: 3000
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Gain17_Gain;                  /* Expression: 1/9.55
                                        * Referenced by: '<Root>/Gain17'
                                        */
  real_T donotdeletethisgain_Gain_e;   /* Expression: 1
                                        * Referenced by: '<S35>/do not delete this gain'
                                        */
  real_T Constant_Value_l;             /* Expression: period
                                        * Referenced by: '<S132>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_m[3];   /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S132>/Look-Up Table1'
                                        */
  real_T gate_Value_h;                 /* Expression: 0
                                        * Referenced by: '<S57>/(gate)'
                                        */
  real_T gate_Value_e;                 /* Expression: 0
                                        * Referenced by: '<S64>/(gate)'
                                        */
  real_T gate_Value_i;                 /* Expression: 0
                                        * Referenced by: '<S50>/(gate)'
                                        */
  real_T gate_Value_k;                 /* Expression: 0
                                        * Referenced by: '<S71>/(gate)'
                                        */
  real_T donotdeletethisgain_Gain_l;   /* Expression: 1
                                        * Referenced by: '<S45>/do not delete this gain'
                                        */
  real_T Step3_Time;                   /* Expression: .1
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: 8
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Gain19_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/Gain19'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: 1/SM.J
                                        * Referenced by: '<S32>/Gain2'
                                        */
  real_T Step5_Time;                   /* Expression: .3
                                        * Referenced by: '<Root>/Step5'
                                        */
  real_T Step5_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step5'
                                        */
  real_T Step5_YFinal;                 /* Expression: -4
                                        * Referenced by: '<Root>/Step5'
                                        */
  real_T TransferFcn4_A;               /* Computed Parameter: TransferFcn4_A
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_C;               /* Computed Parameter: TransferFcn4_C
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  real_T Step4_Time;                   /* Expression: .15
                                        * Referenced by: '<Root>/Step4'
                                        */
  real_T Step4_Y0;                     /* Expression: 3000
                                        * Referenced by: '<Root>/Step4'
                                        */
  real_T Step4_YFinal;                 /* Expression: -2500
                                        * Referenced by: '<Root>/Step4'
                                        */
  real_T Gain20_Gain;                  /* Expression: 1/9.55
                                        * Referenced by: '<Root>/Gain20'
                                        */
  real_T Gain22_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/Gain22'
                                        */
  real_T TransferFcn3_A_f;             /* Computed Parameter: TransferFcn3_A_f
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C_o;             /* Computed Parameter: TransferFcn3_C_o
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T Constant_Value_d;             /* Expression: period
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T LookUpTable1_bp01Data_p[3];   /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S18>/Look-Up Table1'
                                        */
  real_T gate_Value_f;                 /* Expression: 0
                                        * Referenced by: '<S79>/(gate)'
                                        */
  real_T gate_Value_b;                 /* Expression: 0
                                        * Referenced by: '<S107>/(gate)'
                                        */
  real_T gate_Value_g;                 /* Expression: 0
                                        * Referenced by: '<S114>/(gate)'
                                        */
  real_T gate_Value_bc;                /* Expression: 0
                                        * Referenced by: '<S121>/(gate)'
                                        */
  real_T donotdeletethisgain_Gain_n;   /* Expression: 1
                                        * Referenced by: '<S20>/do not delete this gain'
                                        */
  real_T donotdeletethisgain_Gain_h;   /* Expression: 1
                                        * Referenced by: '<S19>/do not delete this gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_final_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[3];
    SimStruct *childSFunctionPtrs[3];
    struct _ssBlkInfo2 blkInfo2[3];
    struct _ssSFcnModelMethods2 methods2[3];
    struct _ssSFcnModelMethods3 methods3[3];
    struct _ssSFcnModelMethods4 methods4[3];
    struct _ssStatesInfo2 statesInfo2[3];
    ssPeriodicStatesInfo periodicStatesInfo[3];
    struct _ssPortInfo2 inputOutputPortInfo2[3];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[8];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[4];
      struct _ssDWorkAuxRecord dWorkAux[4];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[8];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[4];
      struct _ssDWorkAuxRecord dWorkAux[4];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[8];
      struct _ssPortOutputs outputPortInfo[2];
      struct _ssOutPortUnit outputPortUnits[2];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[2];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[4];
      struct _ssDWorkAuxRecord dWorkAux[4];
    } Sfcn2;
  } NonInlinedSFcns;

  X_final_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_final_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_final_T final_P;

/* Block signals (default storage) */
extern B_final_T final_B;

/* Continuous states (default storage) */
extern X_final_T final_X;

/* Block states (default storage) */
extern DW_final_T final_DW;

/* Model entry point functions */
extern void final_initialize(void);
extern void final_step(void);
extern void final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_final_T *const final_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'final'
 * '<S1>'   : 'final/DC Motor'
 * '<S2>'   : 'final/DC Voltage Source1'
 * '<S3>'   : 'final/DC Voltage Source3'
 * '<S4>'   : 'final/DC motor 1'
 * '<S5>'   : 'final/H-bridge'
 * '<S6>'   : 'final/Mosfet1'
 * '<S7>'   : 'final/Mosfet10'
 * '<S8>'   : 'final/Mosfet11'
 * '<S9>'   : 'final/Mosfet12'
 * '<S10>'  : 'final/Mosfet2'
 * '<S11>'  : 'final/Mosfet3'
 * '<S12>'  : 'final/Mosfet4'
 * '<S13>'  : 'final/Mosfet9'
 * '<S14>'  : 'final/PI current controller'
 * '<S15>'  : 'final/PI speed controller'
 * '<S16>'  : 'final/PWM generator'
 * '<S17>'  : 'final/Triangle'
 * '<S18>'  : 'final/Triangle1'
 * '<S19>'  : 'final/Voltage Measurement'
 * '<S20>'  : 'final/Voltage Measurement1'
 * '<S21>'  : 'final/powergui'
 * '<S22>'  : 'final/DC Motor/Electrical model'
 * '<S23>'  : 'final/DC Motor/FCEM'
 * '<S24>'  : 'final/DC Motor/Mechanical model'
 * '<S25>'  : 'final/DC Motor/iA'
 * '<S26>'  : 'final/DC Motor/iF'
 * '<S27>'  : 'final/DC Motor/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques'
 * '<S28>'  : 'final/DC Motor/iA/Model'
 * '<S29>'  : 'final/DC Motor/iF/Model'
 * '<S30>'  : 'final/DC Voltage Source1/Model'
 * '<S31>'  : 'final/DC Voltage Source3/Model'
 * '<S32>'  : 'final/DC motor 1/Electrical model'
 * '<S33>'  : 'final/DC motor 1/FCEM'
 * '<S34>'  : 'final/DC motor 1/Mechanical model'
 * '<S35>'  : 'final/DC motor 1/iA'
 * '<S36>'  : 'final/DC motor 1/iF'
 * '<S37>'  : 'final/DC motor 1/Electrical model/Coulomb (Tf) & Viscous ( Bm*w)  Friction Torques'
 * '<S38>'  : 'final/DC motor 1/iA/Model'
 * '<S39>'  : 'final/DC motor 1/iF/Model'
 * '<S40>'  : 'final/H-bridge/DC Voltage Source1'
 * '<S41>'  : 'final/H-bridge/Mosfet1'
 * '<S42>'  : 'final/H-bridge/Mosfet2'
 * '<S43>'  : 'final/H-bridge/Mosfet3'
 * '<S44>'  : 'final/H-bridge/Mosfet4'
 * '<S45>'  : 'final/H-bridge/Voltage Measurement1'
 * '<S46>'  : 'final/H-bridge/DC Voltage Source1/Model'
 * '<S47>'  : 'final/H-bridge/Mosfet1/Diode'
 * '<S48>'  : 'final/H-bridge/Mosfet1/Ideal Switch'
 * '<S49>'  : 'final/H-bridge/Mosfet1/Measurement list'
 * '<S50>'  : 'final/H-bridge/Mosfet1/Diode/Model'
 * '<S51>'  : 'final/H-bridge/Mosfet1/Diode/Model/Measurement list'
 * '<S52>'  : 'final/H-bridge/Mosfet1/Ideal Switch/Model'
 * '<S53>'  : 'final/H-bridge/Mosfet1/Ideal Switch/Model/Measurement list'
 * '<S54>'  : 'final/H-bridge/Mosfet2/Diode'
 * '<S55>'  : 'final/H-bridge/Mosfet2/Ideal Switch'
 * '<S56>'  : 'final/H-bridge/Mosfet2/Measurement list'
 * '<S57>'  : 'final/H-bridge/Mosfet2/Diode/Model'
 * '<S58>'  : 'final/H-bridge/Mosfet2/Diode/Model/Measurement list'
 * '<S59>'  : 'final/H-bridge/Mosfet2/Ideal Switch/Model'
 * '<S60>'  : 'final/H-bridge/Mosfet2/Ideal Switch/Model/Measurement list'
 * '<S61>'  : 'final/H-bridge/Mosfet3/Diode'
 * '<S62>'  : 'final/H-bridge/Mosfet3/Ideal Switch'
 * '<S63>'  : 'final/H-bridge/Mosfet3/Measurement list'
 * '<S64>'  : 'final/H-bridge/Mosfet3/Diode/Model'
 * '<S65>'  : 'final/H-bridge/Mosfet3/Diode/Model/Measurement list'
 * '<S66>'  : 'final/H-bridge/Mosfet3/Ideal Switch/Model'
 * '<S67>'  : 'final/H-bridge/Mosfet3/Ideal Switch/Model/Measurement list'
 * '<S68>'  : 'final/H-bridge/Mosfet4/Diode'
 * '<S69>'  : 'final/H-bridge/Mosfet4/Ideal Switch'
 * '<S70>'  : 'final/H-bridge/Mosfet4/Measurement list'
 * '<S71>'  : 'final/H-bridge/Mosfet4/Diode/Model'
 * '<S72>'  : 'final/H-bridge/Mosfet4/Diode/Model/Measurement list'
 * '<S73>'  : 'final/H-bridge/Mosfet4/Ideal Switch/Model'
 * '<S74>'  : 'final/H-bridge/Mosfet4/Ideal Switch/Model/Measurement list'
 * '<S75>'  : 'final/H-bridge/Voltage Measurement1/Model'
 * '<S76>'  : 'final/Mosfet1/Diode'
 * '<S77>'  : 'final/Mosfet1/Ideal Switch'
 * '<S78>'  : 'final/Mosfet1/Measurement list'
 * '<S79>'  : 'final/Mosfet1/Diode/Model'
 * '<S80>'  : 'final/Mosfet1/Diode/Model/Measurement list'
 * '<S81>'  : 'final/Mosfet1/Ideal Switch/Model'
 * '<S82>'  : 'final/Mosfet1/Ideal Switch/Model/Measurement list'
 * '<S83>'  : 'final/Mosfet10/Diode'
 * '<S84>'  : 'final/Mosfet10/Ideal Switch'
 * '<S85>'  : 'final/Mosfet10/Measurement list'
 * '<S86>'  : 'final/Mosfet10/Diode/Model'
 * '<S87>'  : 'final/Mosfet10/Diode/Model/Measurement list'
 * '<S88>'  : 'final/Mosfet10/Ideal Switch/Model'
 * '<S89>'  : 'final/Mosfet10/Ideal Switch/Model/Measurement list'
 * '<S90>'  : 'final/Mosfet11/Diode'
 * '<S91>'  : 'final/Mosfet11/Ideal Switch'
 * '<S92>'  : 'final/Mosfet11/Measurement list'
 * '<S93>'  : 'final/Mosfet11/Diode/Model'
 * '<S94>'  : 'final/Mosfet11/Diode/Model/Measurement list'
 * '<S95>'  : 'final/Mosfet11/Ideal Switch/Model'
 * '<S96>'  : 'final/Mosfet11/Ideal Switch/Model/Measurement list'
 * '<S97>'  : 'final/Mosfet12/Diode'
 * '<S98>'  : 'final/Mosfet12/Ideal Switch'
 * '<S99>'  : 'final/Mosfet12/Measurement list'
 * '<S100>' : 'final/Mosfet12/Diode/Model'
 * '<S101>' : 'final/Mosfet12/Diode/Model/Measurement list'
 * '<S102>' : 'final/Mosfet12/Ideal Switch/Model'
 * '<S103>' : 'final/Mosfet12/Ideal Switch/Model/Measurement list'
 * '<S104>' : 'final/Mosfet2/Diode'
 * '<S105>' : 'final/Mosfet2/Ideal Switch'
 * '<S106>' : 'final/Mosfet2/Measurement list'
 * '<S107>' : 'final/Mosfet2/Diode/Model'
 * '<S108>' : 'final/Mosfet2/Diode/Model/Measurement list'
 * '<S109>' : 'final/Mosfet2/Ideal Switch/Model'
 * '<S110>' : 'final/Mosfet2/Ideal Switch/Model/Measurement list'
 * '<S111>' : 'final/Mosfet3/Diode'
 * '<S112>' : 'final/Mosfet3/Ideal Switch'
 * '<S113>' : 'final/Mosfet3/Measurement list'
 * '<S114>' : 'final/Mosfet3/Diode/Model'
 * '<S115>' : 'final/Mosfet3/Diode/Model/Measurement list'
 * '<S116>' : 'final/Mosfet3/Ideal Switch/Model'
 * '<S117>' : 'final/Mosfet3/Ideal Switch/Model/Measurement list'
 * '<S118>' : 'final/Mosfet4/Diode'
 * '<S119>' : 'final/Mosfet4/Ideal Switch'
 * '<S120>' : 'final/Mosfet4/Measurement list'
 * '<S121>' : 'final/Mosfet4/Diode/Model'
 * '<S122>' : 'final/Mosfet4/Diode/Model/Measurement list'
 * '<S123>' : 'final/Mosfet4/Ideal Switch/Model'
 * '<S124>' : 'final/Mosfet4/Ideal Switch/Model/Measurement list'
 * '<S125>' : 'final/Mosfet9/Diode'
 * '<S126>' : 'final/Mosfet9/Ideal Switch'
 * '<S127>' : 'final/Mosfet9/Measurement list'
 * '<S128>' : 'final/Mosfet9/Diode/Model'
 * '<S129>' : 'final/Mosfet9/Diode/Model/Measurement list'
 * '<S130>' : 'final/Mosfet9/Ideal Switch/Model'
 * '<S131>' : 'final/Mosfet9/Ideal Switch/Model/Measurement list'
 * '<S132>' : 'final/PWM generator/Triangle1'
 * '<S133>' : 'final/Voltage Measurement/Model'
 * '<S134>' : 'final/Voltage Measurement1/Model'
 * '<S135>' : 'final/powergui/EquivalentModel1'
 * '<S136>' : 'final/powergui/EquivalentModel2'
 * '<S137>' : 'final/powergui/EquivalentModel3'
 * '<S138>' : 'final/powergui/EquivalentModel1/Gates'
 * '<S139>' : 'final/powergui/EquivalentModel1/Sources'
 * '<S140>' : 'final/powergui/EquivalentModel1/Status'
 * '<S141>' : 'final/powergui/EquivalentModel1/Yout'
 * '<S142>' : 'final/powergui/EquivalentModel2/Gates'
 * '<S143>' : 'final/powergui/EquivalentModel2/Sources'
 * '<S144>' : 'final/powergui/EquivalentModel2/Status'
 * '<S145>' : 'final/powergui/EquivalentModel2/Yout'
 * '<S146>' : 'final/powergui/EquivalentModel3/Gates'
 * '<S147>' : 'final/powergui/EquivalentModel3/Sources'
 * '<S148>' : 'final/powergui/EquivalentModel3/Status'
 * '<S149>' : 'final/powergui/EquivalentModel3/Yout'
 */
#endif                                 /* RTW_HEADER_final_h_ */
