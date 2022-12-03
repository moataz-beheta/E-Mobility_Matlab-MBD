/* Include files */

#include "Alarm_System_sfun.h"
#include "c1_Alarm_System.h"
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
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void initialize_params_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void enable_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void disable_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_Alarm_System
  (SFc1_Alarm_SystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Alarm_System
  (SFc1_Alarm_SystemInstanceStruct *chartInstance);
static void set_sim_state_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_Alarm_System
  (SFc1_Alarm_SystemInstanceStruct *chartInstance);
static void finalize_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void sf_gateway_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void mdl_start_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void initSimStructsc1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_b_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Alarm_System, const char_T
  *c1_identifier);
static uint8_T c1_c_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_d_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_e_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc1_Alarm_SystemInstanceStruct *
  chartInstance, int32_T c1_ssid);
static void c1_init_sf_message_store_memory(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc1_Alarm_SystemInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_Alarm_SystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc1_Alarm_System(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_c1_Alarm_System = 0U;
}

static void initialize_params_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_Alarm_System
  (SFc1_Alarm_SystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_Alarm_System
  (SFc1_Alarm_SystemInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  const mxArray *c1_b_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(1, 1), false);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_Alarm_System;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  chartInstance->c1_is_active_c1_Alarm_System = c1_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
     "is_active_c1_Alarm_System");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_Alarm_System(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_Alarm_System
  (SFc1_Alarm_SystemInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  boolean_T c1_out;
  c1_set_sim_state_side_effects_c1_Alarm_System(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  sAlarm_SystemLocalData.m_m_Switch = (real_T)ReadSwitch(SWITCH_1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c1_sfEvent);
  c1_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(5U, 1U, 0, (boolean_T)
              CV_RELATIONAL_EVAL(5U, 1U, 0, sAlarm_SystemLocalData.m_m_Switch,
    1.0, -1, 0U, sAlarm_SystemLocalData.m_m_Switch == 1.0) != 0U,
              chartInstance->c1_sfEvent)) != 0);
  if (c1_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
    Led_TurnOn(LED_GREEN);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
    Led_TurnOff(LED_GREEN);
  }

  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
}

static void mdl_start_c1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  c1_init_sf_message_store_memory(chartInstance);
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc1_Alarm_System(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
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

const mxArray *sf_c1_Alarm_System_get_eml_resolved_functions_info(void)
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
  SFc1_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_Alarm_SystemInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
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
  SFc1_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_Alarm_SystemInstanceStruct *)chartInstanceVoid;
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

static uint8_T c1_b_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Alarm_System, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Alarm_System), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Alarm_System);
  return c1_y;
}

static uint8_T c1_c_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
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

static const mxArray *c1_d_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = (const char *)c1_identifier;
  c1_thisId.fParent = NULL;
  c1_thisId.bParentIsCell = false;
  sf_mex_assign(&c1_y, c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_e_emlrt_marshallIn(SFc1_Alarm_SystemInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc1_Alarm_SystemInstanceStruct *
  chartInstance, int32_T c1_ssid)
{
  (void)chartInstance;
  (void)c1_ssid;
  return NULL;
}

static void c1_init_sf_message_store_memory(SFc1_Alarm_SystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc1_Alarm_SystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_Alarm_SystemInstanceStruct
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

void sf_c1_Alarm_System_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2348716266U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3126832053U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3345447800U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2221778618U);
}

mxArray* sf_c1_Alarm_System_get_post_codegen_info(void);
mxArray *sf_c1_Alarm_System_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("iaIGjY63KJCquM9UsfilTB");
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
    mxArray* mxPostCodegenInfo = sf_c1_Alarm_System_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Alarm_System_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Alarm_System_jit_fallback_info(void)
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

mxArray *sf_c1_Alarm_System_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_Alarm_System_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_Alarm_System(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_Alarm_System\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Alarm_System_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc1_Alarm_SystemInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Alarm_SystemInstanceStruct *chartInstance =
      (SFc1_Alarm_SystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Alarm_SystemMachineNumber_,
           1,
           0,
           6,
           0,
           0,
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
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 10 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0, 0, 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
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
    SFc1_Alarm_SystemInstanceStruct *chartInstance =
      (SFc1_Alarm_SystemInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        (void)chartInstance;
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sL36RM87hCCeqyQOwmP7MyB";
}

static void sf_opaque_initialize_c1_Alarm_System(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Alarm_SystemInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*)
    chartInstanceVar);
  initialize_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Alarm_System(void *chartInstanceVar)
{
  enable_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Alarm_System(void *chartInstanceVar)
{
  disable_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Alarm_System(void *chartInstanceVar)
{
  sf_gateway_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_Alarm_System(SimStruct* S)
{
  return get_sim_state_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_Alarm_System(SimStruct* S, const mxArray *
  st)
{
  set_sim_state_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c1_Alarm_System(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Alarm_SystemInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Alarm_System_optimization_info();
    }

    finalize_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Alarm_System(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Alarm_System((SFc1_Alarm_SystemInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c1_Alarm_System(SimStruct *S)
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
  ssSetChecksum0(S,(331718544U));
  ssSetChecksum1(S,(987699462U));
  ssSetChecksum2(S,(496194348U));
  ssSetChecksum3(S,(3191415247U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c1_Alarm_System(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_Alarm_System(SimStruct *S)
{
  SFc1_Alarm_SystemInstanceStruct *chartInstance;
  chartInstance = (SFc1_Alarm_SystemInstanceStruct *)utMalloc(sizeof
    (SFc1_Alarm_SystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc1_Alarm_SystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_Alarm_System;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Alarm_System;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_Alarm_System;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_Alarm_System;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_Alarm_System;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_Alarm_System;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_Alarm_System;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Alarm_System;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Alarm_System;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Alarm_System;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_Alarm_System;
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
  mdl_start_c1_Alarm_System(chartInstance);
}

void c1_Alarm_System_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Alarm_System(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Alarm_System(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Alarm_System(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Alarm_System_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
