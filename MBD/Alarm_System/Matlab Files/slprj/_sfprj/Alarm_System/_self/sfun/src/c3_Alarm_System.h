#ifndef __c3_Alarm_System_h__
#define __c3_Alarm_System_h__

/* Type Definitions */
#ifndef typedef_SFc3_Alarm_SystemInstanceStruct
#define typedef_SFc3_Alarm_SystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Read_Temp;
  uint8_T c3_is_active_c3_Alarm_System;
  uint8_T c3_is_c3_Alarm_System;
  boolean_T c3_Switch_Pressed;
  real_T c3_Analog_Value;
  real_T c3_Digital_Value;
  real_T c3_Temperature;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
} SFc3_Alarm_SystemInstanceStruct;

#endif                                 /*typedef_SFc3_Alarm_SystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Alarm_System_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Alarm_System_get_check_sum(mxArray *plhs[]);
extern void c3_Alarm_System_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
