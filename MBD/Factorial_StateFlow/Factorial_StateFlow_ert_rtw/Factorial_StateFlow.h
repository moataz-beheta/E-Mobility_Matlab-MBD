/*
 * File: Factorial_StateFlow.h
 *
 * Code generated for Simulink model 'Factorial_StateFlow'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Nov  8 07:22:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Factorial_StateFlow_h_
#define RTW_HEADER_Factorial_StateFlow_h_
#include <stddef.h>
#ifndef Factorial_StateFlow_COMMON_INCLUDES_
# define Factorial_StateFlow_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Factorial_StateFlow_COMMON_INCLUDES_ */

#include "Factorial_StateFlow_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T In1;                        /* '<Root>/In1' */
} ExtU_Factorial_StateFlow_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Result;                     /* '<Root>/Result' */
} ExtY_Factorial_StateFlow_T;

/* Real-time Model Data Structure */
struct tag_RTM_Factorial_StateFlow_T {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_Factorial_StateFlow_T Factorial_StateFlow_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Factorial_StateFlow_T Factorial_StateFlow_Y;

/* Model entry point functions */
extern void Factorial_StateFlow_initialize(void);
extern void Factorial_StateFlow_step(void);
extern void Factorial_StateFlow_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Factorial_StateFlow_T *const Factorial_StateFlow_M;

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
 * '<Root>' : 'Factorial_StateFlow'
 * '<S1>'   : 'Factorial_StateFlow/Chart'
 */
#endif                                 /* RTW_HEADER_Factorial_StateFlow_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
