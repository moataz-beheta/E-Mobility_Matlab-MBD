#ifndef __c2_Trigger_Every_5ms_Edited_h__
#define __c2_Trigger_Every_5ms_Edited_h__

/* Type Definitions */
#ifndef typedef_SFc2_Trigger_Every_5ms_EditedInstanceStruct
#define typedef_SFc2_Trigger_Every_5ms_EditedInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_Trigger_Every_5ms_Edited;
  boolean_T c2_Read_Switch;
  boolean_T c2_Switch_Pressed;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_fEmlrtCtx;
} SFc2_Trigger_Every_5ms_EditedInstanceStruct;

#endif                                 /*typedef_SFc2_Trigger_Every_5ms_EditedInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_Trigger_Every_5ms_Edited_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Trigger_Every_5ms_Edited_get_check_sum(mxArray *plhs[]);
extern void c2_Trigger_Every_5ms_Edited_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
