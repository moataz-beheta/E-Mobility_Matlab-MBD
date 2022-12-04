/* Include files */

#include "Trigger_Every_5ms_Edited_sfun.h"
#include "c1_Trigger_Every_5ms_Edited.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Trigger_Every_5ms_Edited_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_SwitchState              ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void initialize_params_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void enable_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void disable_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void set_sim_state_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void c1_set_sim_state_side_effects_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void finalize_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void sf_gateway_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void mdl_start_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void initSimStructsc1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_b_emlrt_marshallIn(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_SwitchState, const char_T
  *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_d_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_b_Read_Switch, const char_T *c1_identifier);
static boolean_T c1_e_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_g_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, int32_T c1_ssid);
static void c1_init_sf_message_store_memory
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_Trigger_Every_5ms_Edited(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_tp_SwitchState = 0U;
  chartInstance->c1_is_active_c1_Trigger_Every_5ms_Edited = 0U;
  chartInstance->c1_is_c1_Trigger_Every_5ms_Edited = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_Read_Switch = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_Read_Switch, 0U);
  chartInstance->c1_Switch_Pressed = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c1_Switch_Pressed, 1U);
}

static void initialize_params_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_Trigger_Every_5ms_Edited == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_c1_Trigger_Every_5ms_Edited == c1_IN_SwitchState) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  boolean_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  boolean_T c1_b_hoistedGlobal;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  const mxArray *c1_e_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(4, 1), false);
  c1_hoistedGlobal = chartInstance->c1_Read_Switch;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_Switch_Pressed;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_Trigger_Every_5ms_Edited;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_c1_Trigger_Every_5ms_Edited;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  c1_u = sf_mex_dup(c1_st);
  chartInstance->c1_Read_Switch = c1_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Read_Switch");
  chartInstance->c1_Switch_Pressed = c1_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "Switch_Pressed");
  chartInstance->c1_is_active_c1_Trigger_Every_5ms_Edited =
    c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "is_active_c1_Trigger_Every_5ms_Edited");
  chartInstance->c1_is_c1_Trigger_Every_5ms_Edited = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
     "is_c1_Trigger_Every_5ms_Edited");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_Trigger_Every_5ms_Edited(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_c1_Trigger_Every_5ms_Edited == c1_IN_SwitchState) {
      chartInstance->c1_tp_SwitchState = 1U;
    } else {
      chartInstance->c1_tp_SwitchState = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  c1_set_sim_state_side_effects_c1_Trigger_Every_5ms_Edited(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  if (chartInstance->c1_is_active_c1_Trigger_Every_5ms_Edited == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_active_c1_Trigger_Every_5ms_Edited = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    chartInstance->c1_is_c1_Trigger_Every_5ms_Edited = c1_IN_SwitchState;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    chartInstance->c1_tp_SwitchState = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
    Led_TurnOn(LED_1);
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  c1_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc1_Trigger_Every_5ms_Edited
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)(c1_machineNumber);
  (void)(c1_chartNumber);
  (void)(c1_instanceNumber);
}

const mxArray *sf_c1_Trigger_Every_5ms_Edited_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c1_b_tp_SwitchState, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_SwitchState),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_SwitchState);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_SwitchState;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c1_b_tp_SwitchState = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_SwitchState),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_SwitchState);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_d_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_b_Read_Switch, const char_T *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Read_Switch),
    &c1_thisId);
  sf_mex_destroy(&c1_b_Read_Switch);
  return c1_y;
}

static boolean_T c1_e_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Read_Switch;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c1_b_Read_Switch = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Read_Switch),
    &c1_thisId);
  sf_mex_destroy(&c1_b_Read_Switch);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  sf_mex_assign(&c1_y, c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_g_emlrt_marshallIn
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, int32_T c1_ssid)
{
  (void)chartInstance;
  (void)c1_ssid;
  return NULL;
}

static void c1_init_sf_message_store_memory
  (SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance)
{
  chartInstance->c1_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_Trigger_Every_5ms_Edited_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3162444532U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3888676145U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2167725872U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2772260093U);
}

mxArray* sf_c1_Trigger_Every_5ms_Edited_get_post_codegen_info(void);
mxArray *sf_c1_Trigger_Every_5ms_Edited_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zcbZfcRxQFK4N6fJTXEMaH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c1_Trigger_Every_5ms_Edited_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Trigger_Every_5ms_Edited_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Trigger_Every_5ms_Edited_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("custom_code");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c1_Trigger_Every_5ms_Edited_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_Trigger_Every_5ms_Edited_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c1_Trigger_Every_5ms_Edited(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[3],M[14],T\"Read_Switch\",},{M[3],M[15],T\"Switch_Pressed\",},{M[8],M[0],T\"is_active_c1_Trigger_Every_5ms_Edited\",},{M[9],M[0],T\"is_c1_Trigger_Every_5ms_Edited\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Trigger_Every_5ms_Edited_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc1_Trigger_Every_5ms_EditedInstanceStruct
    *) chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance =
      (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Trigger_Every_5ms_EditedMachineNumber_,
           1,
           1,
           2,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Trigger_Every_5ms_EditedMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Trigger_Every_5ms_EditedMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Trigger_Every_5ms_EditedMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"Read_Switch");
          _SFD_SET_DATA_PROPS(1,0,0,0,"Switch_Pressed");
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Trigger_Every_5ms_EditedMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance =
      (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c1_Read_Switch);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c1_Switch_Pressed);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sO4pCOIBXjPmuhyFW1i4WaC";
}

static void sf_opaque_initialize_c1_Trigger_Every_5ms_Edited(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Trigger_Every_5ms_EditedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
  initialize_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Trigger_Every_5ms_Edited(void *chartInstanceVar)
{
  enable_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Trigger_Every_5ms_Edited(void *chartInstanceVar)
{
  disable_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Trigger_Every_5ms_Edited(void *chartInstanceVar)
{
  sf_gateway_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Trigger_Every_5ms_Edited
  (SimStruct* S)
{
  return get_sim_state_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Trigger_Every_5ms_Edited(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c1_Trigger_Every_5ms_Edited(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Trigger_Every_5ms_Edited_optimization_info();
    }

    finalize_c1_Trigger_Every_5ms_Edited
      ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Trigger_Every_5ms_Edited
    ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Trigger_Every_5ms_Edited(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Trigger_Every_5ms_Edited
      ((SFc1_Trigger_Every_5ms_EditedInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_Trigger_Every_5ms_Edited(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Trigger_Every_5ms_Edited_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 1);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2282635063U));
  ssSetChecksum1(S,(3522940697U));
  ssSetChecksum2(S,(2250148342U));
  ssSetChecksum3(S,(2611648506U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Trigger_Every_5ms_Edited(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_Trigger_Every_5ms_Edited(SimStruct *S)
{
  SFc1_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc1_Trigger_Every_5ms_EditedInstanceStruct *)utMalloc(sizeof
    (SFc1_Trigger_Every_5ms_EditedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_Trigger_Every_5ms_EditedInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c1_Trigger_Every_5ms_Edited(chartInstance);
}

void c1_Trigger_Every_5ms_Edited_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Trigger_Every_5ms_Edited(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Trigger_Every_5ms_Edited(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Trigger_Every_5ms_Edited(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Trigger_Every_5ms_Edited_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
