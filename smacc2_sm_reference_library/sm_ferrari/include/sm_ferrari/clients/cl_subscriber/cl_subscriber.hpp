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
#include <smacc2/client_bases/smacc_subscriber_client.hpp>
#include <std_msgs/msg/float32.hpp>

namespace sm_ferrari
{
namespace cl_subscriber
{
class ClSubscriber : public smacc2::client_bases::SmaccSubscriberClient<std_msgs::msg::Float32>
{
public:
  ClSubscriber(std::string topicname)
  : smacc2::client_bases::SmaccSubscriberClient<std_msgs::msg::Float32>(topicname)
  {
  }
};
}  // namespace cl_subscriber
}  // namespace sm_ferrari
