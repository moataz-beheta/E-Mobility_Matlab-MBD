#ifndef __c1_Alarm_System_h__
#define __c1_Alarm_System_h__

/* Type Definitions */
#ifndef typedef_SFc1_Alarm_SystemInstanceStruct
#define typedef_SFc1_Alarm_SystemInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Alarm_System;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_fEmlrtCtx;
} SFc1_Alarm_SystemInstanceStruct;

#endif                                 /*typedef_SFc1_Alarm_SystemInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Alarm_System_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Alarm_System_get_check_sum(mxArray *plhs[]);
extern void c1_Alarm_System_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
