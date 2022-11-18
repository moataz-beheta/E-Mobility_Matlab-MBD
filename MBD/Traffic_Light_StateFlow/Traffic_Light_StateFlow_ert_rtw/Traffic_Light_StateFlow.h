/*
 * File: Traffic_Light_StateFlow.h
 *
 * Code generated for Simulink model 'Traffic_Light_StateFlow'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Tue Nov  8 15:54:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Traffic_Light_StateFlow_h_
#define RTW_HEADER_Traffic_Light_StateFlow_h_
#include <stddef.h>
#include <string.h>
#ifndef Traffic_Light_StateFlow_COMMON_INCLUDES_
# define Traffic_Light_StateFlow_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Traffic_Light_StateFlow_COMMON_INCLUDES_ */

#include "Traffic_Light_StateFlow_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_Traffic_Light_Stat;/* '<Root>/Chart' */
  uint8_T is_Traffic_Light;            /* '<Root>/Chart' */
  uint8_T Counter;                     /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Traffic_Light_StateFlow_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T In1;                       /* '<Root>/In1' */
} ExtU_Traffic_Light_StateFlow_T;

/* Real-time Model Data Structure */
struct tag_RTM_Traffic_Light_StateFl_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Traffic_Light_StateFlow_T Traffic_Light_StateFlow_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Traffic_Light_StateFlow_T Traffic_Light_StateFlow_U;

/* Model entry point functions */
extern void Traffic_Light_StateFlow_initialize(void);
extern void Traffic_Light_StateFlow_step(void);
extern void Traffic_Light_StateFlow_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Traffic_Light_StateF_T *const Traffic_Light_StateFlow_M;

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
 * '<Root>' : 'Traffic_Light_StateFlow'
 * '<S1>'   : 'Traffic_Light_StateFlow/Chart'
 */
#endif                                 /* RTW_HEADER_Traffic_Light_StateFlow_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
