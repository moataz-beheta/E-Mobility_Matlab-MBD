/*
 * File: Calculator.h
 *
 * Code generated for Simulink model 'Calculator'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Nov  1 15:14:01 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Calculator_h_
#define RTW_HEADER_Calculator_h_
#include <string.h>
#include <stddef.h>
#ifndef Calculator_COMMON_INCLUDES_
# define Calculator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Calculator_COMMON_INCLUDES_ */

#include "Calculator_types.h"

/* Child system includes */
#include "My_Calculator.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int32_T Merge;                       /* '<S1>/Merge' */
} B_Calculator_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Operation;                    /* '<Root>/Operation ' */
  int32_T INPUT1;                      /* '<Root>/INPUT 1 ' */
  int32_T INPUT2;                      /* '<Root>/INPUT 2' */
} ExtU_Calculator_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int32_T Result;                      /* '<Root>/Result ' */
} ExtY_Calculator_T;

/* Real-time Model Data Structure */
struct tag_RTM_Calculator_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Calculator_T Calculator_B;

/* External inputs (root inport signals with default storage) */
extern ExtU_Calculator_T Calculator_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Calculator_T Calculator_Y;

/* Model entry point functions */
extern void Calculator_initialize(void);
extern void Calculator_step(void);
extern void Calculator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Calculator_T *const Calculator_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 */

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
 * '<Root>' : 'Calculator'
 * '<S1>'   : 'Calculator/My_Calculator'
 * '<S2>'   : 'Calculator/My_Calculator/MATLAB Function'
 * '<S3>'   : 'Calculator/My_Calculator/Switch Case Action Subsystem'
 * '<S4>'   : 'Calculator/My_Calculator/Switch Case Action Subsystem1'
 * '<S5>'   : 'Calculator/My_Calculator/Switch Case Action Subsystem2'
 * '<S6>'   : 'Calculator/My_Calculator/Switch Case Action Subsystem3'
 * '<S7>'   : 'Calculator/My_Calculator/Switch Case Action Subsystem3/If Action Subsystem'
 * '<S8>'   : 'Calculator/My_Calculator/Switch Case Action Subsystem3/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_Calculator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
