/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID.c
 *
 * Code generated for Simulink model 'PID'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct  1 16:42:31 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (8-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID.h"
#include "PID_private.h"

/* Block states (default storage) */
DW_PID_T PID_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PID_T PID_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PID_T PID_Y;

/* Real-time model */
RT_MODEL_PID_T PID_M_;
RT_MODEL_PID_T *const PID_M = &PID_M_;

/* Model step function */
void PID_step(void)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_ProportionalGain;
  real_T rtb_IntegralGain;
  real_T rtb_DeadZone;
  real_T tmp;
  real_T tmp_0;

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S28>/Filter'
   *  Gain: '<S27>/Derivative Gain'
   *  Inport: '<Root>/u'
   *  Sum: '<S28>/SumD'
   */
  rtb_FilterCoefficient = (0.0 * PID_U.u - PID_DW.Filter_DSTATE) * 100.0;

  /* Gain: '<S31>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Inport: '<Root>/u'
   *  Sum: '<S42>/Sum'
   */
  rtb_ProportionalGain = ((PID_U.u + PID_DW.Integrator_DSTATE) +
    rtb_FilterCoefficient) * 14.8305;

  /* DeadZone: '<S26>/DeadZone' */
  if (rtb_ProportionalGain > 40.0) {
    rtb_DeadZone = rtb_ProportionalGain - 40.0;
  } else if (rtb_ProportionalGain >= 0.0) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone = rtb_ProportionalGain;
  }

  /* End of DeadZone: '<S26>/DeadZone' */

  /* Gain: '<S30>/Integral Gain' incorporates:
   *  Inport: '<Root>/u'
   */
  rtb_IntegralGain = 0.36645 * PID_U.u;

  /* Signum: '<S26>/SignPreSat' */
  if (rtb_DeadZone < 0.0) {
    /* DataTypeConversion: '<S26>/DataTypeConv1' */
    tmp = -1.0;
  } else if (rtb_DeadZone > 0.0) {
    /* DataTypeConversion: '<S26>/DataTypeConv1' */
    tmp = 1.0;
  } else if (rtb_DeadZone == 0.0) {
    /* DataTypeConversion: '<S26>/DataTypeConv1' */
    tmp = 0.0;
  } else {
    /* DataTypeConversion: '<S26>/DataTypeConv1' */
    tmp = (rtNaN);
  }

  /* End of Signum: '<S26>/SignPreSat' */

  /* DataTypeConversion: '<S26>/DataTypeConv1' */
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  /* Signum: '<S26>/SignPreIntegrator' */
  if (rtb_IntegralGain < 0.0) {
    /* DataTypeConversion: '<S26>/DataTypeConv2' */
    tmp_0 = -1.0;
  } else if (rtb_IntegralGain > 0.0) {
    /* DataTypeConversion: '<S26>/DataTypeConv2' */
    tmp_0 = 1.0;
  } else if (rtb_IntegralGain == 0.0) {
    /* DataTypeConversion: '<S26>/DataTypeConv2' */
    tmp_0 = 0.0;
  } else {
    /* DataTypeConversion: '<S26>/DataTypeConv2' */
    tmp_0 = (rtNaN);
  }

  /* End of Signum: '<S26>/SignPreIntegrator' */

  /* DataTypeConversion: '<S26>/DataTypeConv2' */
  if (rtIsNaN(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 256.0);
  }

  /* Saturate: '<S40>/Saturation' */
  if (rtb_ProportionalGain > 40.0) {
    /* Outport: '<Root>/y' */
    PID_Y.y = 40.0;
  } else if (rtb_ProportionalGain < 0.0) {
    /* Outport: '<Root>/y' */
    PID_Y.y = 0.0;
  } else {
    /* Outport: '<Root>/y' */
    PID_Y.y = rtb_ProportionalGain;
  }

  /* End of Saturate: '<S40>/Saturation' */

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Constant1'
   *  DataTypeConversion: '<S26>/DataTypeConv1'
   *  DataTypeConversion: '<S26>/DataTypeConv2'
   *  Gain: '<S26>/ZeroGain'
   *  Logic: '<S26>/AND3'
   *  RelationalOperator: '<S26>/Equal1'
   *  RelationalOperator: '<S26>/NotEqual'
   */
  if ((0.0 * rtb_ProportionalGain != rtb_DeadZone) && ((tmp < 0.0 ? (int16_T)
        (int8_T)-(int8_T)(uint8_T)-tmp : (int16_T)(int8_T)(uint8_T)tmp) ==
       (tmp_0 < 0.0 ? (int16_T)(int8_T)-(int8_T)(uint8_T)-tmp_0 : (int16_T)
        (int8_T)(uint8_T)tmp_0))) {
    rtb_IntegralGain = 0.0;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Update for DiscreteIntegrator: '<S33>/Integrator' */
  PID_DW.Integrator_DSTATE += rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S28>/Filter' */
  PID_DW.Filter_DSTATE += rtb_FilterCoefficient;
}

/* Model initialize function */
void PID_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void PID_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
