#include "CameraSimulator.h"

using namespace Eigen;

CameraSimulator::CameraSimulator(Matrix<int, 3, 4> cameraMatrix)
{
    m_cameraMatrix = cameraMatrix;
}

Eigen::Matrix<int, Eigen::Dynamic, 2> CameraSimulator::convertWorldCoordToImageCoord(Matrix<int, 4, Eigen::Dynamic> worldCoordinates){
    Matrix<int, Eigen::Dynamic, 2> cameraCoordinates;
    for (int i = 0; i < worldCoordinates.cols(); i++) {
        auto col = worldCoordinates.col(i);
        Vector3i cameraCoordinateCol = m_cameraMatrix * col;
        cameraCoordinates.conservativeResize(NoChange, cameraCoordinates.cols() + 1);
        int x = cameraCoordinateCol.data()[0];
        int y = cameraCoordinateCol.data()[1];
        cameraCoordinates.col(cameraCoordinates.cols() - 1) << x, y;
    }
}


