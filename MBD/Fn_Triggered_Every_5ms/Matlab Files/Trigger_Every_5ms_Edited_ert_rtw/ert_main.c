/*
 * File: ert_main.c
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

#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "Trigger_Every_5ms_Edited.h"  /* Model's header file */
#include "rtwtypes.h"
#include "stddef.h"
#define _user_read(var)                (void)var
#define _user_write(var)               (void)var

/*
 * Example use case for call to exported function:
 * In1
 */
void sample_usage_In1(void)
{
  /*
   * Set task inputs here:
   */

  /*
   * Call to exported function
   */
  In1();

  /*
   * Read function outputs here
   */
}

/*
 * The example "main" function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching exported functions to a real-time clock is target specific.
 * This example illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  Trigger_Every_5ms_Edited_initialize();
  while (rtmGetErrorStatus(Trigger_Every_5ms_Edited_M) == (NULL)) {
    /*  Perform application tasks here. */
  }

  /* Terminate model */
  Trigger_Every_5ms_Edited_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
