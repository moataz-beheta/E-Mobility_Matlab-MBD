/*
 * File: Traffic_Light_StateFlow.c
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

#include "Traffic_Light_StateFlow.h"
#include "Traffic_Light_StateFlow_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Traffic_Ligh_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Traffic_Light_Stat_IN_Yellow_ON ((uint8_T)4U)
#define Traffic_Light_StateFl_IN_Red_ON ((uint8_T)3U)
#define Traffic_Light_StateFlow_IN_OFF ((uint8_T)2U)
#define Traffic_Light_State_IN_Green_ON ((uint8_T)1U)

/* Block states (default storage) */
DW_Traffic_Light_StateFlow_T Traffic_Light_StateFlow_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Traffic_Light_StateFlow_T Traffic_Light_StateFlow_U;

/* Real-time model */
RT_MODEL_Traffic_Light_StateF_T Traffic_Light_StateFlow_M_;
RT_MODEL_Traffic_Light_StateF_T *const Traffic_Light_StateFlow_M =
  &Traffic_Light_StateFlow_M_;

/* Model step function */
void Traffic_Light_StateFlow_step(void)
{
  int32_T tmp;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/In1'
   */
  if (Traffic_Light_StateFlow_DW.temporalCounter_i1 < 3U) {
    Traffic_Light_StateFlow_DW.temporalCounter_i1++;
  }

  if (Traffic_Light_StateFlow_DW.is_active_c3_Traffic_Light_Stat == 0U) {
    Traffic_Light_StateFlow_DW.is_active_c3_Traffic_Light_Stat = 1U;
    Traffic_Light_StateFlow_DW.is_Traffic_Light = Traffic_Light_StateFlow_IN_OFF;
  } else {
    switch (Traffic_Light_StateFlow_DW.is_Traffic_Light) {
     case Traffic_Light_State_IN_Green_ON:
      if (Traffic_Light_StateFlow_DW.Counter == 0) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_StateFl_IN_Red_ON;
        Traffic_Light_StateFlow_DW.temporalCounter_i1 = 0U;

        /* Enable RED_ON */
        Traffic_Light_StateFlow_DW.Counter = 2U;
      } else if (!Traffic_Light_StateFlow_U.In1) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_StateFlow_IN_OFF;
      } else {
        tmp = Traffic_Light_StateFlow_DW.Counter - 1;
        if (tmp < 0) {
          tmp = 0;
        }

        Traffic_Light_StateFlow_DW.Counter = (uint8_T)tmp;
      }
      break;

     case Traffic_Light_StateFlow_IN_OFF:
      if (Traffic_Light_StateFlow_U.In1) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_StateFl_IN_Red_ON;
        Traffic_Light_StateFlow_DW.temporalCounter_i1 = 0U;

        /* Enable RED_ON */
        Traffic_Light_StateFlow_DW.Counter = 2U;
      }
      break;

     case Traffic_Light_StateFl_IN_Red_ON:
      if (Traffic_Light_StateFlow_DW.Counter == 0) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_Stat_IN_Yellow_ON;
        Traffic_Light_StateFlow_DW.temporalCounter_i1 = 0U;

        /* Enable Yellow_ON */
        Traffic_Light_StateFlow_DW.Counter = 2U;
      } else if (!Traffic_Light_StateFlow_U.In1) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_StateFlow_IN_OFF;
      } else {
        tmp = Traffic_Light_StateFlow_DW.Counter - 1;
        if (tmp < 0) {
          tmp = 0;
        }

        Traffic_Light_StateFlow_DW.Counter = (uint8_T)tmp;
      }
      break;

     default:
      if (Traffic_Light_StateFlow_DW.Counter == 0) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_State_IN_Green_ON;
        Traffic_Light_StateFlow_DW.temporalCounter_i1 = 0U;

        /* Enable Green_ON */
        Traffic_Light_StateFlow_DW.Counter = 2U;
      } else if (!Traffic_Light_StateFlow_U.In1) {
        Traffic_Light_StateFlow_DW.is_Traffic_Light =
          Traffic_Light_StateFlow_IN_OFF;
      } else {
        tmp = Traffic_Light_StateFlow_DW.Counter - 1;
        if (tmp < 0) {
          tmp = 0;
        }

        Traffic_Light_StateFlow_DW.Counter = (uint8_T)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Traffic_Light_StateFlow_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Traffic_Light_StateFlow_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Traffic_Light_StateFlow_DW, 0,
                sizeof(DW_Traffic_Light_StateFlow_T));

  /* external inputs */
  Traffic_Light_StateFlow_U.In1 = false;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  Traffic_Light_StateFlow_DW.is_Traffic_Light = Traffic_Ligh_IN_NO_ACTIVE_CHILD;
  Traffic_Light_StateFlow_DW.temporalCounter_i1 = 0U;
  Traffic_Light_StateFlow_DW.is_active_c3_Traffic_Light_Stat = 0U;
  Traffic_Light_StateFlow_DW.Counter = 0U;
}

/* Model terminate function */
void Traffic_Light_StateFlow_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
