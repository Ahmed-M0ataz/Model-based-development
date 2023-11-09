/*
 * File: daming_change.c
 *
 * Code generated for Simulink model 'daming_change'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov  9 19:24:35 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "daming_change.h"
#include "daming_change_types.h"
#include "rtwtypes.h"
#include "daming_change_private.h"

/* Block signals (default storage) */
B_daming_change_T daming_change_B;

/* Block states (default storage) */
DW_daming_change_T daming_change_DW;

/* Real-time model */
static RT_MODEL_daming_change_T daming_change_M_;
RT_MODEL_daming_change_T *const daming_change_M = &daming_change_M_;

/* Model step function */
void daming_change_step(void)
{
  MW_AnalogIn_ResultDataType_Type datatype_id;
  codertarget_arduinobase_int_o_T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T u0;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (daming_change_DW.obj.SampleTime != daming_change_P.AnalogInput_SampleTime)
  {
    daming_change_DW.obj.SampleTime = daming_change_P.AnalogInput_SampleTime;
  }

  obj = &daming_change_DW.obj;
  obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
  datatype_id = MW_ANALOGIN_UINT16;
  MW_AnalogInSingle_ReadResult
    (daming_change_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     datatype_id);

  /* Gain: '<Root>/Gain1' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   */
  daming_change_B.response = (uint32_T)daming_change_P.Gain1_Gain *
    b_varargout_1;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (daming_change_P.ManualSwitch_CurrentSetting == 1) {
    /* Step: '<Root>/Step' */
    if (daming_change_M->Timing.t[0] < daming_change_P.Step_Time) {
      /* ManualSwitch: '<Root>/Manual Switch' */
      daming_change_B.finalvalue = daming_change_P.Step_Y0;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' */
      daming_change_B.finalvalue = daming_change_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    daming_change_B.finalvalue = daming_change_P.Constant_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLABSystem: '<Root>/PWM' */
  obj_0 = &daming_change_DW.obj_j;
  obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Gain: '<Root>/Gain' */
  u0 = daming_change_P.Gain_Gain * daming_change_B.finalvalue;

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(daming_change_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, u0);

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((daming_change_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((daming_change_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  daming_change_M->Timing.t[0] =
    ((time_T)(++daming_change_M->Timing.clockTick0)) *
    daming_change_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    daming_change_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void daming_change_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&daming_change_M->solverInfo,
                          &daming_change_M->Timing.simTimeStep);
    rtsiSetTPtr(&daming_change_M->solverInfo, &rtmGetTPtr(daming_change_M));
    rtsiSetStepSizePtr(&daming_change_M->solverInfo,
                       &daming_change_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&daming_change_M->solverInfo, (&rtmGetErrorStatus
      (daming_change_M)));
    rtsiSetRTModelPtr(&daming_change_M->solverInfo, daming_change_M);
  }

  rtsiSetSimTimeStep(&daming_change_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&daming_change_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(daming_change_M, &daming_change_M->Timing.tArray[0]);
  rtmSetTFinal(daming_change_M, 10.0);
  daming_change_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  daming_change_M->Sizes.checksums[0] = (3527056770U);
  daming_change_M->Sizes.checksums[1] = (2746546449U);
  daming_change_M->Sizes.checksums[2] = (3794780515U);
  daming_change_M->Sizes.checksums[3] = (2461363831U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    daming_change_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(daming_change_M->extModeInfo,
      &daming_change_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(daming_change_M->extModeInfo,
                        daming_change_M->Sizes.checksums);
    rteiSetTPtr(daming_change_M->extModeInfo, rtmGetTPtr(daming_change_M));
  }

  {
    codertarget_arduinobase_int_o_T *obj_0;
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    daming_change_DW.obj.matlabCodegenIsDeleted = true;
    daming_change_DW.obj.isInitialized = 0L;
    daming_change_DW.obj.SampleTime = -1.0;
    daming_change_DW.obj.matlabCodegenIsDeleted = false;
    daming_change_DW.obj.SampleTime = daming_change_P.AnalogInput_SampleTime;
    obj = &daming_change_DW.obj;
    daming_change_DW.obj.isSetupComplete = false;
    daming_change_DW.obj.isInitialized = 1L;
    obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(54UL);
    daming_change_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    daming_change_DW.obj_j.matlabCodegenIsDeleted = true;
    daming_change_DW.obj_j.isInitialized = 0L;
    daming_change_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &daming_change_DW.obj_j;
    daming_change_DW.obj_j.isSetupComplete = false;
    daming_change_DW.obj_j.isInitialized = 1L;
    obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
    daming_change_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void daming_change_terminate(void)
{
  codertarget_arduinobase_int_o_T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  obj = &daming_change_DW.obj;
  if (!daming_change_DW.obj.matlabCodegenIsDeleted) {
    daming_change_DW.obj.matlabCodegenIsDeleted = true;
    if ((daming_change_DW.obj.isInitialized == 1L) &&
        daming_change_DW.obj.isSetupComplete) {
      obj->AnalogInDriverObj.MW_ANALOGIN_HANDLE = MW_AnalogIn_GetHandle(54UL);
      MW_AnalogIn_Close
        (daming_change_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj_0 = &daming_change_DW.obj_j;
  if (!daming_change_DW.obj_j.matlabCodegenIsDeleted) {
    daming_change_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((daming_change_DW.obj_j.isInitialized == 1L) &&
        daming_change_DW.obj_j.isSetupComplete) {
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(daming_change_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj_0->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(daming_change_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
