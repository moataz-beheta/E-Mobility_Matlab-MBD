/*
 * File: Alarm_System.c
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

#include "Alarm_System.h"
#include "Alarm_System_private.h"

/* Block states (default storage) */
DW_Alarm_System_T Alarm_System_DW;

/* Real-time model */
RT_MODEL_Alarm_System_T Alarm_System_M_;
RT_MODEL_Alarm_System_T *const Alarm_System_M = &Alarm_System_M_;

/* Model step function */
void Alarm_System_step(void)
{
  real_T Analog_Value;

  /* Chart: '<Root>/ADC Value & LEDs' */
  if (Alarm_System_DW.is_active_c3_Alarm_System == 0U) {
    Alarm_System_DW.is_active_c3_Alarm_System = 1U;
  } else {
    if ((Alarm_System_DW.Switch == 1.0) && (Alarm_System_DW.Temperature >= 80.0))
    {
      BuzzerOn();
      Led_TurnOn(LED_RED);
    } else {
      BuzzerOff();
      Led_TurnOff(LED_RED);
    }

    Analog_Value = (real_T)ADC_Read(ADC_CHANNEL);
    Alarm_System_DW.Temperature = Analog_Value * 5000.0 / 1024.0 / 10.0;
  }

  /* End of Chart: '<Root>/ADC Value & LEDs' */

  /* Chart: '<Root>/Swtich State' */
  Alarm_System_DW.Switch = (real_T)ReadSwitch(SWITCH_1);
  if (Alarm_System_DW.Switch == 1.0) {
    Led_TurnOn(LED_GREEN);
  } else {
    Led_TurnOff(LED_GREEN);
  }

  /* End of Chart: '<Root>/Swtich State' */
}

/* Model initialize function */
void Alarm_System_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Alarm_System_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&Alarm_System_DW, 0,
                sizeof(DW_Alarm_System_T));

  /* Machine initializer */
  Alarm_System_DW.Switch = 0.0;

  /* SystemInitialize for Chart: '<Root>/ADC Value & LEDs' */
  Alarm_System_DW.is_active_c3_Alarm_System = 0U;
  Alarm_System_DW.Temperature = 0.0;
}

/* Model terminate function */
void Alarm_System_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
