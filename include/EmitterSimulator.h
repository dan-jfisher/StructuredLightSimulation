#pragma once
#include <Eigen/Dense>

struct Plane {
    Eigen::Vector3i normal;
    float distFromOrigin;
};

struct Cube
{
public:
    Plane planes[6];
};

class EmitterSimulator
{
public:
    EmitterSimulator(Cube cube,
                     Eigen::Vector3i emitterLoc);
    Eigen::Vector3i projectBeamOnPlane(Plane plane,
                                      Eigen::Vector3i emitterLoc,
                                      Eigen::Vector3i referencePlaneLoc);
    Eigen::Vector3i projectBeamOnCube(Cube cube,
                                      Eigen::Vector3i emitterLoc,
                                      Eigen::Vector3i referencePlaneLoc);
    Eigen::Matrix<int, 3, Eigen::Dynamic> projectMatrixOnCube(Cube cube);
    static float getDistance(Eigen::Vector3i, Eigen::Vector3i);
private:
    Eigen::Matrix<int, Eigen::Dynamic, 3> m_referenceMatrix;
    Cube m_cube;
    Eigen::Vector3i m_emitterLoc;
};
