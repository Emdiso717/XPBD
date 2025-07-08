#include <Eigen/Dense>
#include <iostream>

Eigen::VectorXd Make_Mass(
    std::vector<Eigen::Vector4i> &faces,
    std::vector<Eigen::Vector3d> &vertices,
    double &rho);