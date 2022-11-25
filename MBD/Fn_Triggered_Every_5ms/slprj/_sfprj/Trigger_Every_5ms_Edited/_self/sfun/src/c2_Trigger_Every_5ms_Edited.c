/* Include files */

#include "Trigger_Every_5ms_Edited_sfun.h"
#include "c2_Trigger_Every_5ms_Edited.h"
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
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void initialize_params_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void enable_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void disable_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void set_sim_state_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void c2_set_sim_state_side_effects_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void finalize_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void sf_gateway_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void mdl_start_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void initSimStructsc2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_b_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_b_Read_Switch, const char_T *c2_identifier);
static boolean_T c2_c_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Trigger_Every_5ms_Edited,
  const char_T *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *c2_f_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier);
static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, int32_T c2_ssid);
static void c2_init_sf_message_store_memory
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_Trigger_Every_5ms_Edited(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_is_active_c2_Trigger_Every_5ms_Edited = 0U;
  chartInstance->c2_Read_Switch = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_Read_Switch, 0U);
  chartInstance->c2_Switch_Pressed = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_Switch_Pressed, 1U);
}

static void initialize_params_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  boolean_T c2_hoistedGlobal;
  const mxArray *c2_b_y = NULL;
  boolean_T c2_b_hoistedGlobal;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  const mxArray *c2_d_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(3, 1), false);
  c2_hoistedGlobal = chartInstance->c2_Read_Switch;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_hoistedGlobal, 11, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_Switch_Pressed;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_Trigger_Every_5ms_Edited;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  chartInstance->c2_Read_Switch = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 0)), "Read_Switch");
  chartInstance->c2_Switch_Pressed = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "Switch_Pressed");
  chartInstance->c2_is_active_c2_Trigger_Every_5ms_Edited =
    c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "is_active_c2_Trigger_Every_5ms_Edited");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_Trigger_Every_5ms_Edited(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  if (chartInstance->c2_doSetSimStateSideEffects != 0) {
    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_gateway_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  c2_set_sim_state_side_effects_c2_Trigger_Every_5ms_Edited(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  chartInstance->c2_Read_Switch = (boolean_T)ReadSwitch(SWITCH_1);
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_Read_Switch, 0U);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c2_sfEvent);
  c2_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(5U, 0U, 0, (boolean_T)
              CV_RELATIONAL_EVAL(5U, 0U, 0, (real_T)
    chartInstance->c2_Read_Switch, 1.0, 0, 0U, (int32_T)
    chartInstance->c2_Read_Switch) != 0U, chartInstance->c2_sfEvent)) != 0);
  if (c2_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
    chartInstance->c2_Switch_Pressed = true;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_Switch_Pressed, 1U);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    chartInstance->c2_Switch_Pressed = false;
    _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c2_Switch_Pressed, 1U);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U, chartInstance->c2_sfEvent);
  c2_b_out = (CV_TRANSITION_EVAL(10U, (int32_T)_SFD_CCP_CALL(5U, 10U, 0,
    (boolean_T)CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
    chartInstance->c2_Switch_Pressed, 1.0, 0, 0U, (int32_T)
    chartInstance->c2_Switch_Pressed) != 0U, chartInstance->c2_sfEvent)) != 0);
  if (c2_b_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
    Led_TurnOn(LED_1);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
    Led_TurnOff(LED_1);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  c2_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc2_Trigger_Every_5ms_Edited
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

const mxArray *sf_c2_Trigger_Every_5ms_Edited_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static boolean_T c2_b_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_b_Read_Switch, const char_T *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Read_Switch),
    &c2_thisId);
  sf_mex_destroy(&c2_b_Read_Switch);
  return c2_y;
}

static boolean_T c2_c_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_Read_Switch;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)
    chartInstanceVoid;
  c2_b_Read_Switch = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_Read_Switch),
    &c2_thisId);
  sf_mex_destroy(&c2_b_Read_Switch);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Trigger_Every_5ms_Edited,
  const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Trigger_Every_5ms_Edited), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Trigger_Every_5ms_Edited);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *c2_f_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_b_setSimStateSideEffectsInfo, const char_T *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  sf_mex_assign(&c2_y, c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), false);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_g_emlrt_marshallIn
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  (void)c2_parentId;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), false);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance, int32_T c2_ssid)
{
  (void)chartInstance;
  (void)c2_ssid;
  return NULL;
}

static void c2_init_sf_message_store_memory
  (SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_Trigger_Every_5ms_EditedInstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
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

void sf_c2_Trigger_Every_5ms_Edited_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3058982711U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3375949542U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(709953007U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(169528618U);
}

mxArray* sf_c2_Trigger_Every_5ms_Edited_get_post_codegen_info(void);
mxArray *sf_c2_Trigger_Every_5ms_Edited_get_autoinheritance_info(void)
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
      sf_c2_Trigger_Every_5ms_Edited_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_Trigger_Every_5ms_Edited_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_Trigger_Every_5ms_Edited_jit_fallback_info(void)
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

mxArray *sf_c2_Trigger_Every_5ms_Edited_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_Trigger_Every_5ms_Edited_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_Trigger_Every_5ms_Edited(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[3],M[14],T\"Read_Switch\",},{M[3],M[15],T\"Switch_Pressed\",},{M[8],M[0],T\"is_active_c2_Trigger_Every_5ms_Edited\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Trigger_Every_5ms_Edited_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc2_Trigger_Every_5ms_EditedInstanceStruct
    *) chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance =
      (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Trigger_Every_5ms_EditedMachineNumber_,
           2,
           0,
           11,
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
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 15 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(0,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 18 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(10,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 18 };

          static int sRelationalopEps[] = { 0 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(10,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
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
    SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance =
      (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c2_Read_Switch);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c2_Switch_Pressed);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sAMJxq1DoaPYFBPN0MXeJvD";
}

static void sf_opaque_initialize_c2_Trigger_Every_5ms_Edited(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Trigger_Every_5ms_EditedInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
  initialize_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Trigger_Every_5ms_Edited(void *chartInstanceVar)
{
  enable_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Trigger_Every_5ms_Edited(void *chartInstanceVar)
{
  disable_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Trigger_Every_5ms_Edited(void *chartInstanceVar)
{
  sf_gateway_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_Trigger_Every_5ms_Edited
  (SimStruct* S)
{
  return get_sim_state_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_Trigger_Every_5ms_Edited(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c2_Trigger_Every_5ms_Edited(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Trigger_Every_5ms_Edited_optimization_info();
    }

    finalize_c2_Trigger_Every_5ms_Edited
      ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Trigger_Every_5ms_Edited
    ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Trigger_Every_5ms_Edited(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Trigger_Every_5ms_Edited
      ((SFc2_Trigger_Every_5ms_EditedInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_Trigger_Every_5ms_Edited(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2978597305U));
  ssSetChecksum1(S,(184629760U));
  ssSetChecksum2(S,(1707286979U));
  ssSetChecksum3(S,(1195491914U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Trigger_Every_5ms_Edited(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_Trigger_Every_5ms_Edited(SimStruct *S)
{
  SFc2_Trigger_Every_5ms_EditedInstanceStruct *chartInstance;
  chartInstance = (SFc2_Trigger_Every_5ms_EditedInstanceStruct *)utMalloc(sizeof
    (SFc2_Trigger_Every_5ms_EditedInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_Trigger_Every_5ms_EditedInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Trigger_Every_5ms_Edited;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Trigger_Every_5ms_Edited;
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
  mdl_start_c2_Trigger_Every_5ms_Edited(chartInstance);
}

void c2_Trigger_Every_5ms_Edited_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Trigger_Every_5ms_Edited(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Trigger_Every_5ms_Edited(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Trigger_Every_5ms_Edited(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Trigger_Every_5ms_Edited_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
