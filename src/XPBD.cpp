#include "XPBD.hpp"
using namespace std;
using namespace Eigen;
template <size_t N>
void XPBD(int &steps,
          double &time,
          vector<Vector3d> &vertices,
          vector<Vector<int, N>> &faces,
          vector<Vector3d> &v0,
          ExternalForceFunc externalForce,
          Eigen::MatrixXd M,
          double E, double P_r)
{
    double h = time / (double)step;
    Eigen::VectorXd lambda = Eigen::VectorXd::Zero(vertices.size());
    vertor<Vector3d> x = vertices;
    vector<Vector3d> v = v0;
    vector<double> alpha = cal_alpha(vertices, faces, E, P_r);
    for (auto &a : alpha)
    {
        a /= (h * h);
    }
    for (int i = 0; i < steps; i++)
    {
        x = x + h * v + h ^ 2 * M.inverse() * externalForce(x);
        // solve iteration
        for (int j = 0; j < alpha.size(); j++)
        {
        }
    }
}

std::vector<double> cal_alpha(std::vector<Eigen::Vector3d> &vertices, std::vector<Eigen::Vector4i> &faces, double E, double P_r)
{
    Matrix3d Dm;
    Vector4i index;
    double V, mu, lambda, alpha_H, alpha_D;
    vector<double> result;
    for (int i = 0; i < faces.size(); i++)
    {
        index = faces[i];
        Dm.col(0) = vertices[index[1]] - vertices[index[0]];
        Dm.col(1) = vertices[index[2]] - vertices[index[0]];
        Dm.col(2) = vertices[index[3]] - vertices[index[0]];
        V = std::abs(Dm.determinant()) / 6.0;
        mu = E / (2.0 * (1.0 + P_r));
        lambda = (E * P_r) / ((1.0 + P_r) * (1.0 - 2.0 * P_r));
        alpha_H = 1.0 / (lambda * V);
        alpha_D = 1.0 / (mu * V);
        result.push_back(alpha_H);
        result.push_back(alpha_D);
    }
    return result;
}

Eigen::MatrixXd cal_gradCH(Eigen::Vector3d x0, Eigen::Vector3d x1, Eigen::Vector3d x2, Eigen::Vector3d x3, Eigen::Vector3d X0, Eigen::Vector3d X1, Eigen::Vector3d X2, Eigen::Vector3d X3)
{
    // cal F in 3*3
    Eigen::Matrix3d F = cal_F(x0, x1, x2, x3, X0, X1, X2, X3);
    // grad CH = grad(det F) = (det F F^-T)grad(F)
    // det F F^-T
    Eigen::Matrix3d adjF_T = F.determinant() * F.inverse().transpose();
}

/**
    @param X means the origional position
    @param x means the current position
 */
// Eigen::Matrix3d cal_F(Eigen::Vector3d &x0, Eigen::Vector3d &x1, Eigen::Vector3d &x2, Eigen::Vector3d &x3, Eigen::Vector3d &X0, Eigen::Vector3d &X1, Eigen::Vector3d &X2, Eigen::Vector3d &X3)
// {
//     Eigen::Matrix3d Dm;
//     Dm.col(0) = X1 - X0;
//     Dm.col(1) = X2 - X0;
//     Dm.col(2) = X3 - X0;

//     Eigen::Matrix3d Ds;
//     Ds.col(0) = x1 - x0;
//     Ds.col(1) = x2 - x0;
//     Ds.col(2) = x3 - x0;
//     Eigen::Matrix3d F = Ds * Dm.inverse();
//     return F;
// }
