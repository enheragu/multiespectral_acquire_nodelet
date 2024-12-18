// Include files to use the pylon API.
#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif

// Namespace for using pylon objects.
using namespace Pylon;

// Settings to use any camera type.
#include "BaslerCamera.h"
#include "BaslerCameraArray.h"

using namespace Pylon;
using namespace Pylon::BaslerCameraCameraParams_Params;

// Number of images to be grabbed.
static const uint32_t c_countOfImagesToGrab = 10;

// Namespace for using cout.
using namespace std;

int main(int argc, char* argv[])
{
    // The exit code of the sample application.
    int exitCode = 0;

    // Before using any pylon methods, the pylon runtime must be initialized. 
    PylonInitialize();

    try
    {
        // Create an instant camera object with the first found camera device.
        BaslerCamera camera( CTlFactory::GetInstance().CreateFirstDevice());

        // Print the model name of the camera.
        cout << "Using device " << camera.GetDeviceInfo().GetModelName() << endl;
        
        // Open the camera for accessing the parameters.
        camera.Open();

        // Get parameter values
        cout << "camera.AcquisitionFrameCount = " << camera.AcquisitionFrameCount.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionFrameRateAbs = " << camera.AcquisitionFrameRateAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionFrameRateEnable = " << camera.AcquisitionFrameRateEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionMode = " << camera.AcquisitionMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStart = " << camera.AcquisitionStart.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStartEventStreamChannelIndex = " << camera.AcquisitionStartEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStartEventTimestamp = " << camera.AcquisitionStartEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStartOvertriggerEventStreamChannelIndex = " << camera.AcquisitionStartOvertriggerEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStartOvertriggerEventTimestamp = " << camera.AcquisitionStartOvertriggerEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStatus = " << camera.AcquisitionStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStatusSelector = " << camera.AcquisitionStatusSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionStop = " << camera.AcquisitionStop.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionWaitEventStreamChannelIndex = " << camera.AcquisitionWaitEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AcquisitionWaitEventTimestamp = " << camera.AcquisitionWaitEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ActionCommandCount = " << camera.ActionCommandCount.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ActionDeviceKey = " << camera.ActionDeviceKey.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ActionGroupKey = " << camera.ActionGroupKey.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ActionGroupMask = " << camera.ActionGroupMask.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ActionSelector = " << camera.ActionSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoExposureTimeAbsLowerLimit = " << camera.AutoExposureTimeAbsLowerLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoExposureTimeAbsUpperLimit = " << camera.AutoExposureTimeAbsUpperLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIHeight = " << camera.AutoFunctionAOIHeight.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIOffsetX = " << camera.AutoFunctionAOIOffsetX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIOffsetY = " << camera.AutoFunctionAOIOffsetY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOISelector = " << camera.AutoFunctionAOISelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIUsageIntensity = " << camera.AutoFunctionAOIUsageIntensity.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIUsageRedLightCorrection = " << camera.AutoFunctionAOIUsageRedLightCorrection.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIUsageWhiteBalance = " << camera.AutoFunctionAOIUsageWhiteBalance.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionAOIWidth = " << camera.AutoFunctionAOIWidth.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoFunctionProfile = " << camera.AutoFunctionProfile.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoGainRawLowerLimit = " << camera.AutoGainRawLowerLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoGainRawUpperLimit = " << camera.AutoGainRawUpperLimit.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.AutoTargetValue = " << camera.AutoTargetValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceRatioAbs = " << camera.BalanceRatioAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceRatioRaw = " << camera.BalanceRatioRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceRatioSelector = " << camera.BalanceRatioSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceWhiteAdjustmentDampingAbs = " << camera.BalanceWhiteAdjustmentDampingAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceWhiteAdjustmentDampingRaw = " << camera.BalanceWhiteAdjustmentDampingRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceWhiteAuto = " << camera.BalanceWhiteAuto.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BalanceWhiteReset = " << camera.BalanceWhiteReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BinningHorizontal = " << camera.BinningHorizontal.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BinningModeHorizontal = " << camera.BinningModeHorizontal.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BinningModeVertical = " << camera.BinningModeVertical.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BinningVertical = " << camera.BinningVertical.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BlackLevelRaw = " << camera.BlackLevelRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.BlackLevelSelector = " << camera.BlackLevelSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CenterX = " << camera.CenterX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CenterY = " << camera.CenterY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkDynamicRangeMax = " << camera.ChunkDynamicRangeMax.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkDynamicRangeMin = " << camera.ChunkDynamicRangeMin.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkEnable = " << camera.ChunkEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkExposureTime = " << camera.ChunkExposureTime.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkFrameTriggerCounter = " << camera.ChunkFrameTriggerCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkFrameTriggerIgnoredCounter = " << camera.ChunkFrameTriggerIgnoredCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkFramecounter = " << camera.ChunkFramecounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkFramesPerTriggerCounter = " << camera.ChunkFramesPerTriggerCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkGainAll = " << camera.ChunkGainAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkHeight = " << camera.ChunkHeight.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkInputStatusAtLineTriggerBitsPerLine = " << camera.ChunkInputStatusAtLineTriggerBitsPerLine.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkInputStatusAtLineTriggerIndex = " << camera.ChunkInputStatusAtLineTriggerIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkInputStatusAtLineTriggerValue = " << camera.ChunkInputStatusAtLineTriggerValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkLineStatusAll = " << camera.ChunkLineStatusAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkLineTriggerCounter = " << camera.ChunkLineTriggerCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkLineTriggerEndToEndCounter = " << camera.ChunkLineTriggerEndToEndCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkLineTriggerIgnoredCounter = " << camera.ChunkLineTriggerIgnoredCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkModeActive = " << camera.ChunkModeActive.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkOffsetX = " << camera.ChunkOffsetX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkOffsetY = " << camera.ChunkOffsetY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkPayloadCRC16 = " << camera.ChunkPayloadCRC16.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkPixelFormat = " << camera.ChunkPixelFormat.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkSelector = " << camera.ChunkSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkSequenceSetIndex = " << camera.ChunkSequenceSetIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkShaftEncoderCounter = " << camera.ChunkShaftEncoderCounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkStride = " << camera.ChunkStride.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkTimestamp = " << camera.ChunkTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkTriggerinputcounter = " << camera.ChunkTriggerinputcounter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkVirtLineStatusAll = " << camera.ChunkVirtLineStatusAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ChunkWidth = " << camera.ChunkWidth.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ClearLastError = " << camera.ClearLastError.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentEnable = " << camera.ColorAdjustmentEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentHue = " << camera.ColorAdjustmentHue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentHueRaw = " << camera.ColorAdjustmentHueRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentReset = " << camera.ColorAdjustmentReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentSaturation = " << camera.ColorAdjustmentSaturation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentSaturationRaw = " << camera.ColorAdjustmentSaturationRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorAdjustmentSelector = " << camera.ColorAdjustmentSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationMatrixFactor = " << camera.ColorTransformationMatrixFactor.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationMatrixFactorRaw = " << camera.ColorTransformationMatrixFactorRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationSelector = " << camera.ColorTransformationSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationValue = " << camera.ColorTransformationValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationValueRaw = " << camera.ColorTransformationValueRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ColorTransformationValueSelector = " << camera.ColorTransformationValueSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ContrastAbs = " << camera.ContrastAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ContrastMode = " << camera.ContrastMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ContrastPivot = " << camera.ContrastPivot.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ContrastRaw = " << camera.ContrastRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterEventSource = " << camera.CounterEventSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterReset = " << camera.CounterReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterResetSource = " << camera.CounterResetSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CounterSelector = " << camera.CounterSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CriticalTemperatureEventStreamChannelIndex = " << camera.CriticalTemperatureEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.CriticalTemperatureEventTimestamp = " << camera.CriticalTemperatureEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DecimationHorizontal = " << camera.DecimationHorizontal.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DecimationVertical = " << camera.DecimationVertical.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Denoising = " << camera.Denoising.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DenoisingEnable = " << camera.DenoisingEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceFirmwareVersion = " << camera.DeviceFirmwareVersion.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceID = " << camera.DeviceID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceManufacturerInfo = " << camera.DeviceManufacturerInfo.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceModelName = " << camera.DeviceModelName.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceRegistersStreamingEnd = " << camera.DeviceRegistersStreamingEnd.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceRegistersStreamingStart = " << camera.DeviceRegistersStreamingStart.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceReset = " << camera.DeviceReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceScanType = " << camera.DeviceScanType.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceUserID = " << camera.DeviceUserID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceVendorName = " << camera.DeviceVendorName.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DeviceVersion = " << camera.DeviceVersion.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.DigitalShift = " << camera.DigitalShift.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EnableBurstAcquisition = " << camera.EnableBurstAcquisition.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventNotification = " << camera.EventNotification.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventOverrunEventFrameID = " << camera.EventOverrunEventFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventOverrunEventStreamChannelIndex = " << camera.EventOverrunEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventOverrunEventTimestamp = " << camera.EventOverrunEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.EventSelector = " << camera.EventSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExpertFeatureAccessKey = " << camera.ExpertFeatureAccessKey.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExpertFeatureAccessSelector = " << camera.ExpertFeatureAccessSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExpertFeatureEnable = " << camera.ExpertFeatureEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureAuto = " << camera.ExposureAuto.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureEndEventFrameID = " << camera.ExposureEndEventFrameID.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureEndEventStreamChannelIndex = " << camera.ExposureEndEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureEndEventTimestamp = " << camera.ExposureEndEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureMode = " << camera.ExposureMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureOverlapTimeMaxAbs = " << camera.ExposureOverlapTimeMaxAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureOverlapTimeMaxRaw = " << camera.ExposureOverlapTimeMaxRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureTimeAbs = " << camera.ExposureTimeAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ExposureTimeRaw = " << camera.ExposureTimeRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FeatureSet = " << camera.FeatureSet.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileAccessLength = " << camera.FileAccessLength.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileAccessOffset = " << camera.FileAccessOffset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOpenMode = " << camera.FileOpenMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationExecute = " << camera.FileOperationExecute.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationResult = " << camera.FileOperationResult.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationSelector = " << camera.FileOperationSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileOperationStatus = " << camera.FileOperationStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileSelector = " << camera.FileSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FileSize = " << camera.FileSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameStartEventStreamChannelIndex = " << camera.FrameStartEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameStartEventTimestamp = " << camera.FrameStartEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameStartOvertriggerEventStreamChannelIndex = " << camera.FrameStartOvertriggerEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameStartOvertriggerEventTimestamp = " << camera.FrameStartOvertriggerEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameTimeoutEventStreamChannelIndex = " << camera.FrameTimeoutEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameTimeoutEventTimestamp = " << camera.FrameTimeoutEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameWaitEventStreamChannelIndex = " << camera.FrameWaitEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.FrameWaitEventTimestamp = " << camera.FrameWaitEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GainAuto = " << camera.GainAuto.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GainRaw = " << camera.GainRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GainSelector = " << camera.GainSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Gamma = " << camera.Gamma.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GammaEnable = " << camera.GammaEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GammaSelector = " << camera.GammaSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevCCP = " << camera.GevCCP.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevCurrentDefaultGateway = " << camera.GevCurrentDefaultGateway.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevCurrentIPAddress = " << camera.GevCurrentIPAddress.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevCurrentIPConfiguration = " << camera.GevCurrentIPConfiguration.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevCurrentSubnetMask = " << camera.GevCurrentSubnetMask.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevDeviceModeCharacterSet = " << camera.GevDeviceModeCharacterSet.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevDeviceModeIsBigEndian = " << camera.GevDeviceModeIsBigEndian.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevFirstURL = " << camera.GevFirstURL.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevHeartbeatTimeout = " << camera.GevHeartbeatTimeout.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevIEEE1588 = " << camera.GevIEEE1588.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevIEEE1588Status = " << camera.GevIEEE1588Status.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevInterfaceSelector = " << camera.GevInterfaceSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevLinkCrossover = " << camera.GevLinkCrossover.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevLinkFullDuplex = " << camera.GevLinkFullDuplex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevLinkMaster = " << camera.GevLinkMaster.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevLinkSpeed = " << camera.GevLinkSpeed.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevMACAddress = " << camera.GevMACAddress.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevMessageChannelCount = " << camera.GevMessageChannelCount.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevNumberOfInterfaces = " << camera.GevNumberOfInterfaces.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevPersistentDefaultGateway = " << camera.GevPersistentDefaultGateway.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevPersistentIPAddress = " << camera.GevPersistentIPAddress.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevPersistentSubnetMask = " << camera.GevPersistentSubnetMask.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCBWA = " << camera.GevSCBWA.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCBWR = " << camera.GevSCBWR.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCBWRA = " << camera.GevSCBWRA.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCDA = " << camera.GevSCDA.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCDCT = " << camera.GevSCDCT.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCDMT = " << camera.GevSCDMT.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCFJM = " << camera.GevSCFJM.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCFTD = " << camera.GevSCFTD.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPD = " << camera.GevSCPD.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPHostPort = " << camera.GevSCPHostPort.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPInterfaceIndex = " << camera.GevSCPInterfaceIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPSBigEndian = " << camera.GevSCPSBigEndian.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPSDoNotFragment = " << camera.GevSCPSDoNotFragment.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPSFireTestPacket = " << camera.GevSCPSFireTestPacket.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSCPSPacketSize = " << camera.GevSCPSPacketSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSecondURL = " << camera.GevSecondURL.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevStreamChannelCount = " << camera.GevStreamChannelCount.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevStreamChannelSelector = " << camera.GevStreamChannelSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedIEEE1588 = " << camera.GevSupportedIEEE1588.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedIPConfigurationDHCP = " << camera.GevSupportedIPConfigurationDHCP.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedIPConfigurationLLA = " << camera.GevSupportedIPConfigurationLLA.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedIPConfigurationPersistentIP = " << camera.GevSupportedIPConfigurationPersistentIP.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedOptionalCommandsConcatenation = " << camera.GevSupportedOptionalCommandsConcatenation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedOptionalCommandsEVENT = " << camera.GevSupportedOptionalCommandsEVENT.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedOptionalCommandsEVENTDATA = " << camera.GevSupportedOptionalCommandsEVENTDATA.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedOptionalCommandsPACKETRESEND = " << camera.GevSupportedOptionalCommandsPACKETRESEND.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevSupportedOptionalCommandsWRITEMEM = " << camera.GevSupportedOptionalCommandsWRITEMEM.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevTimestampControlLatch = " << camera.GevTimestampControlLatch.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevTimestampControlLatchReset = " << camera.GevTimestampControlLatchReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevTimestampControlReset = " << camera.GevTimestampControlReset.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevTimestampTickFrequency = " << camera.GevTimestampTickFrequency.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevTimestampValue = " << camera.GevTimestampValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevVersionMajor = " << camera.GevVersionMajor.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GevVersionMinor = " << camera.GevVersionMinor.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GrayValueAdjustmentDampingAbs = " << camera.GrayValueAdjustmentDampingAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.GrayValueAdjustmentDampingRaw = " << camera.GrayValueAdjustmentDampingRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Height = " << camera.Height.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.HeightMax = " << camera.HeightMax.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTEnable = " << camera.LUTEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTIndex = " << camera.LUTIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTSelector = " << camera.LUTSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LUTValue = " << camera.LUTValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LastError = " << camera.LastError.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LateActionEventStreamChannelIndex = " << camera.LateActionEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LateActionEventTimestamp = " << camera.LateActionEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LightSourceSelector = " << camera.LightSourceSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line1RisingEdgeEventStreamChannelIndex = " << camera.Line1RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line1RisingEdgeEventTimestamp = " << camera.Line1RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line2RisingEdgeEventStreamChannelIndex = " << camera.Line2RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line2RisingEdgeEventTimestamp = " << camera.Line2RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line3RisingEdgeEventStreamChannelIndex = " << camera.Line3RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line3RisingEdgeEventTimestamp = " << camera.Line3RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line4RisingEdgeEventStreamChannelIndex = " << camera.Line4RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Line4RisingEdgeEventTimestamp = " << camera.Line4RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineDebouncerTimeAbs = " << camera.LineDebouncerTimeAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineFormat = " << camera.LineFormat.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineInverter = " << camera.LineInverter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineLogic = " << camera.LineLogic.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineMode = " << camera.LineMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineSelector = " << camera.LineSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineSource = " << camera.LineSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineStartOvertriggerEventStreamChannelIndex = " << camera.LineStartOvertriggerEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineStartOvertriggerEventTimestamp = " << camera.LineStartOvertriggerEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineStatus = " << camera.LineStatus.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineStatusAll = " << camera.LineStatusAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.LineTermination = " << camera.LineTermination.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.MedianFilter = " << camera.MedianFilter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.MinOutPulseWidthAbs = " << camera.MinOutPulseWidthAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.OffsetX = " << camera.OffsetX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.OffsetY = " << camera.OffsetY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.OverTemperatureEventStreamChannelIndex = " << camera.OverTemperatureEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.OverTemperatureEventTimestamp = " << camera.OverTemperatureEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ParameterSelector = " << camera.ParameterSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PayloadSize = " << camera.PayloadSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelColorFilter = " << camera.PixelColorFilter.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelDynamicRangeMax = " << camera.PixelDynamicRangeMax.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelDynamicRangeMin = " << camera.PixelDynamicRangeMin.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelFormat = " << camera.PixelFormat.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelFormatLegacy = " << camera.PixelFormatLegacy.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.PixelSize = " << camera.PixelSize.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ProcessedRawEnable = " << camera.ProcessedRawEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ReadoutTimeAbs = " << camera.ReadoutTimeAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.RemoveLimits = " << camera.RemoveLimits.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ResultingFramePeriodAbs = " << camera.ResultingFramePeriodAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ResultingFrameRateAbs = " << camera.ResultingFrameRateAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ReverseX = " << camera.ReverseX.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ReverseY = " << camera.ReverseY.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SensorHeight = " << camera.SensorHeight.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SensorWidth = " << camera.SensorWidth.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceAddressBitSelector = " << camera.SequenceAddressBitSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceAddressBitSource = " << camera.SequenceAddressBitSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceAdvanceMode = " << camera.SequenceAdvanceMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceAsyncAdvance = " << camera.SequenceAsyncAdvance.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceAsyncRestart = " << camera.SequenceAsyncRestart.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceControlSelector = " << camera.SequenceControlSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceControlSource = " << camera.SequenceControlSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceCurrentSet = " << camera.SequenceCurrentSet.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceEnable = " << camera.SequenceEnable.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceSetExecutions = " << camera.SequenceSetExecutions.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceSetIndex = " << camera.SequenceSetIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceSetLoad = " << camera.SequenceSetLoad.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceSetStore = " << camera.SequenceSetStore.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SequenceSetTotalNumber = " << camera.SequenceSetTotalNumber.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Sharpness = " << camera.Sharpness.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SharpnessRaw = " << camera.SharpnessRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.ShutterMode = " << camera.ShutterMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SubstrateVoltage = " << camera.SubstrateVoltage.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SyncUserOutputSelector = " << camera.SyncUserOutputSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SyncUserOutputValue = " << camera.SyncUserOutputValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.SyncUserOutputValueAll = " << camera.SyncUserOutputValueAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TestImageSelector = " << camera.TestImageSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDelayAbs = " << camera.TimerDelayAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDelayRaw = " << camera.TimerDelayRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDelayTimebaseAbs = " << camera.TimerDelayTimebaseAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDurationAbs = " << camera.TimerDurationAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDurationRaw = " << camera.TimerDurationRaw.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerDurationTimebaseAbs = " << camera.TimerDurationTimebaseAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerSelector = " << camera.TimerSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerTriggerActivation = " << camera.TimerTriggerActivation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TimerTriggerSource = " << camera.TimerTriggerSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerActivation = " << camera.TriggerActivation.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerDelayAbs = " << camera.TriggerDelayAbs.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerMode = " << camera.TriggerMode.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerSelector = " << camera.TriggerSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerSoftware = " << camera.TriggerSoftware.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.TriggerSource = " << camera.TriggerSource.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserDefinedValue = " << camera.UserDefinedValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserDefinedValueSelector = " << camera.UserDefinedValueSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserOutputSelector = " << camera.UserOutputSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserOutputValue = " << camera.UserOutputValue.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserOutputValueAll = " << camera.UserOutputValueAll.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetDefaultSelector = " << camera.UserSetDefaultSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetLoad = " << camera.UserSetLoad.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetSave = " << camera.UserSetSave.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.UserSetSelector = " << camera.UserSetSelector.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine1RisingEdgeEventStreamChannelIndex = " << camera.VirtualLine1RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine1RisingEdgeEventTimestamp = " << camera.VirtualLine1RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine2RisingEdgeEventStreamChannelIndex = " << camera.VirtualLine2RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine2RisingEdgeEventTimestamp = " << camera.VirtualLine2RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine3RisingEdgeEventStreamChannelIndex = " << camera.VirtualLine3RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine3RisingEdgeEventTimestamp = " << camera.VirtualLine3RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine4RisingEdgeEventStreamChannelIndex = " << camera.VirtualLine4RisingEdgeEventStreamChannelIndex.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.VirtualLine4RisingEdgeEventTimestamp = " << camera.VirtualLine4RisingEdgeEventTimestamp.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Width = " << camera.Width.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.WidthMax = " << camera.WidthMax.ToStringOrDefault("<not readable>") << std::endl;
        
        // Set parameter values
        camera.Height.TrySetToMaximum();
        camera.OffsetX.TrySetToMinimum();
        camera.OffsetY.TrySetToMinimum();
        camera.Width.TrySetToMaximum();
        
        // Start the grabbing of c_countOfImagesToGrab images.
        // The camera device is parameterized with a default configuration which
        // sets up free-running continuous acquisition.
        camera.StartGrabbing( c_countOfImagesToGrab);

        // This smart pointer will receive the grab result data.
        CGrabResultPtr ptrGrabResult;

        // Camera.StopGrabbing() is called automatically by the RetrieveResult() method
        // when c_countOfImagesToGrab images have been retrieved.
        while ( camera.IsGrabbing())
        {
            // Wait for an image and then retrieve it. A timeout of 5000 ms is used.
            camera.RetrieveResult( 5000, ptrGrabResult, TimeoutHandling_ThrowException);

            // Image grabbed successfully?
            if (ptrGrabResult->GrabSucceeded())
            {
                // Access the image data.
                cout << "SizeX: " << ptrGrabResult->GetWidth() << endl;
                cout << "SizeY: " << ptrGrabResult->GetHeight() << endl;
                const uint8_t *pImageBuffer = (uint8_t *) ptrGrabResult->GetBuffer();
                cout << "Gray value of first pixel: " << (uint32_t) pImageBuffer[0] << endl << endl;

#ifdef PYLON_WIN_BUILD
                // Display the grabbed image.
                Pylon::DisplayImage(1, ptrGrabResult);
#endif
            }
            else
            {
                cout << "Error: " << ptrGrabResult->GetErrorCode() << " " << ptrGrabResult->GetErrorDescription() << endl;
            }
        }
        
        // Close the camera.
        camera.Close();
    }
    catch (const GenericException &e)
    {
        // Error handling.
        cerr << "An exception occurred." << endl
        << e.GetDescription() << endl;
        exitCode = 1;
    }

    // Comment the following two lines to disable waiting on exit
    cerr << endl << "Press Enter to exit." << endl;
    while( cin.get() != '\n');

    // Releases all pylon resources. 
    PylonTerminate(); 

    return exitCode;
}