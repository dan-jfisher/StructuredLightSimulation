#pragma once
#include <Eigen/Core>
#include <opencv2/core.hpp>

struct SimulationParams {
    int emitterDistance;
    Eigen::Matrix<int, 3, 4> cameraMatrix; //pinhole method
};

class DepthImageGenerator
{
public:
    DepthImageGenerator();
    cv::Mat getDepthImage(SimulationParams params,
                      Eigen::Matrix<int, Eigen::Dynamic, 2> irPointMatrix);

private:
    int m_numIrPixels;
    Eigen::Matrix<int, Eigen::Dynamic, 2> m_referenceMatrix;
    int m_referencePlaneDistance;
};

