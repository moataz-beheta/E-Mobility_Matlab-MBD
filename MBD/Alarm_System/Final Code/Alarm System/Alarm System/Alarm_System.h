/*
 * File: Alarm_System.h
 *
 * Code generated for Simulink model 'Alarm_System'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sat Dec  3 16:30:24 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Alarm_System_h_
#define RTW_HEADER_Alarm_System_h_
#include <stddef.h>
#include <string.h>
#ifndef Alarm_System_COMMON_INCLUDES_
# define Alarm_System_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* Alarm_System_COMMON_INCLUDES_ */

#include "Alarm_System_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "LED.h"
#include "Switch.h"
#include "Buzzer.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_interface.h"
#include "Dio_private.h"
#include "ADC_interface.h"
#include "ADC_Configuration.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Temperature;                  /* '<Root>/ADC Value & LEDs' */
  real_T Switch;
  uint8_T is_active_c3_Alarm_System;   /* '<Root>/ADC Value & LEDs' */
} DW_Alarm_System_T;

/* Real-time Model Data Structure */
struct tag_RTM_Alarm_System_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Alarm_System_T Alarm_System_DW;

/* Model entry point functions */
extern void Alarm_System_initialize(void);
extern void Alarm_System_step(void);
extern void Alarm_System_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Alarm_System_T *const Alarm_System_M;

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
 * '<Root>' : 'Alarm_System'
 * '<S1>'   : 'Alarm_System/ADC Value & LEDs'
 * '<S2>'   : 'Alarm_System/Swtich State'
 */
#endif                                 /* RTW_HEADER_Alarm_System_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
