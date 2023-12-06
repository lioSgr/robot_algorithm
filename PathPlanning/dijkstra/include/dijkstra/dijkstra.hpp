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


#ifndef DIJKSTRA__DIJKSTRA_HPP_
#define DIJKSTRA__DIJKSTRA_HPP_

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "nav_msgs/msg/path.hpp"

namespace dijkstra
{
class Dijkstra : public rclcpp::Node
{
public:
    /**
     * @brief Construct a new Dijkstra object
     * 
     */
    Dijkstra();
    /**
     * @brief Destroy the Dijkstra object
     * 
     */
    ~Dijkstra();

private:
    //  接收栅格地图
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
    // 发布规划的路径
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
    // 路径规划使用的地图
    nav_msgs::msg::OccupancyGrid map_;

    // 保存地图
    void mapSubCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);

};
}  // namespace dijkstra
#endif  // DIJKSTRA__DIJKSTRA_HPP_
