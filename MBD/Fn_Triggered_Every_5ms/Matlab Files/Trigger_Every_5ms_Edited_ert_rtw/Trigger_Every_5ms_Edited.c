/*
 * File: Trigger_Every_5ms_Edited.c
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

#include "Trigger_Every_5ms_Edited.h"
#include "Trigger_Every_5ms_Edited_private.h"

/* Real-time model */
RT_MODEL_Trigger_Every_5ms_Ed_T Trigger_Every_5ms_Edited_M_;
RT_MODEL_Trigger_Every_5ms_Ed_T *const Trigger_Every_5ms_Edited_M =
  &Trigger_Every_5ms_Edited_M_;

/* Output and update for function-call system: '<Root>/Triggered Subsystem1' */
void Trigger_Eve_TriggeredSubsystem1(void)
{
  boolean_T Read_Switch;

  /* Chart: '<S1>/Chart' */
  /*  SwitchState  */
  Read_Switch = ReadSwitch(SWITCH_1);

  /*  LEDState  */
  if (Read_Switch) {
    Led_TurnOn(LED_1);
  } else {
    Led_TurnOff(LED_1);
  }

  /* End of Chart: '<S1>/Chart' */
}

/* Model step function */
void In1(void)
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_In1_at_outport_1' incorporates:
   *  SubSystem: '<Root>/Triggered Subsystem1'
   */
  Trigger_Eve_TriggeredSubsystem1();

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_In1_at_outport_1' */
}

/* Model initialize function */
void Trigger_Every_5ms_Edited_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Trigger_Every_5ms_Edited_M, (NULL));
}

/* Model terminate function */
void Trigger_Every_5ms_Edited_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
