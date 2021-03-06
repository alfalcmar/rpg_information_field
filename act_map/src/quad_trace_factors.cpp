#include "act_map/quad_trace_factors.h"

namespace act_map
{
double getTraceAtRotation(const Eigen::Matrix3d& Rwc, const double k1,
                          const double k2, const double k3, const TraceK1& K1,
                          const TraceK2& K2, const TraceK3& K3)
{
  Eigen::Matrix3d rot = Rwc.transpose();
  rpg::Matrix13 e3TR = Eigen::Vector3d(0, 0, 1).transpose() * rot;
  rpg::Matrix31 e3TR_trans = e3TR.transpose();
  double trace = k1 * e3TR * K1.cast<double>() * e3TR_trans +
                 k2 * (e3TR * K2.cast<double>()).value() +
                 k3 * static_cast<double>(K3(0, 0));
  return trace;
}
}
