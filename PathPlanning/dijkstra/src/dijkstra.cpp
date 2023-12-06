/*
 Copyright 2023 ROS2 LLC

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */


#include "dijkstra/dijkstra.hpp"

namespace dijkstra
{

Dijkstra::Dijkstra()
: Node("dijkstra")
{
    RCLCPP_INFO(this->get_logger(), "Construct a new Dijkstra object");
    using std::placeholders::_1;
    map_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
        "map",
        rclcpp::QoS(rclcpp::KeepLast(1)).transient_local().reliable(),
        std::bind(&Dijkstra::mapSubCallback, this, _1));
}

Dijkstra::~Dijkstra()
{
    RCLCPP_INFO(this->get_logger(), "Destroy the Dijkstra object");
}

void
Dijkstra::mapSubCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
    map_ = *msg;
    RCLCPP_INFO(this->get_logger(), "Received new map, %d x %d (%f)", map_.info.width, map_.info.height, map_.info.resolution);
}



} // namespace dijkstra
