/*
 * File: Calculator_graphical_function.c
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

#include "Calculator_graphical_function.h"
#include "Calculator_graphical_function_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_Calculator_graphical_fun_T Calculator_graphical_function_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Calculator_graphical_fun_T Calculator_graphical_function_Y;

/* Real-time model */
RT_MODEL_Calculator_graphical_T Calculator_graphical_functio_M_;
RT_MODEL_Calculator_graphical_T *const Calculator_graphical_functio_M =
  &Calculator_graphical_functio_M_;

/* Forward declaration for local functions */
static void Calculator_graphical_functi_Add(real_T In1, real_T In2);
static void Calculator_graphical_functi_Sub(real_T In1, real_T In2);
static void Calculator_graphical_funct_Mult(real_T In1, real_T In2);
static void Calculator_graphical_functi_Div(real_T In1, real_T In2);

/* Function for Chart: '<Root>/Chart' */
static void Calculator_graphical_functi_Add(real_T In1, real_T In2)
{
  real_T tmp;
  tmp = In1 + In2;
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      /* Outport: '<Root>/Add_Result' */
      Calculator_graphical_function_Y.Add_Result = (int16_T)tmp;
    } else {
      /* Outport: '<Root>/Add_Result' */
      Calculator_graphical_function_Y.Add_Result = MIN_int16_T;
    }
  } else {
    /* Outport: '<Root>/Add_Result' */
    Calculator_graphical_function_Y.Add_Result = MAX_int16_T;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Calculator_graphical_functi_Sub(real_T In1, real_T In2)
{
  real_T tmp;
  tmp = In1 - In2;
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      /* Outport: '<Root>/Sub_Result' */
      Calculator_graphical_function_Y.Sub_Result = (int16_T)tmp;
    } else {
      /* Outport: '<Root>/Sub_Result' */
      Calculator_graphical_function_Y.Sub_Result = MIN_int16_T;
    }
  } else {
    /* Outport: '<Root>/Sub_Result' */
    Calculator_graphical_function_Y.Sub_Result = MAX_int16_T;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Calculator_graphical_funct_Mult(real_T In1, real_T In2)
{
  real_T tmp;
  tmp = In1 * In2;
  if (tmp < 32768.0) {
    if (tmp >= -32768.0) {
      /* Outport: '<Root>/Mult_Result' */
      Calculator_graphical_function_Y.Mult_Result = (int16_T)tmp;
    } else {
      /* Outport: '<Root>/Mult_Result' */
      Calculator_graphical_function_Y.Mult_Result = MIN_int16_T;
    }
  } else {
    /* Outport: '<Root>/Mult_Result' */
    Calculator_graphical_function_Y.Mult_Result = MAX_int16_T;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Calculator_graphical_functi_Div(real_T In1, real_T In2)
{
  /*  Division  */
  if (In2 != 0.0) {
    /* Outport: '<Root>/Div_Result' */
    Calculator_graphical_function_Y.Div_Result = In1 / In2;
  } else {
    /* Outport: '<Root>/Error_Flag' */
    Calculator_graphical_function_Y.Error_Flag = 10;
  }
}

/* Model step function */
void Calculator_graphical_function_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  Calculator_graphical_functi_Add((real_T)Calculator_graphical_function_U.In1,
    (real_T)Calculator_graphical_function_U.In2);
  Calculator_graphical_functi_Sub((real_T)Calculator_graphical_function_U.In1,
    (real_T)Calculator_graphical_function_U.In2);
  Calculator_graphical_funct_Mult((real_T)Calculator_graphical_function_U.In1,
    (real_T)Calculator_graphical_function_U.In2);
  Calculator_graphical_functi_Div((real_T)Calculator_graphical_function_U.In1,
    (real_T)Calculator_graphical_function_U.In2);
}

/* Model initialize function */
void Calculator_graphical_function_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Calculator_graphical_functio_M, (NULL));

  /* external inputs */
  (void)memset((void *)&Calculator_graphical_function_U, 0, sizeof
               (ExtU_Calculator_graphical_fun_T));

  /* external outputs */
  (void) memset((void *)&Calculator_graphical_function_Y, 0,
                sizeof(ExtY_Calculator_graphical_fun_T));

  /* SystemInitialize for Outport: '<Root>/Add_Result' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Calculator_graphical_function_Y.Add_Result = 0;

  /* SystemInitialize for Outport: '<Root>/Sub_Result' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Calculator_graphical_function_Y.Sub_Result = 0;

  /* SystemInitialize for Outport: '<Root>/Mult_Result' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Calculator_graphical_function_Y.Mult_Result = 0;

  /* SystemInitialize for Outport: '<Root>/Div_Result' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Calculator_graphical_function_Y.Div_Result = 0.0;

  /* SystemInitialize for Outport: '<Root>/Error_Flag' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Calculator_graphical_function_Y.Error_Flag = 0;
}

/* Model terminate function */
void Calculator_graphical_function_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
