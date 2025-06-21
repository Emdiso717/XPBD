#include <Eigen/Dense>
#include <vector>
#include <functional>
#include <iostream>
using ExternalForceFunc = std::function<
    std::vector<Eigen::Vector3d>(const std::vector<Eigen::Vector3d> &vertices)>;

template <size_t N>
void XPBD(int &steps,
          double &time,
          std::vector<Eigen::Vector3d> &vertices,
          std::vector<Eigen::Vector<int, N>> &faces,
          std::vector<Eigen::Vector3d> &v0,
          ExternalForceFunc externalForce,
          Eigen::MatrixXd M,
          double E, double P_r);

std::vector<double> cal_alpha(std::vector<Eigen::Vector3d> &vertices,
                              std::vector<Eigen::Vector4i> &faces,
                              double E, double P_r);

Eigen::MatrixXd cal_F(Eigen::Vector3d &x0, Eigen::Vector3d &x1, Eigen::Vector3d &x2, Eigen::Vector3d &x3, Eigen::Vector3d &X0, Eigen::Vector3d &X1, Eigen::Vector3d &X2, Eigen::Vector3d &X3);

Eigen::Matrix3d cal_gradCH(Eigen::Matrix3d F, double gamma);