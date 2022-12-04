/* Include files */

#include "Alarm_System_sfun.h"
#include "c3_Alarm_System.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Alarm_System_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Read_Temp                ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void initialize_params_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void enable_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void disable_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_Alarm_System
  (SFc3_Alarm_SystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Alarm_System
  (SFc3_Alarm_SystemInstanceStruct *chartInstance);
static void set_sim_state_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_Alarm_System
  (SFc3_Alarm_SystemInstanceStruct *chartInstance);
static void finalize_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void sf_gateway_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void mdl_start_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void initSimStructsc3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static int32_T c3_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_b_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Read_Temp, const char_T *c3_identifier);
static uint8_T c3_c_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_d_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_Switch_Pressed, const char_T
  *c3_identifier);
static boolean_T c3_e_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_f_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_Analog_Value, const char_T *c3_identifier);
static real_T c3_g_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier);
static const mxArray *c3_i_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc3_Alarm_SystemInstanceStruct *
  chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc3_Alarm_SystemInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_Alarm_SystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_Alarm_System(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  chartInstance->c3_tp_Read_Temp = 0U;
  chartInstance->c3_is_active_c3_Alarm_System = 0U;
  chartInstance->c3_is_c3_Alarm_System = c3_IN_NO_ACTIVE_CHILD;
  chartInstance->c3_Switch_Pressed = false;
  _SFD_DATA_RANGE_CHECK((real_T)chartInstance->c3_Switch_Pressed, 3U);
  chartInstance->c3_Analog_Value = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_Analog_Value, 1U);
  chartInstance->c3_Digital_Value = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_Digital_Value, 2U);
  chartInstance->c3_Temperature = 0.0;
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_Temperature, 4U);
}

static void initialize_params_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_Alarm_System
  (SFc3_Alarm_SystemInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c3_is_active_c3_Alarm_System == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
  }

  if (chartInstance->c3_is_c3_Alarm_System == c3_IN_Read_Temp) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c3_Alarm_System
  (SFc3_Alarm_SystemInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  boolean_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(6, 1), false);
  c3_hoistedGlobal = chartInstance->c3_Analog_Value;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_Digital_Value;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_Switch_Pressed;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_Temperature;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_is_active_c3_Alarm_System;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_is_c3_Alarm_System;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_Analog_Value = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 0)), "Analog_Value");
  chartInstance->c3_Digital_Value = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 1)), "Digital_Value");
  chartInstance->c3_Switch_Pressed = c3_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "Switch_Pressed");
  chartInstance->c3_Temperature = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 3)), "Temperature");
  chartInstance->c3_is_active_c3_Alarm_System = c3_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 4)),
     "is_active_c3_Alarm_System");
  chartInstance->c3_is_c3_Alarm_System = c3_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)), "is_c3_Alarm_System");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_Alarm_System(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_Alarm_System
  (SFc3_Alarm_SystemInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    if (chartInstance->c3_is_c3_Alarm_System == c3_IN_Read_Temp) {
      chartInstance->c3_tp_Read_Temp = 1U;
    } else {
      chartInstance->c3_tp_Read_Temp = 0U;
    }

    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  boolean_T c3_temp;
  boolean_T c3_out;
  c3_set_sim_state_side_effects_c3_Alarm_System(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  if (chartInstance->c3_is_active_c3_Alarm_System == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_active_c3_Alarm_System = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_is_c3_Alarm_System = c3_IN_Read_Temp;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_tp_Read_Temp = 1U;
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c3_sfEvent);
    c3_temp = _SFD_CCP_CALL(5U, 1U, 0, (boolean_T)CV_RELATIONAL_EVAL(5U, 1U, 0,
      sAlarm_SystemLocalData.m_m_Switch, 1.0, -1, 0U,
      sAlarm_SystemLocalData.m_m_Switch == 1.0) != 0U, chartInstance->c3_sfEvent);
    if (c3_temp) {
      c3_temp = _SFD_CCP_CALL(5U, 1U, 1, (boolean_T)CV_RELATIONAL_EVAL(5U, 1U, 1,
        chartInstance->c3_Temperature, 80.0, -1, 5U,
        chartInstance->c3_Temperature >= 80.0) != 0U, chartInstance->c3_sfEvent);
    }

    c3_out = (CV_TRANSITION_EVAL(1U, (int32_T)c3_temp) != 0);
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c3_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c3_sfEvent);
      BuzzerOn();
      Led_TurnOn(LED_RED);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c3_sfEvent);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c3_sfEvent);
      BuzzerOff();
      Led_TurnOff(LED_RED);
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c3_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
    chartInstance->c3_Analog_Value = (real_T)ADC_Read(ADC_CHANNEL);
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Analog_Value, 1U);
    chartInstance->c3_Digital_Value = chartInstance->c3_Analog_Value * 5000.0 /
      1024.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Digital_Value, 2U);
    chartInstance->c3_Temperature = chartInstance->c3_Digital_Value / 10.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c3_Temperature, 4U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc3_Alarm_System(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

const mxArray *sf_c3_Alarm_System_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_b_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_tp_Read_Temp, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Read_Temp),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Read_Temp);
  return c3_y;
}

static uint8_T c3_c_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tp_Read_Temp;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_b_tp_Read_Temp = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tp_Read_Temp),
    &c3_thisId);
  sf_mex_destroy(&c3_b_tp_Read_Temp);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_Switch_Pressed, const char_T
  *c3_identifier)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Switch_Pressed),
    &c3_thisId);
  sf_mex_destroy(&c3_b_Switch_Pressed);
  return c3_y;
}

static boolean_T c3_e_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Switch_Pressed;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_b_Switch_Pressed = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Switch_Pressed),
    &c3_thisId);
  sf_mex_destroy(&c3_b_Switch_Pressed);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_f_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_Analog_Value, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Analog_Value),
    &c3_thisId);
  sf_mex_destroy(&c3_b_Analog_Value);
  return c3_y;
}

static real_T c3_g_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_Analog_Value;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c3_b_Analog_Value = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_Analog_Value),
    &c3_thisId);
  sf_mex_destroy(&c3_b_Analog_Value);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_b_setSimStateSideEffectsInfo, const char_T
  *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_i_emlrt_marshallIn(SFc3_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc3_Alarm_SystemInstanceStruct *
  chartInstance, int32_T c3_ssid)
{
  (void)chartInstance;
  (void)c3_ssid;
  return NULL;
}

static void c3_init_sf_message_store_memory(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_Alarm_SystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_Alarm_SystemInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
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

void sf_c3_Alarm_System_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1545693907U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2386830873U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4184709888U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1766759728U);
}

mxArray* sf_c3_Alarm_System_get_post_codegen_info(void);
mxArray *sf_c3_Alarm_System_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ppBToiZDDWhfvJYt5zw4nC");
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
    mxArray* mxPostCodegenInfo = sf_c3_Alarm_System_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_Alarm_System_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_Alarm_System_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("machine_data");
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

mxArray *sf_c3_Alarm_System_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_Alarm_System_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_Alarm_System(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[3],M[104],T\"Analog_Value\",},{M[3],M[105],T\"Digital_Value\",},{M[3],M[15],T\"Switch_Pressed\",},{M[3],M[106],T\"Temperature\",},{M[8],M[0],T\"is_active_c3_Alarm_System\",},{M[9],M[0],T\"is_c3_Alarm_System\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Alarm_System_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_Alarm_SystemInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Alarm_SystemInstanceStruct *chartInstance =
      (SFc3_Alarm_SystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Alarm_SystemMachineNumber_,
           3,
           1,
           7,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Alarm_SystemMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Alarm_SystemMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Alarm_SystemMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(1,0,0,0,"Analog_Value");
          _SFD_SET_DATA_PROPS(2,0,0,0,"Digital_Value");
          _SFD_SET_DATA_PROPS(3,0,0,0,"Switch_Pressed");
          _SFD_SET_DATA_PROPS(4,0,0,0,"Temperature");
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

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 14 };

          static unsigned int sEndGuardMap[] = { 10, 29 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(1,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1, 14 };

          static unsigned int sEndRelationalopMap[] = { 10, 29 };

          static int sRelationalopEps[] = { -1, -1 };

          static int sRelationalopType[] = { 5, 5, 5, 5, 5, 5, 0, 5 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,2,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)c3_d_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Alarm_SystemMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Alarm_SystemInstanceStruct *chartInstance =
      (SFc3_Alarm_SystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)&chartInstance->c3_Switch_Pressed);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)&chartInstance->c3_Analog_Value);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)&chartInstance->c3_Digital_Value);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c3_Temperature);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sehqkbOD2w47tgyFatO5XrD";
}

static void sf_opaque_initialize_c3_Alarm_System(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_Alarm_SystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*)
    chartInstanceVar);
  initialize_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_Alarm_System(void *chartInstanceVar)
{
  enable_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_Alarm_System(void *chartInstanceVar)
{
  disable_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_Alarm_System(void *chartInstanceVar)
{
  sf_gateway_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_Alarm_System(SimStruct* S)
{
  return get_sim_state_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_Alarm_System(SimStruct* S, const mxArray *
  st)
{
  set_sim_state_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_Alarm_System(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Alarm_SystemInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Alarm_System_optimization_info();
    }

    finalize_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Alarm_System(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Alarm_System((SFc3_Alarm_SystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_Alarm_System(SimStruct *S)
{
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Alarm_System_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3088734878U));
  ssSetChecksum1(S,(2673892818U));
  ssSetChecksum2(S,(913575637U));
  ssSetChecksum3(S,(1270817511U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c3_Alarm_System(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_Alarm_System(SimStruct *S)
{
  SFc3_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc3_Alarm_SystemInstanceStruct *)utMalloc(sizeof
    (SFc3_Alarm_SystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_Alarm_SystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_Alarm_System;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Alarm_System;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_Alarm_System;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_Alarm_System;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_Alarm_System;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_Alarm_System;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_Alarm_System;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Alarm_System;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Alarm_System;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Alarm_System;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_Alarm_System;
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
  mdl_start_c3_Alarm_System(chartInstance);
}

void c3_Alarm_System_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Alarm_System(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Alarm_System(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Alarm_System(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Alarm_System_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
