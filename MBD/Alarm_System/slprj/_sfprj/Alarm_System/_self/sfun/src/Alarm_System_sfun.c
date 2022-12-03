/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "Alarm_System_sfun.h"
#include "Alarm_System_sfun_debug_macros.h"
#include "c1_Alarm_System.h"
#include "c3_Alarm_System.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Alarm_SystemMachineNumber_;
SFAlarm_SystemLocalData sAlarm_SystemLocalData;

/* Function Declarations */

/* Function Definitions */
void Alarm_System_initializer(void)
{
  _SFD_SET_MACHINE_DATA_VALUE_PTR(_Alarm_SystemMachineNumber_, 0U, (void *)
    &sAlarm_SystemLocalData.m_m_Switch);
  sAlarm_SystemLocalData.m_m_Switch = 0.0;
}

void Alarm_System_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Alarm_System_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Alarm_System_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Alarm_System_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Alarm_System_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4256020664U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1365283942U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2923422650U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(440834945U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Alarm_System_get_check_sum(mxArray *plhs[]);
          sf_c1_Alarm_System_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Alarm_System_get_check_sum(mxArray *plhs[]);
          sf_c3_Alarm_System_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(517912761U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1439515431U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2640612689U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2526347288U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1603652151U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1149539654U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(882354257U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3663213549U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Alarm_System_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "iaIGjY63KJCquM9UsfilTB") == 0) {
          extern mxArray *sf_c1_Alarm_System_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Alarm_System_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "ppBToiZDDWhfvJYt5zw4nC") == 0) {
          extern mxArray *sf_c3_Alarm_System_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Alarm_System_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Alarm_System_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  char instanceChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    mxGetString(prhs[2], instanceChksum,sizeof(instanceChksum)/sizeof(char));
    instanceChksum[(sizeof(instanceChksum)/sizeof(char)-1)] = '\0';
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(instanceChksum, "sL36RM87hCCeqyQOwmP7MyB") == 0) {
          extern const mxArray
            *sf_c1_Alarm_System_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c1_Alarm_System_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     case 3:
      {
        if (strcmp(instanceChksum, "sehqkbOD2w47tgyFatO5XrD") == 0) {
          extern const mxArray
            *sf_c3_Alarm_System_get_eml_resolved_functions_info(void);
          mxArray *persistentMxArray = (mxArray *)
            sf_c3_Alarm_System_get_eml_resolved_functions_info();
          plhs[0] = mxDuplicateArray(persistentMxArray);
          mxDestroyArray(persistentMxArray);
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Alarm_System_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sL36RM87hCCeqyQOwmP7MyB") == 0) {
          extern mxArray *sf_c1_Alarm_System_third_party_uses_info(void);
          plhs[0] = sf_c1_Alarm_System_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sehqkbOD2w47tgyFatO5XrD") == 0) {
          extern mxArray *sf_c3_Alarm_System_third_party_uses_info(void);
          plhs[0] = sf_c3_Alarm_System_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Alarm_System_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sL36RM87hCCeqyQOwmP7MyB") == 0) {
          extern mxArray *sf_c1_Alarm_System_jit_fallback_info(void);
          plhs[0] = sf_c1_Alarm_System_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sehqkbOD2w47tgyFatO5XrD") == 0) {
          extern mxArray *sf_c3_Alarm_System_jit_fallback_info(void);
          plhs[0] = sf_c3_Alarm_System_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Alarm_System_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sL36RM87hCCeqyQOwmP7MyB") == 0) {
          extern mxArray *sf_c1_Alarm_System_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Alarm_System_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "sehqkbOD2w47tgyFatO5XrD") == 0) {
          extern mxArray *sf_c3_Alarm_System_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_Alarm_System_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Alarm_System_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Alarm_SystemMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Alarm_System","sfun",0,2,1,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Alarm_SystemMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_Alarm_SystemMachineNumber_,
    1);
  sf_debug_set_machine_data_scope(debugInstance,_Alarm_SystemMachineNumber_,0,0);
  sf_debug_set_machine_data_name(debugInstance,_Alarm_SystemMachineNumber_,0,
    "Switch");
  sf_debug_set_machine_data_type(debugInstance,_Alarm_SystemMachineNumber_,0,
    SF_DOUBLE,0,0,0.0,1.0,0);
  sf_debug_set_machine_data_size(debugInstance,_Alarm_SystemMachineNumber_,0,0,
    NULL);
  sf_debug_set_machine_data_value_ptr(debugInstance,_Alarm_SystemMachineNumber_,
    0,NULL);
}

void Alarm_System_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_Alarm_System_optimization_info(void);
mxArray* load_Alarm_System_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_Alarm_System_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Alarm_System",
      "Alarm_System");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Alarm_System_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
