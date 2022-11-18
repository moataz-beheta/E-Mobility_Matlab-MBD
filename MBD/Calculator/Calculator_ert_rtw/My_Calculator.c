/*
 * File: My_Calculator.c
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

#include "My_Calculator.h"

/* Include model header file for global data */
#include "Calculator.h"
#include "Calculator_private.h"

/* System initialize for atomic system: '<Root>/My_Calculator' */
void Calculator_My_Calculator_Init(int32_T *rty_Out1)
{
  /* SystemInitialize for Merge: '<S1>/Merge' */
  *rty_Out1 = 0;
}

/* Output and update for atomic system: '<Root>/My_Calculator' */
void Calculator_My_Calculator(real_T rtu_In1, int32_T rtu_In2, int32_T rtu_In3,
  int32_T *rty_Out1)
{
  int32_T rtb_y;
  int32_T tmp;

  /* MATLAB Function: '<S1>/MATLAB Function' */
  rtb_y = 4;
  if (43.0 == rtu_In1) {
    tmp = 0;
  } else if (45.0 == rtu_In1) {
    tmp = 1;
  } else if (42.0 == rtu_In1) {
    tmp = 2;
  } else if (47.0 == rtu_In1) {
    tmp = 3;
  } else {
    tmp = -1;
  }

  switch (tmp) {
   case 0:
    rtb_y = 0;
    break;

   case 1:
    rtb_y = 1;
    break;

   case 2:
    rtb_y = 2;
    break;

   case 3:
    rtb_y = 3;
    break;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* SwitchCase: '<S1>/Switch Case' */
  switch ((int32_T)fmod(rtb_y, 4.294967296E+9)) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sum: '<S3>/Add' */
    *rty_Out1 = rtu_In2 + rtu_In3;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Sum: '<S4>/Subtract' */
    *rty_Out1 = rtu_In2 - rtu_In3;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Product: '<S5>/Product' */
    *rty_Out1 = rtu_In2 * rtu_In3;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* If: '<S6>/If' incorporates:
     *  Constant: '<S6>/Constant'
     *  Inport: '<S7>/In1'
     *  Inport: '<S8>/In1'
     */
    if (rtu_In3 != 0) {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      rtb_y = rtu_In3;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
       *  ActionPort: '<S7>/Action Port'
       */
      rtb_y = -1;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
    }

    /* End of If: '<S6>/If' */

    /* Product: '<S6>/Divide' */
    *rty_Out1 = div_s32_floor(rtu_In2, rtb_y);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
