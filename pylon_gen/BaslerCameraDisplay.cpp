// Include files to use the pylon API.
#include <pylon/PylonIncludes.h>
#ifdef PYLON_WIN_BUILD
#    include <pylon/PylonGUI.h>
#endif

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// Namespace for using pylon objects.
using namespace Pylon;

// Settings to use any camera type.
#include "BaslerCamera.h"
#include "BaslerCameraArray.h"

using namespace Pylon;
using namespace Pylon::BaslerCameraCameraParams_Params;

// Number of images to be grabbed.
static const uint32_t c_countOfImagesToGrab = 100;

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
        cout << "camera.DeviceModelName = " << camera.DeviceModelName.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.Width = " << camera.Width.ToStringOrDefault("<not readable>") << std::endl;
        cout << "camera.WidthMax = " << camera.WidthMax.ToStringOrDefault("<not readable>") << std::endl;
        
        // Set parameter values
        // camera.Height.TrySetToMaximum();
        // camera.OffsetX.TrySetToMinimum();
        // camera.OffsetY.TrySetToMinimum();
        // camera.Width.TrySetToMaximum();
        
        // Start the grabbing of c_countOfImagesToGrab images.
        // The camera device is parameterized with a default configuration which
        // sets up free-running continuous acquisition.
        camera.StartGrabbing( c_countOfImagesToGrab);

        // This smart pointer will receive the grab result data.
        CGrabResultPtr ptrGrabResult;
        cv::Mat openCvImage;

        CImageFormatConverter formatConverter;
        formatConverter.OutputPixelFormat = PixelType_BGR8packed;
        CPylonImage pylonImage;

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


                formatConverter.Convert(pylonImage, ptrGrabResult);
                openCvImage = cv::Mat(ptrGrabResult->GetHeight(), ptrGrabResult->GetWidth(), CV_8UC3, (uint8_t *)pylonImage.GetBuffer());
            
                cv::imshow("Display window", openCvImage);
                // cv::waitKey(0);
                cv::waitKey(1);
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