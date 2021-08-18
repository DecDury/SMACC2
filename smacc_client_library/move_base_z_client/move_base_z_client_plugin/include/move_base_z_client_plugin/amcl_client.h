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

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/
#pragma once

#include <smacc/client_bases/smacc_action_client_base.h>
#include <smacc/smacc.h>

#include <nav2_msgs/action/navigate_to_pose.hpp>
//#include <move_base_z_client_plugin/components/planner_switcher/planner_switcher.h>

namespace cl_move_base_z
{
class Amcl : public smacc::ISmaccClient
{
public:
  Amcl();
  virtual ~Amcl();
  std::string getName() const override;
};

}  // namespace cl_move_base_z
