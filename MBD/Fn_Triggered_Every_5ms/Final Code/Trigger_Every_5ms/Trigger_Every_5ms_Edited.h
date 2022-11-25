/*
 * File: Trigger_Every_5ms_Edited.h
 *
 * Code generated for Simulink model 'Trigger_Every_5ms_Edited'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Fri Nov 25 19:50:13 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Trigger_Every_5ms_Edited_h_
#define RTW_HEADER_Trigger_Every_5ms_Edited_h_
#include <stddef.h>
#ifndef Trigger_Every_5ms_Edited_COMMON_INCLUDES_
# define Trigger_Every_5ms_Edited_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Trigger_Every_5ms_Edited_COMMON_INCLUDES_ */

#include "Trigger_Every_5ms_Edited_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_interface.h"
#include "Dio_private.h"
#include "LED.h"
#include "Switch.h"

/* Real-time Model Data Structure */
struct tag_RTM_Trigger_Every_5ms_Edi_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void Trigger_Every_5ms_Edited_initialize(void);
extern void Trigger_Every_5ms_Edited_terminate(void);

/* Exported entry point function */
extern void In1(void);

/* Real-time Model object */
extern RT_MODEL_Trigger_Every_5ms_Ed_T *const Trigger_Every_5ms_Edited_M;

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
 * '<Root>' : 'Trigger_Every_5ms_Edited'
 * '<S1>'   : 'Trigger_Every_5ms_Edited/Triggered Subsystem1'
 * '<S2>'   : 'Trigger_Every_5ms_Edited/Triggered Subsystem1/Chart'
 * '<S3>'   : 'Trigger_Every_5ms_Edited/Triggered Subsystem1/Chart1'
 */
#endif                                 /* RTW_HEADER_Trigger_Every_5ms_Edited_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
