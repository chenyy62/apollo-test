/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file throttleinfo_75.h
 * @brief the class of Throttleinfo75 (for lincoln vehicle)
 */

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

/**
 * @namespace apollo::canbus::lincoln
 * @brief apollo::canbus::lincoln
 */
namespace apollo {
namespace canbus {
namespace lincoln {

/**
 * @class Throttleinfo75
 *
 * @brief one of the protocol data of lincoln vehicle
 */
class Throttleinfo75 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  /*
   * @brief parse received data
   * @param bytes a pointer to the input bytes
   * @param length the length of the input bytes
   * @param chassis_detail the parsed chassis_detail
   */
  virtual void Parse(const std::uint8_t *bytes, int32_t length,
                     ChassisDetail *chassis_detail) const;

  /**
   * @brief calculate engine rpm based on byte array.
   * @param bytes a pointer to the byte array
   * @param length the length of the byte array
   * @return the value of lateral acceleration
   */
  double engine_rpm(const std::uint8_t *bytes, int32_t length) const;

  /**
   * @brief calculate acc pedal percent based on byte array.
   * @param bytes a pointer to the byte array
   * @param length the length of the byte array
   * @return the value of lateral acceleration
   */
  double acc_pedal_percent(const std::uint8_t *bytes, int32_t length) const;

  /**
   * @brief calculate acc pedal rate based on byte array.
   * @param bytes a pointer to the byte array
   * @param length the length of the byte array
   * @return the value of lateral acceleration
   */
  double acc_pedal_rate(const std::uint8_t *bytes, int32_t length) const;
};

}  // namespace lincoln
}  // namespace canbus
}  // namespace apollo