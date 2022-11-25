#ifndef __c1_Trigger_Every_5ms_Edited_h__
#define __c1_Trigger_Every_5ms_Edited_h__

/* Type Definitions */
#ifndef typedef_SFc1_Trigger_Every_5ms_EditedInstanceStruct
#define typedef_SFc1_Trigger_Every_5ms_EditedInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_SwitchState;
  uint8_T c1_is_active_c1_Trigger_Every_5ms_Edited;
  uint8_T c1_is_c1_Trigger_Every_5ms_Edited;
  boolean_T c1_Read_Switch;
  boolean_T c1_Switch_Pressed;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_fEmlrtCtx;
} SFc1_Trigger_Every_5ms_EditedInstanceStruct;

#endif                                 /*typedef_SFc1_Trigger_Every_5ms_EditedInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_Trigger_Every_5ms_Edited_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Trigger_Every_5ms_Edited_get_check_sum(mxArray *plhs[]);
extern void c1_Trigger_Every_5ms_Edited_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
