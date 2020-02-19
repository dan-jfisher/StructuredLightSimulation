#include "EmitterSimulator.h"

using namespace Eigen;

EmitterSimulator::EmitterSimulator(Cube cube,
                                   Eigen::Vector3i emitterLoc)
{
    //generate reference plane/matrix
}

Eigen::Vector3i EmitterSimulator::projectBeamOnPlane(Plane plane,
                                  Eigen::Vector3i emitterLoc,
                                  Eigen::Vector3i referencePlaneLoc) {
    Vector3i beamVector = referencePlaneLoc - emitterLoc;
    float normDotOrigin = plane.normal.dot(emitterLoc);
    float normDotBeam = plane.normal.dot(beamVector);

    return emitterLoc + (beamVector * (int)((plane.distFromOrigin - normDotOrigin)/normDotBeam));
}

Eigen::Vector3i EmitterSimulator::projectBeamOnCube(Cube cube,
                                  Eigen::Vector3i emitterLoc,
                                  Eigen::Vector3i referencePlaneLoc) {
    Eigen::Vector3i shortestDistIntersect = referencePlaneLoc;
    float shortestDist = getDistance(emitterLoc, referencePlaneLoc);
    for (auto plane : cube.planes) {
        Eigen::Vector3i intersectLoc = projectBeamOnPlane(plane, emitterLoc, referencePlaneLoc);
        float dist = getDistance(emitterLoc, intersectLoc);
        if (dist < shortestDist) {
            shortestDistIntersect = intersectLoc;
            shortestDist = dist;
        }
    }
    return shortestDistIntersect;
}

Eigen::Matrix<int, 3, Eigen::Dynamic> EmitterSimulator::projectMatrixOnCube(Cube cube) {
    Matrix<int, 3, Eigen::Dynamic> cubeIntersectLocs;
    for (int i = 0; i < m_referenceMatrix.rows(); i++) {
        Vector3i row = m_referenceMatrix.row(i);
        auto loc = projectBeamOnCube(cube, m_emitterLoc, row);
        cubeIntersectLocs.conservativeResize(NoChange, cubeIntersectLocs.cols() + 1);
        cubeIntersectLocs.col(cubeIntersectLocs.cols() - 1) = loc;
    }

    cubeIntersectLocs.conservativeResize(cubeIntersectLocs.rows() + 1, NoChange);
    Vector4i constAdditionVect;
    constAdditionVect << 0, 0, 0, 1;
//    cubeIntersectLocs += constAdditionVect;
    return cubeIntersectLocs;
}

float EmitterSimulator::getDistance(Eigen::Vector3i a, Eigen::Vector3i b) {
//    return (b - a).pow(2).colwise().sum().array().pow(1/2);
//    Vector3i diffSquared = (b - a).array().pow(2);
    return 0;
}



