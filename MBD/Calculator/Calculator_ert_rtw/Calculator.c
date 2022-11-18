/*
 * File: Calculator.c
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

#include "Calculator.h"
#include "Calculator_private.h"

/* Block signals (default storage) */
B_Calculator_T Calculator_B;

/* External inputs (root inport signals with default storage) */
ExtU_Calculator_T Calculator_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Calculator_T Calculator_Y;

/* Real-time model */
RT_MODEL_Calculator_T Calculator_M_;
RT_MODEL_Calculator_T *const Calculator_M = &Calculator_M_;
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

/* Model step function */
void Calculator_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/My_Calculator' */

  /* Inport: '<Root>/Operation ' incorporates:
   *  Inport: '<Root>/INPUT 1 '
   *  Inport: '<Root>/INPUT 2'
   */
  Calculator_My_Calculator(Calculator_U.Operation, Calculator_U.INPUT1,
    Calculator_U.INPUT2, &Calculator_B.Merge);

  /* End of Outputs for SubSystem: '<Root>/My_Calculator' */

  /* Outport: '<Root>/Result ' */
  Calculator_Y.Result = Calculator_B.Merge;
}

/* Model initialize function */
void Calculator_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Calculator_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Calculator_B), 0,
                sizeof(B_Calculator_T));

  /* external inputs */
  (void)memset((void *)&Calculator_U, 0, sizeof(ExtU_Calculator_T));

  /* external outputs */
  Calculator_Y.Result = 0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/My_Calculator' */
  Calculator_My_Calculator_Init(&Calculator_B.Merge);

  /* End of SystemInitialize for SubSystem: '<Root>/My_Calculator' */
}

/* Model terminate function */
void Calculator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
