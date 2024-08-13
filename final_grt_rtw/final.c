/*
 * final.c
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

#include "final.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "final_private.h"
#include <math.h>
#include <float.h>
#include <string.h>

/* Block signals (default storage) */
B_final_T final_B;

/* Continuous states */
X_final_T final_X;

/* Block states (default storage) */
DW_final_T final_DW;

/* Real-time model */
static RT_MODEL_final_T final_M_;
RT_MODEL_final_T *const final_M = &final_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/* Projection for root system: '<Root>' */
void final_projection(void)
{
  /* Projection for S-Function (sfun_spid_contc): '<S135>/State-Space' */
  /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[0];
    sfcnProjection(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Projection for S-Function (sfun_spid_contc): '<S136>/State-Space' */
  /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[1];
    sfcnProjection(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  final_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  final_step();
  final_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  final_step();
  final_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  final_step();
  final_projection();
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    real_T q;
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model step function */
void final_step(void)
{
  real_T rtb_Gain1_m;
  real_T rtb_Iaref;
  real_T rtb_LookUpTable1;
  real_T rtb_Sum11;
  real_T rtb_Sum13;
  real_T rtb_Sum13_i;
  real_T rtb_Sum14;
  real_T rtb_Uaref;
  real_T tmp;
  real_T u1_tmp;
  real_T u2_tmp;
  boolean_T rtb_NOT1;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* set solver stop time */
    if (!(final_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&final_M->solverInfo, ((final_M->Timing.clockTickH0
        + 1) * final_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&final_M->solverInfo, ((final_M->Timing.clockTick0 +
        1) * final_M->Timing.stepSize0 + final_M->Timing.clockTickH0 *
        final_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(final_M)) {
    final_M->Timing.t[0] = rtsiGetT(&final_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S46>/DC' */
    final_B.DC = final_P.UaN;
  }

  /* Integrator: '<S32>/Integrator' */
  final_B.w = final_X.Integrator_CSTATE;

  /* Product: '<S32>/Product' incorporates:
   *  Constant: '<S32>/Constant'
   */
  final_B.Efcem = final_B.w * final_P.Constant_Value;

  /* S-Function (sfun_spid_contc): '<S135>/State-Space' */

  /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S31>/DC' */
    final_B.DC_p = final_P.UaN;
  }

  /* Integrator: '<S22>/Integrator' */
  final_B.w_k = final_X.Integrator_CSTATE_k;

  /* Product: '<S22>/Product' incorporates:
   *  Constant: '<S22>/Constant'
   */
  final_B.Efcem_g = final_B.w_k * final_P.Constant_Value_b;

  /* S-Function (sfun_spid_contc): '<S136>/State-Space' */

  /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S30>/DC' */
    final_B.DC_g = final_P.UaN;
  }

  /* S-Function (sfun_spid_contc): '<S137>/State-Space' */

  /* Level2 S-Function Block: '<S137>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Step: '<Root>/Step' incorporates:
   *  Step: '<Root>/Step1'
   *  Step: '<Root>/Step2'
   *  Step: '<Root>/Step3'
   *  Step: '<Root>/Step4'
   *  Step: '<Root>/Step5'
   */
  rtb_LookUpTable1 = final_M->Timing.t[0];
  if (rtb_LookUpTable1 < final_P.Step_Time) {
    tmp = final_P.Step_Y0;
  } else {
    tmp = final_P.Step_YFinal;
  }

  /* Gain: '<Root>/Gain7' incorporates:
   *  Step: '<Root>/Step'
   */
  final_B.SpeedSP = final_P.Gain7_Gain * tmp;

  /* Step: '<Root>/Step1' */
  if (rtb_LookUpTable1 < final_P.Step1_Time) {
    /* Step: '<Root>/Step1' */
    final_B.TL = final_P.Step1_Y0;
  } else {
    /* Step: '<Root>/Step1' */
    final_B.TL = final_P.Step1_YFinal;
  }

  /* Gain: '<Root>/Gain9' */
  final_B.Gain9 = final_P.Gain9_Gain * final_B.TL;
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Gain: '<S25>/do not delete this gain' */
  final_B.donotdeletethisgain = final_P.donotdeletethisgain_Gain *
    final_B.StateSpace_o1_m[1];
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Product: '<S22>/Product1' incorporates:
   *  Constant: '<S22>/Constant'
   */
  final_B.Te = final_B.donotdeletethisgain * final_P.Constant_Value_b;
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Sum: '<Root>/Sum3' */
  rtb_Sum13 = final_B.SpeedSP - final_B.w_k;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Gain: '<Root>/Gain3'
   *  TransferFcn: '<Root>/Transfer Fcn2'
   */
  rtb_Iaref = final_P.TransferFcn2_C * final_X.TransferFcn2_CSTATE + final_P.Kps
    * rtb_Sum13;

  /* Saturate: '<Root>/Ia sat' incorporates:
   *  Saturate: '<Root>/Ia sat1'
   */
  u1_tmp = -final_P.IaN * 8.0;
  u2_tmp = final_P.IaN * 8.0;
  if (rtb_Iaref > u2_tmp) {
    /* Saturate: '<Root>/Ia sat' */
    final_B.Iaref = u2_tmp;
  } else if (rtb_Iaref < u1_tmp) {
    /* Saturate: '<Root>/Ia sat' */
    final_B.Iaref = u1_tmp;
  } else {
    /* Saturate: '<Root>/Ia sat' */
    final_B.Iaref = rtb_Iaref;
  }

  /* End of Saturate: '<Root>/Ia sat' */
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Signum: '<S27>/Sign' */
  if (rtIsNaN(final_B.w_k)) {
    tmp = (rtNaN);
  } else if (final_B.w_k < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (final_B.w_k > 0.0);
  }

  /* Gain: '<S22>/Gain2' incorporates:
   *  Gain: '<S27>/Gain'
   *  Gain: '<S27>/Gain1'
   *  Signum: '<S27>/Sign'
   *  Sum: '<S22>/Sum'
   *  Sum: '<S27>/Sum'
   */
  final_B.A = ((final_B.Te - final_B.TL) -
               (final_P.CoulombTfViscousBmwFrictionTo_i * tmp +
                final_P.CoulombTfViscousBmwFrictionTorq * final_B.w_k)) *
    final_P.Gain2_Gain;

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  rtb_Gain1_m = (rtb_Iaref - final_B.Iaref) * final_P.Kas;

  /* Sum: '<Root>/Sum10' */
  rtb_Sum14 = final_B.Iaref - final_B.donotdeletethisgain;

  /* Sum: '<Root>/Sum5' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain4'
   *  Sum: '<Root>/Sum6'
   *  TransferFcn: '<Root>/Transfer Fcn1'
   */
  rtb_Iaref = (final_P.TransferFcn1_C * final_X.TransferFcn1_CSTATE +
               final_P.Kpc * rtb_Sum14) + final_P.KT * final_B.w_k;

  /* Saturate: '<Root>/Ua sat' */
  if (rtb_Iaref > final_P.UaN) {
    rtb_Uaref = final_P.UaN;
  } else if (rtb_Iaref < -final_P.UaN) {
    rtb_Uaref = -final_P.UaN;
  } else {
    rtb_Uaref = rtb_Iaref;
  }

  /* End of Saturate: '<Root>/Ua sat' */

  /* Gain: '<Root>/Gain5' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum7'
   */
  final_B.Gain5 = (rtb_Sum14 - (rtb_Iaref - rtb_Uaref) * final_P.Kac) *
    final_P.Kic;

  /* Gain: '<Root>/Gain6' incorporates:
   *  Sum: '<Root>/Sum8'
   */
  final_B.Gain6 = (rtb_Sum13 - rtb_Gain1_m) * final_P.Kis;

  /* Clock: '<S17>/Clock' incorporates:
   *  Clock: '<S132>/Clock'
   *  Clock: '<S18>/Clock'
   */
  rtb_Gain1_m = final_M->Timing.t[0];

  /* RelationalOperator: '<Root>/Relational Operator3' incorporates:
   *  Clock: '<S17>/Clock'
   *  Constant: '<S17>/Constant'
   *  Gain: '<Root>/Gain8'
   *  Lookup_n-D: '<S17>/Look-Up Table1'
   *  Math: '<S17>/Math Function'
   */
  rtb_NOT1 = (1.0 / final_P.UaN * rtb_Uaref > look1_binlxpw(rt_remd_snf
    (rtb_Gain1_m, final_P.Constant_Value_m), final_P.LookUpTable1_bp01Data,
    final_P.Triangle_rep_seq_y, 2U));

  /* Logic: '<Root>/NOT3' */
  rtb_RelationalOperator1 = !rtb_NOT1;

  /* DataTypeConversion: '<S88>/Data Type Conversion' */
  final_B.DataTypeConversion = rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S86>/(gate)' */
    final_B.gate = final_P.gate_Value;

    /* Constant: '<S93>/(gate)' */
    final_B.gate_j = final_P.gate_Value_m;
  }

  /* DataTypeConversion: '<S95>/Data Type Conversion' */
  final_B.DataTypeConversion_j = rtb_NOT1;

  /* DataTypeConversion: '<S102>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S95>/Data Type Conversion'
   */
  final_B.DataTypeConversion_e = rtb_NOT1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S100>/(gate)' */
    final_B.gate_h = final_P.gate_Value_j;

    /* Constant: '<S128>/(gate)' */
    final_B.gate_d = final_P.gate_Value_c;
  }

  /* DataTypeConversion: '<S130>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S88>/Data Type Conversion'
   */
  final_B.DataTypeConversion_h = rtb_RelationalOperator1;

  /* Step: '<Root>/Step2' */
  if (rtb_LookUpTable1 < final_P.Step2_Time) {
    tmp = final_P.Step2_Y0;
  } else {
    tmp = final_P.Step2_YFinal;
  }

  /* Gain: '<Root>/Gain17' incorporates:
   *  Step: '<Root>/Step2'
   */
  final_B.SpeedSP_h = final_P.Gain17_Gain * tmp;

  /* Sum: '<S15>/Sum13' */
  rtb_Sum13 = final_B.SpeedSP_h - final_B.w;

  /* Sum: '<S15>/Sum14' incorporates:
   *  Gain: '<S15>/Gain13'
   *  TransferFcn: '<S15>/Transfer Fcn5'
   */
  rtb_Sum14 = final_P.TransferFcn5_C * final_X.TransferFcn5_CSTATE + final_P.Kps
    * rtb_Sum13;

  /* Saturate: '<S15>/Ia sat1' */
  rtb_Iaref = -final_P.IaN * 7.0;
  rtb_Uaref = final_P.IaN * 7.0;
  if (rtb_Sum14 > rtb_Uaref) {
    rtb_Iaref = rtb_Uaref;
  } else if (!(rtb_Sum14 < rtb_Iaref)) {
    rtb_Iaref = rtb_Sum14;
  }

  /* End of Saturate: '<S15>/Ia sat1' */

  /* Gain: '<S35>/do not delete this gain' */
  final_B.donotdeletethisgain_p = final_P.donotdeletethisgain_Gain_e *
    final_B.StateSpace_o1[1];

  /* Sum: '<S14>/Sum11' */
  rtb_Sum11 = rtb_Iaref - final_B.donotdeletethisgain_p;

  /* Sum: '<S14>/Sum15' incorporates:
   *  Gain: '<Root>/Gain10'
   *  Gain: '<S14>/Gain14'
   *  Sum: '<S14>/Sum16'
   *  TransferFcn: '<S14>/Transfer Fcn3'
   */
  rtb_Uaref = (final_P.TransferFcn3_C * final_X.TransferFcn3_CSTATE +
               final_P.Kpc * rtb_Sum11) + final_P.KT * final_B.w;

  /* Saturate: '<S14>/Ua sat1' */
  if (rtb_Uaref > final_P.UaN) {
    rtb_Sum13_i = final_P.UaN;
  } else if (rtb_Uaref < -final_P.UaN) {
    rtb_Sum13_i = -final_P.UaN;
  } else {
    rtb_Sum13_i = rtb_Uaref;
  }

  /* End of Saturate: '<S14>/Ua sat1' */

  /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
   *  Constant: '<S132>/Constant'
   *  Gain: '<S16>/Gain18'
   *  Lookup_n-D: '<S132>/Look-Up Table1'
   *  Math: '<S132>/Math Function'
   */
  rtb_RelationalOperator1 = (1.0 / final_P.UaN * rtb_Sum13_i > look1_binlxpw
    (rt_remd_snf(rtb_Gain1_m, final_P.Constant_Value_l),
     final_P.LookUpTable1_bp01Data_m, final_P.Triangle1_rep_seq_y, 2U));

  /* DataTypeConversion: '<S59>/Data Type Conversion' */
  final_B.DataTypeConversion_g = rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S57>/(gate)' */
    final_B.gate_do = final_P.gate_Value_h;

    /* Constant: '<S64>/(gate)' */
    final_B.gate_m = final_P.gate_Value_e;
  }

  /* DataTypeConversion: '<S66>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S59>/Data Type Conversion'
   */
  final_B.DataTypeConversion_jf = rtb_RelationalOperator1;

  /* Logic: '<S16>/NOT1' */
  rtb_RelationalOperator1 = !rtb_RelationalOperator1;

  /* DataTypeConversion: '<S52>/Data Type Conversion' */
  final_B.DataTypeConversion_ef = rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S50>/(gate)' */
    final_B.gate_n = final_P.gate_Value_i;

    /* Constant: '<S71>/(gate)' */
    final_B.gate_jm = final_P.gate_Value_k;
  }

  /* DataTypeConversion: '<S73>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S52>/Data Type Conversion'
   */
  final_B.DataTypeConversion_m = rtb_RelationalOperator1;

  /* Gain: '<S45>/do not delete this gain' */
  final_B.donotdeletethisgain_e = final_P.donotdeletethisgain_Gain_l *
    final_B.StateSpace_o1[0];
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Step: '<Root>/Step3' */
  if (rtb_LookUpTable1 < final_P.Step3_Time) {
    /* Step: '<Root>/Step3' */
    final_B.TL_k = final_P.Step3_Y0;
  } else {
    /* Step: '<Root>/Step3' */
    final_B.TL_k = final_P.Step3_YFinal;
  }

  /* Gain: '<Root>/Gain19' */
  final_B.Gain19 = final_P.Gain19_Gain * final_B.TL_k;
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Product: '<S32>/Product1' incorporates:
   *  Constant: '<S32>/Constant'
   */
  final_B.Te_k = final_B.donotdeletethisgain_p * final_P.Constant_Value;
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Signum: '<S37>/Sign' */
  if (rtIsNaN(final_B.w)) {
    tmp = (rtNaN);
  } else if (final_B.w < 0.0) {
    tmp = -1.0;
  } else {
    tmp = (final_B.w > 0.0);
  }

  /* Gain: '<S32>/Gain2' incorporates:
   *  Gain: '<S37>/Gain'
   *  Gain: '<S37>/Gain1'
   *  Signum: '<S37>/Sign'
   *  Sum: '<S32>/Sum'
   *  Sum: '<S37>/Sum'
   */
  final_B.A_j = ((final_B.Te_k - final_B.TL_k) -
                 (final_P.CoulombTfViscousBmwFrictionTo_g * tmp +
                  final_P.CoulombTfViscousBmwFrictionTo_l * final_B.w)) *
    final_P.Gain2_Gain_f;

  /* Gain: '<S14>/Gain15' incorporates:
   *  Gain: '<S14>/Gain12'
   *  Sum: '<S14>/Sum17'
   *  Sum: '<S14>/Sum9'
   */
  final_B.Gain15 = (rtb_Sum11 - (rtb_Uaref - rtb_Sum13_i) * final_P.Kac) *
    final_P.Kic;

  /* Gain: '<S15>/Gain16' incorporates:
   *  Gain: '<S15>/Gain11'
   *  Sum: '<S15>/Sum12'
   *  Sum: '<S15>/Sum18'
   */
  final_B.Gain16 = (rtb_Sum13 - (rtb_Sum14 - rtb_Iaref) * final_P.Kas) *
    final_P.Kis;

  /* Step: '<Root>/Step5' */
  if (rtb_LookUpTable1 < final_P.Step5_Time) {
    /* Step: '<Root>/Step5' */
    final_B.TL_l = final_P.Step5_Y0;
  } else {
    /* Step: '<Root>/Step5' */
    final_B.TL_l = final_P.Step5_YFinal;
  }

  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Step: '<Root>/Step4' */
  if (rtb_LookUpTable1 < final_P.Step4_Time) {
    rtb_LookUpTable1 = final_P.Step4_Y0;
  } else {
    rtb_LookUpTable1 = final_P.Step4_YFinal;
  }

  /* Gain: '<Root>/Gain20' incorporates:
   *  Step: '<Root>/Step4'
   */
  final_B.SpeedSP_f = final_P.Gain20_Gain * rtb_LookUpTable1;

  /* Sum: '<Root>/Sum14' incorporates:
   *  Gain: '<Root>/Gain14'
   *  Sum: '<Root>/Sum13'
   *  TransferFcn: '<Root>/Transfer Fcn4'
   */
  rtb_LookUpTable1 = final_P.TransferFcn4_C * final_X.TransferFcn4_CSTATE +
    final_P.Kps * final_B.SpeedSP_f;

  /* Saturate: '<Root>/Ia sat1' */
  if (rtb_LookUpTable1 > u2_tmp) {
    /* Saturate: '<Root>/Ia sat1' */
    final_B.Iaref_d = u2_tmp;
  } else if (rtb_LookUpTable1 < u1_tmp) {
    /* Saturate: '<Root>/Ia sat1' */
    final_B.Iaref_d = u1_tmp;
  } else {
    /* Saturate: '<Root>/Ia sat1' */
    final_B.Iaref_d = rtb_LookUpTable1;
  }

  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Gain: '<Root>/Gain22' */
  final_B.Gain22 = final_P.Gain22_Gain * final_B.TL_l;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Gain: '<Root>/Gain11' */
    final_B.Eafeedforward = final_P.KT * 0.0;
  }

  /* Gain: '<Root>/Gain12' incorporates:
   *  Sum: '<Root>/Sum12'
   */
  rtb_Sum14 = (rtb_LookUpTable1 - final_B.Iaref_d) * final_P.Kas;

  /* Sum: '<Root>/Sum15' incorporates:
   *  Gain: '<Root>/Gain15'
   *  Sum: '<Root>/Sum11'
   *  Sum: '<Root>/Sum16'
   *  TransferFcn: '<Root>/Transfer Fcn3'
   */
  rtb_LookUpTable1 = (final_P.TransferFcn3_C_o * final_X.TransferFcn3_CSTATE_a +
                      final_P.Kpc * final_B.Iaref_d) + final_B.Eafeedforward;

  /* Saturate: '<Root>/Ua sat1' */
  if (rtb_LookUpTable1 > final_P.UaN) {
    rtb_Uaref = final_P.UaN;
  } else if (rtb_LookUpTable1 < -final_P.UaN) {
    rtb_Uaref = -final_P.UaN;
  } else {
    rtb_Uaref = rtb_LookUpTable1;
  }

  /* End of Saturate: '<Root>/Ua sat1' */

  /* Gain: '<Root>/Gain16' incorporates:
   *  Gain: '<Root>/Gain13'
   *  Sum: '<Root>/Sum11'
   *  Sum: '<Root>/Sum17'
   *  Sum: '<Root>/Sum9'
   */
  final_B.Gain16_a = (final_B.Iaref_d - (rtb_LookUpTable1 - rtb_Uaref) *
                      final_P.Kac) * final_P.Kic;

  /* Gain: '<Root>/Gain18' incorporates:
   *  Sum: '<Root>/Sum13'
   *  Sum: '<Root>/Sum18'
   */
  final_B.Gain18 = (final_B.SpeedSP_f - rtb_Sum14) * final_P.Kis;

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<S18>/Constant'
   *  Gain: '<Root>/Gain21'
   *  Lookup_n-D: '<S18>/Look-Up Table1'
   *  Math: '<S18>/Math Function'
   */
  rtb_RelationalOperator1 = (1.0 / final_P.UaN * rtb_Uaref > look1_binlxpw
    (rt_remd_snf(rtb_Gain1_m, final_P.Constant_Value_d),
     final_P.LookUpTable1_bp01Data_p, final_P.Triangle1_rep_seq_y_k, 2U));

  /* Logic: '<Root>/NOT1' */
  rtb_NOT1 = !rtb_RelationalOperator1;

  /* DataTypeConversion: '<S81>/Data Type Conversion' */
  final_B.DataTypeConversion_l = rtb_NOT1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S79>/(gate)' */
    final_B.gate_a = final_P.gate_Value_f;

    /* Constant: '<S107>/(gate)' */
    final_B.gate_jv = final_P.gate_Value_b;
  }

  /* DataTypeConversion: '<S109>/Data Type Conversion' */
  final_B.DataTypeConversion_jl = rtb_RelationalOperator1;

  /* DataTypeConversion: '<S116>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S109>/Data Type Conversion'
   */
  final_B.DataTypeConversion_jc = rtb_RelationalOperator1;

  /* DataTypeConversion: '<S123>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S81>/Data Type Conversion'
   */
  final_B.DataTypeConversion_p = rtb_NOT1;
  if (rtmIsMajorTimeStep(final_M)) {
    /* Constant: '<S114>/(gate)' */
    final_B.gate_hx = final_P.gate_Value_g;

    /* Constant: '<S121>/(gate)' */
    final_B.gate_ah = final_P.gate_Value_bc;
  }

  /* Gain: '<S20>/do not delete this gain' */
  final_B.donotdeletethisgain_a = final_P.donotdeletethisgain_Gain_n *
    final_B.StateSpace_o1_p;
  if (rtmIsMajorTimeStep(final_M)) {
  }

  /* Gain: '<S19>/do not delete this gain' */
  final_B.donotdeletethisgain_o = final_P.donotdeletethisgain_Gain_h *
    final_B.StateSpace_o1_m[0];
  if (rtmIsMajorTimeStep(final_M)) {
  }

  if (rtmIsMajorTimeStep(final_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(final_M->rtwLogInfo, (final_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(final_M)) {
    /* Update for S-Function (sfun_spid_contc): '<S135>/State-Space' */
    /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
    {
      SimStruct *rts = final_M->childSfunctions[0];
      sfcnUpdate(rts,0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Update for S-Function (sfun_spid_contc): '<S136>/State-Space' */
    /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
    {
      SimStruct *rts = final_M->childSfunctions[1];
      sfcnUpdate(rts,0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Update for S-Function (sfun_spid_contc): '<S137>/State-Space' */
    /* Level2 S-Function Block: '<S137>/State-Space' (sfun_spid_contc) */
    {
      SimStruct *rts = final_M->childSfunctions[2];
      sfcnUpdate(rts,0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(final_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(final_M)!=-1) &&
          !((rtmGetTFinal(final_M)-(((final_M->Timing.clockTick1+
               final_M->Timing.clockTickH1* 4294967296.0)) * 1.0E-5)) >
            (((final_M->Timing.clockTick1+final_M->Timing.clockTickH1*
               4294967296.0)) * 1.0E-5) * (DBL_EPSILON))) {
        rtmSetErrorStatus(final_M, "Simulation finished");
      }

      if (rtmGetStopRequested(final_M)) {
        rtmSetErrorStatus(final_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&final_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++final_M->Timing.clockTick0)) {
      ++final_M->Timing.clockTickH0;
    }

    final_M->Timing.t[0] = rtsiGetSolverStopTime(&final_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      final_M->Timing.clockTick1++;
      if (!final_M->Timing.clockTick1) {
        final_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void final_derivatives(void)
{
  XDot_final_T *_rtXdot;
  _rtXdot = ((XDot_final_T *) final_M->derivs);

  /* Derivatives for Integrator: '<S32>/Integrator' */
  _rtXdot->Integrator_CSTATE = final_B.A_j;

  /* Derivatives for S-Function (sfun_spid_contc): '<S135>/State-Space' */
  /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[0];
    real_T *sfcndX_fx = (real_T *) &((XDot_final_T *) final_M->derivs)
      ->StateSpace_CSTATE[0];
    ssSetdX(rts, sfcndX_fx);
    sfcnDerivatives(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Derivatives for Integrator: '<S22>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = final_B.A;

  /* Derivatives for S-Function (sfun_spid_contc): '<S136>/State-Space' */
  /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[1];
    real_T *sfcndX_fx = (real_T *) &((XDot_final_T *) final_M->derivs)
      ->StateSpace_CSTATE_g[0];
    ssSetdX(rts, sfcndX_fx);
    sfcnDerivatives(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += final_P.TransferFcn2_A *
    final_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += final_B.Gain6;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += final_P.TransferFcn1_A *
    final_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += final_B.Gain5;

  /* Derivatives for TransferFcn: '<S14>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += final_P.TransferFcn3_A *
    final_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += final_B.Gain15;

  /* Derivatives for TransferFcn: '<S15>/Transfer Fcn5' */
  _rtXdot->TransferFcn5_CSTATE = 0.0;
  _rtXdot->TransferFcn5_CSTATE += final_P.TransferFcn5_A *
    final_X.TransferFcn5_CSTATE;
  _rtXdot->TransferFcn5_CSTATE += final_B.Gain16;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE = 0.0;
  _rtXdot->TransferFcn4_CSTATE += final_P.TransferFcn4_A *
    final_X.TransferFcn4_CSTATE;
  _rtXdot->TransferFcn4_CSTATE += final_B.Gain18;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE_a = 0.0;
  _rtXdot->TransferFcn3_CSTATE_a += final_P.TransferFcn3_A_f *
    final_X.TransferFcn3_CSTATE_a;
  _rtXdot->TransferFcn3_CSTATE_a += final_B.Gain16_a;
}

/* Model initialize function */
void final_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)final_M, 0,
                sizeof(RT_MODEL_final_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&final_M->solverInfo, &final_M->Timing.simTimeStep);
    rtsiSetTPtr(&final_M->solverInfo, &rtmGetTPtr(final_M));
    rtsiSetStepSizePtr(&final_M->solverInfo, &final_M->Timing.stepSize0);
    rtsiSetdXPtr(&final_M->solverInfo, &final_M->derivs);
    rtsiSetContStatesPtr(&final_M->solverInfo, (real_T **) &final_M->contStates);
    rtsiSetNumContStatesPtr(&final_M->solverInfo, &final_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&final_M->solverInfo,
      &final_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&final_M->solverInfo,
      &final_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&final_M->solverInfo,
      &final_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&final_M->solverInfo, (&rtmGetErrorStatus(final_M)));
    rtsiSetRTModelPtr(&final_M->solverInfo, final_M);
  }

  rtsiSetSimTimeStep(&final_M->solverInfo, MAJOR_TIME_STEP);
  final_M->intgData.y = final_M->odeY;
  final_M->intgData.f[0] = final_M->odeF[0];
  final_M->intgData.f[1] = final_M->odeF[1];
  final_M->intgData.f[2] = final_M->odeF[2];
  final_M->contStates = ((X_final_T *) &final_X);
  rtsiSetSolverData(&final_M->solverInfo, (void *)&final_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&final_M->solverInfo, false);
  rtsiSetSolverName(&final_M->solverInfo,"ode3");
  final_M->solverInfoPtr = (&final_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = final_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "final_M points to
       static memory which is guaranteed to be non-NULL" */
    final_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    final_M->Timing.sampleTimes = (&final_M->Timing.sampleTimesArray[0]);
    final_M->Timing.offsetTimes = (&final_M->Timing.offsetTimesArray[0]);

    /* task periods */
    final_M->Timing.sampleTimes[0] = (0.0);
    final_M->Timing.sampleTimes[1] = (1.0E-5);

    /* task offsets */
    final_M->Timing.offsetTimes[0] = (0.0);
    final_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(final_M, &final_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = final_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    final_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(final_M, 0.4);
  final_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    final_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(final_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(final_M->rtwLogInfo, (NULL));
    rtliSetLogT(final_M->rtwLogInfo, "tout");
    rtliSetLogX(final_M->rtwLogInfo, "");
    rtliSetLogXFinal(final_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(final_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(final_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(final_M->rtwLogInfo, 0);
    rtliSetLogDecimation(final_M->rtwLogInfo, 1);
    rtliSetLogY(final_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(final_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(final_M->rtwLogInfo, (NULL));
  }

  final_M->solverInfoPtr = (&final_M->solverInfo);
  final_M->Timing.stepSize = (1.0E-5);
  rtsiSetFixedStepSize(&final_M->solverInfo, 1.0E-5);
  rtsiSetSolverMode(&final_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &final_B), 0,
                sizeof(B_final_T));

  /* states (continuous) */
  {
    (void) memset((void *)&final_X, 0,
                  sizeof(X_final_T));
  }

  /* states (dwork) */
  (void) memset((void *)&final_DW, 0,
                sizeof(DW_final_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &final_M->NonInlinedSFcns.sfcnInfo;
    final_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(final_M)));
    final_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &final_M->Sizes.numSampTimes);
    final_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr(final_M)[0]);
    final_M->NonInlinedSFcns.taskTimePtrs[1] = (&rtmGetTPtr(final_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,final_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(final_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(final_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(final_M));
    rtssSetStepSizePtr(sfcnInfo, &final_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(final_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &final_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &final_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &final_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &final_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &final_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &final_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &final_M->solverInfoPtr);
  }

  final_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&final_M->NonInlinedSFcns.childSFunctions[0], 0,
                  3*sizeof(SimStruct));
    final_M->childSfunctions = (&final_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    final_M->childSfunctions[0] = (&final_M->NonInlinedSFcns.childSFunctions[0]);
    final_M->childSfunctions[1] = (&final_M->NonInlinedSFcns.childSFunctions[1]);
    final_M->childSfunctions[2] = (&final_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: final/<S135>/State-Space (sfun_spid_contc) */
    {
      SimStruct *rts = final_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = final_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = final_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = final_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &final_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &final_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, final_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &final_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &final_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &final_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &final_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &final_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &final_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &final_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &final_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &final_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &final_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &final_B.DC;
          sfcnUPtrs[1] = &final_B.Efcem;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &final_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &final_B.DataTypeConversion_ef;
          sfcnUPtrs[1] = &final_B.DataTypeConversion_g;
          sfcnUPtrs[2] = &final_B.DataTypeConversion_jf;
          sfcnUPtrs[3] = &final_B.DataTypeConversion_m;
          sfcnUPtrs[4] = &final_B.gate_n;
          sfcnUPtrs[5] = &final_B.gate_do;
          sfcnUPtrs[6] = &final_B.gate_m;
          sfcnUPtrs[7] = &final_B.gate_jm;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &final_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &final_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &final_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &final_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) final_B.StateSpace_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 16);
          ssSetOutputPortSignal(rts, 1, ((real_T *) final_B.StateSpace_o2));
        }
      }

      /* states */
      ssSetContStates(rts, &final_X.StateSpace_CSTATE[0]);

      /* path info */
      ssSetModelName(rts, "State-Space");
      ssSetPath(rts, "final/powergui/EquivalentModel1/State-Space");
      ssSetRTModel(rts,final_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &final_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)final_P.StateSpace_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)final_P.StateSpace_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)final_P.StateSpace_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)final_P.StateSpace_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)final_P.StateSpace_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)final_P.StateSpace_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)final_P.StateSpace_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)final_P.StateSpace_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)final_P.StateSpace_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)final_P.StateSpace_P10_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &final_DW.StateSpace_RWORK[0]);
      ssSetIWork(rts, (int_T *) &final_DW.StateSpace_IWORK[0]);
      ssSetPWork(rts, (void **) &final_DW.StateSpace_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &final_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &final_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 4);

        /* MODE */
        ssSetDWorkWidthAsInt(rts, 0, 9);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &final_DW.StateSpace_MODE[0]);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &final_DW.StateSpace_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidthAsInt(rts, 2, 23);
        ssSetDWorkDataType(rts, 2,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &final_DW.StateSpace_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 3, 22);
        ssSetDWorkDataType(rts, 3,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWork(rts, 3, &final_DW.StateSpace_PWORK[0]);
      }

      ssSetModeVector(rts, (int_T *) &final_DW.StateSpace_MODE[0]);

      /* registration */
      sfun_spid_contc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: final/<S136>/State-Space (sfun_spid_contc) */
    {
      SimStruct *rts = final_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = final_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = final_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = final_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &final_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &final_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, final_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &final_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &final_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &final_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &final_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &final_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &final_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &final_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &final_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &final_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &final_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &final_B.DC_p;
          sfcnUPtrs[1] = &final_B.Efcem_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &final_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &final_B.DataTypeConversion;
          sfcnUPtrs[1] = &final_B.DataTypeConversion_j;
          sfcnUPtrs[2] = &final_B.DataTypeConversion_e;
          sfcnUPtrs[3] = &final_B.DataTypeConversion_h;
          sfcnUPtrs[4] = &final_B.gate;
          sfcnUPtrs[5] = &final_B.gate_j;
          sfcnUPtrs[6] = &final_B.gate_h;
          sfcnUPtrs[7] = &final_B.gate_d;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &final_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &final_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &final_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &final_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) final_B.StateSpace_o1_m));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 16);
          ssSetOutputPortSignal(rts, 1, ((real_T *) final_B.StateSpace_o2_p));
        }
      }

      /* states */
      ssSetContStates(rts, &final_X.StateSpace_CSTATE_g[0]);

      /* path info */
      ssSetModelName(rts, "State-Space");
      ssSetPath(rts, "final/powergui/EquivalentModel2/State-Space");
      ssSetRTModel(rts,final_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &final_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)final_P.StateSpace_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)final_P.StateSpace_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)final_P.StateSpace_P3_Size_o);
        ssSetSFcnParam(rts, 3, (mxArray*)final_P.StateSpace_P4_Size_g);
        ssSetSFcnParam(rts, 4, (mxArray*)final_P.StateSpace_P5_Size_c);
        ssSetSFcnParam(rts, 5, (mxArray*)final_P.StateSpace_P6_Size_h);
        ssSetSFcnParam(rts, 6, (mxArray*)final_P.StateSpace_P7_Size_h);
        ssSetSFcnParam(rts, 7, (mxArray*)final_P.StateSpace_P8_Size_d);
        ssSetSFcnParam(rts, 8, (mxArray*)final_P.StateSpace_P9_Size_k);
        ssSetSFcnParam(rts, 9, (mxArray*)final_P.StateSpace_P10_Size_p);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &final_DW.StateSpace_RWORK_p[0]);
      ssSetIWork(rts, (int_T *) &final_DW.StateSpace_IWORK_d[0]);
      ssSetPWork(rts, (void **) &final_DW.StateSpace_PWORK_e[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &final_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &final_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 4);

        /* MODE */
        ssSetDWorkWidthAsInt(rts, 0, 9);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &final_DW.StateSpace_MODE_h[0]);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &final_DW.StateSpace_RWORK_p[0]);

        /* IWORK */
        ssSetDWorkWidthAsInt(rts, 2, 23);
        ssSetDWorkDataType(rts, 2,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &final_DW.StateSpace_IWORK_d[0]);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 3, 22);
        ssSetDWorkDataType(rts, 3,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWork(rts, 3, &final_DW.StateSpace_PWORK_e[0]);
      }

      ssSetModeVector(rts, (int_T *) &final_DW.StateSpace_MODE_h[0]);

      /* registration */
      sfun_spid_contc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: final/<S137>/State-Space (sfun_spid_contc) */
    {
      SimStruct *rts = final_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = final_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = final_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = final_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &final_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &final_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, final_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &final_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &final_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &final_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &final_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &final_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &final_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &final_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &final_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &final_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &final_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &final_B.DC_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &final_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &final_B.DataTypeConversion_l;
          sfcnUPtrs[1] = &final_B.DataTypeConversion_jl;
          sfcnUPtrs[2] = &final_B.DataTypeConversion_jc;
          sfcnUPtrs[3] = &final_B.DataTypeConversion_p;
          sfcnUPtrs[4] = &final_B.gate_a;
          sfcnUPtrs[5] = &final_B.gate_jv;
          sfcnUPtrs[6] = &final_B.gate_hx;
          sfcnUPtrs[7] = &final_B.gate_ah;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &final_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &final_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);
        _ssSetPortInfo2ForOutputUnits(rts,
          &final_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &final_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &final_B.StateSpace_o1_p));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 16);
          ssSetOutputPortSignal(rts, 1, ((real_T *) final_B.StateSpace_o2_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "State-Space");
      ssSetPath(rts, "final/powergui/EquivalentModel3/State-Space");
      ssSetRTModel(rts,final_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &final_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)final_P.StateSpace_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)final_P.StateSpace_P2_Size_p);
        ssSetSFcnParam(rts, 2, (mxArray*)final_P.StateSpace_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)final_P.StateSpace_P4_Size_i);
        ssSetSFcnParam(rts, 4, (mxArray*)final_P.StateSpace_P5_Size_i);
        ssSetSFcnParam(rts, 5, (mxArray*)final_P.StateSpace_P6_Size_p);
        ssSetSFcnParam(rts, 6, (mxArray*)final_P.StateSpace_P7_Size_b);
        ssSetSFcnParam(rts, 7, (mxArray*)final_P.StateSpace_P8_Size_j);
        ssSetSFcnParam(rts, 8, (mxArray*)final_P.StateSpace_P9_Size_c);
        ssSetSFcnParam(rts, 9, (mxArray*)final_P.StateSpace_P10_Size_e);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &final_DW.StateSpace_RWORK_h[0]);
      ssSetIWork(rts, (int_T *) &final_DW.StateSpace_IWORK_c[0]);
      ssSetPWork(rts, (void **) &final_DW.StateSpace_PWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &final_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &final_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 4);

        /* MODE */
        ssSetDWorkWidthAsInt(rts, 0, 9);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &final_DW.StateSpace_MODE_i[0]);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &final_DW.StateSpace_RWORK_h[0]);

        /* IWORK */
        ssSetDWorkWidthAsInt(rts, 2, 23);
        ssSetDWorkDataType(rts, 2,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &final_DW.StateSpace_IWORK_c[0]);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 3, 22);
        ssSetDWorkDataType(rts, 3,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWork(rts, 3, &final_DW.StateSpace_PWORK_m[0]);
      }

      ssSetModeVector(rts, (int_T *) &final_DW.StateSpace_MODE_i[0]);

      /* registration */
      sfun_spid_contc(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(final_M->rtwLogInfo, 0.0, rtmGetTFinal
    (final_M), final_M->Timing.stepSize0, (&rtmGetErrorStatus(final_M)));

  /* Start for S-Function (sfun_spid_contc): '<S135>/State-Space' */
  /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_spid_contc): '<S136>/State-Space' */
  /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S30>/DC' */
  final_B.DC_g = final_P.UaN;

  /* Start for S-Function (sfun_spid_contc): '<S137>/State-Space' */
  /* Level2 S-Function Block: '<S137>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S32>/Integrator' */
  final_X.Integrator_CSTATE = final_P.Integrator_IC;

  /* InitializeConditions for S-Function (sfun_spid_contc): '<S135>/State-Space' */
  /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Integrator: '<S22>/Integrator' */
  final_X.Integrator_CSTATE_k = final_P.Integrator_IC_d;

  /* InitializeConditions for S-Function (sfun_spid_contc): '<S136>/State-Space' */
  /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_spid_contc): '<S137>/State-Space' */
  /* Level2 S-Function Block: '<S137>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  final_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  final_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S14>/Transfer Fcn3' */
  final_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S15>/Transfer Fcn5' */
  final_X.TransferFcn5_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  final_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  final_X.TransferFcn3_CSTATE_a = 0.0;
}

/* Model terminate function */
void final_terminate(void)
{
  /* Terminate for S-Function (sfun_spid_contc): '<S135>/State-Space' */
  /* Level2 S-Function Block: '<S135>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_spid_contc): '<S136>/State-Space' */
  /* Level2 S-Function Block: '<S136>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_spid_contc): '<S137>/State-Space' */
  /* Level2 S-Function Block: '<S137>/State-Space' (sfun_spid_contc) */
  {
    SimStruct *rts = final_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}
