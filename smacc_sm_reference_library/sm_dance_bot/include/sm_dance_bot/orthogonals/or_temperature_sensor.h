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

#pragma once

#include <multirole_sensor_client/cl_multirole_sensor.h>
#include <sm_dance_bot/clients/cl_temperature_sensor/cl_temperature_sensor.h>
#include <smacc/smacc_orthogonal.h>
#include <sensor_msgs/msg/temperature.hpp>

using namespace std::chrono_literals;

namespace sm_dance_bot
{
class OrTemperatureSensor : public smacc::Orthogonal<OrTemperatureSensor>
{
public:
  void onInitialize() override
  {
    auto clTemperatureSensor = this->createClient<ClTemperatureSensor>();

    clTemperatureSensor->topicName = "/temperature";
    // ClTemperatureSensor->queueSize = "/front/scan";
    clTemperatureSensor->timeout_ = rclcpp::Duration(10s);

    // clTemperatureSensor->initialize();
  }
};
}  // namespace sm_dance_bot
