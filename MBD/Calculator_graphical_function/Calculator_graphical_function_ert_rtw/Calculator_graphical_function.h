/*
 * File: Calculator_graphical_function.h
 *
 * Code generated for Simulink model 'Calculator_graphical_function'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Nov  7 19:41:29 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Calculator_graphical_function_h_
#define RTW_HEADER_Calculator_graphical_function_h_
#include <string.h>
#include <stddef.h>
#ifndef Calculator_graphical_function_COMMON_INCLUDES_
# define Calculator_graphical_function_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Calculator_graphical_function_COMMON_INCLUDES_ */

#include "Calculator_graphical_function_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  int16_T In1;                         /* '<Root>/In1' */
  int16_T In2;                         /* '<Root>/In2' */
} ExtU_Calculator_graphical_fun_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int16_T Add_Result;                  /* '<Root>/Add_Result' */
  int16_T Sub_Result;                  /* '<Root>/Sub_Result' */
  int16_T Mult_Result;                 /* '<Root>/Mult_Result' */
  real_T Div_Result;                   /* '<Root>/Div_Result' */
  int16_T Error_Flag;                  /* '<Root>/Error_Flag' */
} ExtY_Calculator_graphical_fun_T;

/* Real-time Model Data Structure */
struct tag_RTM_Calculator_graphical__T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_Calculator_graphical_fun_T Calculator_graphical_function_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Calculator_graphical_fun_T Calculator_graphical_function_Y;

/* Model entry point functions */
extern void Calculator_graphical_function_initialize(void);
extern void Calculator_graphical_function_step(void);
extern void Calculator_graphical_function_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Calculator_graphical_T *const Calculator_graphical_functio_M;

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
 * '<Root>' : 'Calculator_graphical_function'
 * '<S1>'   : 'Calculator_graphical_function/Chart'
 */
#endif                                 /* RTW_HEADER_Calculator_graphical_function_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
