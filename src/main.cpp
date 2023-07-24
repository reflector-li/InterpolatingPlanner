#include "matplotlibcpp.h"
#include "rs_path.h"
#include "type.h"
#include "math.h"
#include <map>

namespace plt = matplotlibcpp;
using namespace std;
int main() {
// ----------------RS Curve----------------
   Vec3d start_pose(2,2,0),end_pose(7,9,-M_PI/4);
   vector<double> arrow_x = {start_pose[0],end_pose[0]};
   vector<double> arrow_y = {start_pose[1],end_pose[1]};
   vector<double> arrow_u = {1,1};
   vector<double> arrow_v = {arrow_u[0]*tan(start_pose[2]),arrow_u[1]*tan(end_pose[2])};

   double step_size = 0.2;
   double turning_radius = 1.0,length = 0;
   RSPath rs_path(turning_radius);
   VectorVec3d path = rs_path.GetRSPath(start_pose,end_pose,step_size,length);
   
   map<string,string> style;
   style.insert(std::make_pair("color","b"));
   plt::quiver(arrow_x,arrow_y,arrow_u,arrow_v,style);
   plt::plotPath(path,"r");
   plt::xlim(1,10);
   plt::ylim(0,10);

   plt::title("plot interpolating path");
   plt::grid(true);
   plt::show();
   std::cout<<"length: "<<path.size()<<std::endl;

}
