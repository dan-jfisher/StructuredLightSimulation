#include "DepthImageGenerator.h"
#include <map>

using namespace Eigen;
using namespace cv;

DepthImageGenerator::DepthImageGenerator()
{
    m_numIrPixels = 100;
    m_referenceMatrix.resize(m_numIrPixels, 2);
    m_referencePlaneDistance = 200;
}

cv::Mat DepthImageGenerator::getDepthImage(SimulationParams params,
                                           Eigen::Matrix<int, Eigen::Dynamic, 2> irPointMatrix) {
    int focalLength; //function of cameraMatrix
    cv::Mat depthImage;

    //perform distance formula calculation on each element of irPointMatrix and m_referenceMatrix
    VectorXi pixelDistancesSquared = (irPointMatrix - m_referenceMatrix).array().pow(2).rowwise().sum();
    VectorXi pixelDistances = pixelDistancesSquared.array().pow(1/2);
    //perform the calculation from Journal of Sensors: Jia et. al.
    VectorXi distancesFromRefPlane = m_referencePlaneDistance /
            (1 + (focalLength * params.emitterDistance) *
             (m_referencePlaneDistance * pixelDistances).array().pow(-1));
    //get distance of each IR projection from the camera
    VectorXi distancesFromCamera = m_referencePlaneDistance - distancesFromRefPlane.array();

    //convert distance vector a map using the coordinates from irPointMatrix
    std::map<int, std::map<int, int>> knownDistances;
    //convert knownDistances to greyscale image
    return depthImage;
}
