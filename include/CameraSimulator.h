#pragma once
#include <Eigen/Core>


class CameraSimulator
{
public:
    CameraSimulator(Eigen::Matrix<int, 3, 4>);
    Eigen::Matrix<int, Eigen::Dynamic, 2> convertWorldCoordToImageCoord(Eigen::Matrix<int, 4, Eigen::Dynamic>);
private:
    Eigen::Matrix<int, 3, 4> m_cameraMatrix;
};
