#include "solver.hpp"
using namespace Eigen;
using namespace std;

Eigen::VectorXd Make_Mass(std::vector<Eigen::Vector4i> &faces, std::vector<Eigen::Vector3d> &vertices, double &rho)
{
    Matrix3d Dm;
    Vector4i index;
    double V, m_tet;
    VectorXd m(3 * vertices.size());
    m.setZero();
    for (int i = 0; i < faces.size(); i++)
    {
        index = faces[i];
        Dm.col(0) = vertices[index[1]] - vertices[index[0]];
        Dm.col(1) = vertices[index[2]] - vertices[index[0]];
        Dm.col(2) = vertices[index[3]] - vertices[index[0]];
        V = std::abs(Dm.determinant()) / 6.0;
        m_tet = V * rho;
        for (int j = 0; j < 4; j++)
        {
            m(3 * index[j]) += m_tet;
            m(3 * index[j] + 1) += m_tet;
            m(3 * index[j] + 2) += m_tet;
        }
    }
    return m;
}