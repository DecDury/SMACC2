// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <smacc/smacc.h>

namespace sm_dance_bot
{
namespace SS2
{
namespace sm_dance_bot
{
namespace radial_motion_states
{
// FORWARD DECLARATIONS OF INNER STATES
class StiRadialRotate;
class StiRadialReturn;
class StiRadialEndPoint;
class StiRadialLoopStart;
}  // namespace radial_motion_states
}  // namespace sm_dance_bot
using namespace sm_dance_bot::radial_motion_states;

// STATE DECLARATION
struct SsRadialPattern2 : smacc::SmaccState<SsRadialPattern2, MsDanceBotRunMode, StiRadialLoopStart>
{
public:
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

    Transition<EvLoopEnd<StiRadialLoopStart>, StNavigateReverse1, ENDLOOP>

    >
    reactions;

  // STATE FUNCTIONS
  static void staticConfigure()
  {
    //configure_orthogonal<OrObstaclePerception, CbLidarSensor>();
  }

  void runtimeConfigure() {}

  int iteration_count = 0;
  static constexpr int total_iterations() { return 4; }
  static constexpr float ray_angle_increment_degree() { return 360.0 / total_iterations(); }
  static constexpr float ray_length_meters() { return 5; }
};

// FORWARD DECLARATION FOR THE SUPERSTATE
using SS = SsRadialPattern2;
#include <sm_dance_bot/states/radial_motion_states/sti_radial_end_point.h>
#include <sm_dance_bot/states/radial_motion_states/sti_radial_loop_start.h>
#include <sm_dance_bot/states/radial_motion_states/sti_radial_return.h>
#include <sm_dance_bot/states/radial_motion_states/sti_radial_rotate.h>
}  // namespace SS2
}  // namespace sm_dance_bot
