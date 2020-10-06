/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID.h
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

#ifndef RTW_HEADER_PID_h_
#define RTW_HEADER_PID_h_
#include <math.h>
#ifndef PID_COMMON_INCLUDES_
# define PID_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PID_COMMON_INCLUDES_ */

#include "PID_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
  real_T Filter_DSTATE;                /* '<S28>/Filter' */
} DW_PID_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T u;                            /* '<Root>/u' */
} ExtU_PID_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExtY_PID_T;

/* Real-time Model Data Structure */
struct tag_RTM_PID_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_PID_T PID_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PID_T PID_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PID_T PID_Y;

/* Model entry point functions */
extern void PID_initialize(void);
extern void PID_step(void);
extern void PID_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_T *const PID_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Model_Hotend/PID Controller')    - opens subsystem Model_Hotend/PID Controller
 * hilite_system('Model_Hotend/PID Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Model_Hotend'
 * '<S1>'   : 'Model_Hotend/PID Controller'
 * '<S2>'   : 'Model_Hotend/PID Controller/Anti-windup'
 * '<S3>'   : 'Model_Hotend/PID Controller/D Gain'
 * '<S4>'   : 'Model_Hotend/PID Controller/Filter'
 * '<S5>'   : 'Model_Hotend/PID Controller/Filter ICs'
 * '<S6>'   : 'Model_Hotend/PID Controller/I Gain'
 * '<S7>'   : 'Model_Hotend/PID Controller/Ideal P Gain'
 * '<S8>'   : 'Model_Hotend/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'Model_Hotend/PID Controller/Integrator'
 * '<S10>'  : 'Model_Hotend/PID Controller/Integrator ICs'
 * '<S11>'  : 'Model_Hotend/PID Controller/N Copy'
 * '<S12>'  : 'Model_Hotend/PID Controller/N Gain'
 * '<S13>'  : 'Model_Hotend/PID Controller/P Copy'
 * '<S14>'  : 'Model_Hotend/PID Controller/Parallel P Gain'
 * '<S15>'  : 'Model_Hotend/PID Controller/Reset Signal'
 * '<S16>'  : 'Model_Hotend/PID Controller/Saturation'
 * '<S17>'  : 'Model_Hotend/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'Model_Hotend/PID Controller/Sum'
 * '<S19>'  : 'Model_Hotend/PID Controller/Sum Fdbk'
 * '<S20>'  : 'Model_Hotend/PID Controller/Tracking Mode'
 * '<S21>'  : 'Model_Hotend/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'Model_Hotend/PID Controller/Tsamp - Integral'
 * '<S23>'  : 'Model_Hotend/PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'Model_Hotend/PID Controller/postSat Signal'
 * '<S25>'  : 'Model_Hotend/PID Controller/preSat Signal'
 * '<S26>'  : 'Model_Hotend/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S27>'  : 'Model_Hotend/PID Controller/D Gain/Internal Parameters'
 * '<S28>'  : 'Model_Hotend/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S29>'  : 'Model_Hotend/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'Model_Hotend/PID Controller/I Gain/Internal Parameters'
 * '<S31>'  : 'Model_Hotend/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S32>'  : 'Model_Hotend/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'Model_Hotend/PID Controller/Integrator/Discrete'
 * '<S34>'  : 'Model_Hotend/PID Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'Model_Hotend/PID Controller/N Copy/Disabled'
 * '<S36>'  : 'Model_Hotend/PID Controller/N Gain/Internal Parameters'
 * '<S37>'  : 'Model_Hotend/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S38>'  : 'Model_Hotend/PID Controller/Parallel P Gain/Passthrough'
 * '<S39>'  : 'Model_Hotend/PID Controller/Reset Signal/Disabled'
 * '<S40>'  : 'Model_Hotend/PID Controller/Saturation/Enabled'
 * '<S41>'  : 'Model_Hotend/PID Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'Model_Hotend/PID Controller/Sum/Sum_PID'
 * '<S43>'  : 'Model_Hotend/PID Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'Model_Hotend/PID Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'Model_Hotend/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'Model_Hotend/PID Controller/Tsamp - Integral/Passthrough'
 * '<S47>'  : 'Model_Hotend/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'Model_Hotend/PID Controller/postSat Signal/Forward_Path'
 * '<S49>'  : 'Model_Hotend/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_PID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
