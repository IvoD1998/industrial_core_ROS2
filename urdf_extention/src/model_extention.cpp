/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, ACRO Research Group KULeuven
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *       * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *       * Neither the name of the Southwest Research Institute, nor the names
 *       of its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "urdf_extention/model_extention.hpp"
using namespace std::chrono_literals;

namespace urdf
{
ModelExtention::ModelExtention() : Model(), Node("model_extention")
{
}
ModelExtention::~ModelExtention()
{
}
bool ModelExtention::initParam(const std::string &node_name, const std::string &param_name)
{
    std::vector <rclcpp::Parameter> xml_strings = {};
    rclcpp::Parameter xml_string;

    rclcpp::SyncParametersClient::SharedPtr parameters_client = std::make_shared<rclcpp::SyncParametersClient>(this, node_name);
    while (!parameters_client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
            rclcpp::shutdown();
        }
        RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
  }

    if(!parameters_client->has_parameter(param_name))
    {
        RCLCPP_ERROR(this->get_logger(), "Parameter %s not found in node %s", param_name.c_str(), node_name.c_str());
        return false;
    }

    xml_strings = parameters_client->get_parameters({param_name});
    xml_string = xml_strings[0];

    if(xml_string.get_type() != rclcpp::ParameterType::PARAMETER_STRING)
    {
        RCLCPP_ERROR(this->get_logger(), "Parameter %s of node %s is not of type string", param_name, node_name);
    }
    
    // RCLCPP_INFO(this->get_logger(), xml_string.as_string());

    return this->initString(xml_string.as_string());
}
}
