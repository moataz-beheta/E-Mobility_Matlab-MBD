/*
 * File: Factorial_StateFlow.c
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

#include "Factorial_StateFlow.h"
#include "Factorial_StateFlow_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_Factorial_StateFlow_T Factorial_StateFlow_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Factorial_StateFlow_T Factorial_StateFlow_Y;

/* Real-time model */
RT_MODEL_Factorial_StateFlow_T Factorial_StateFlow_M_;
RT_MODEL_Factorial_StateFlow_T *const Factorial_StateFlow_M =
  &Factorial_StateFlow_M_;

/* Model step function */
void Factorial_StateFlow_step(void)
{
  uint16_T Num;
  uint32_T tmp;
  int32_T tmp_0;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/In1'
   */
  /*  Factorial_While */
  Num = Factorial_StateFlow_U.In1;
  Factorial_StateFlow_Y.Result = 1U;
  while (Num > 0) {
    tmp = (uint32_T)Factorial_StateFlow_Y.Result * Num;
    if (tmp > 2147483647U) {
      tmp = 2147483647U;
    }

    tmp_0 = (int32_T)tmp;
    if ((int32_T)tmp > 65535) {
      tmp_0 = 65535;
    }

    Factorial_StateFlow_Y.Result = (uint16_T)tmp_0;
    Num--;
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Factorial_StateFlow_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Factorial_StateFlow_M, (NULL));

  /* external inputs */
  Factorial_StateFlow_U.In1 = 0U;

  /* external outputs */
  Factorial_StateFlow_Y.Result = 0U;
}

/* Model terminate function */
void Factorial_StateFlow_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
