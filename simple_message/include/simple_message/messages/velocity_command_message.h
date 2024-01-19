/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2013, Southwest Research Institute
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 	* Redistributions of source code must retain the above copyright
 * 	notice, this list of conditions and the following disclaimer.
 * 	* Redistributions in binary form must reproduce the above copyright
 * 	notice, this list of conditions and the following disclaimer in the
 * 	documentation and/or other materials provided with the distribution.
 * 	* Neither the name of the Southwest Research Institute, nor the names
 *	of its contributors may be used to endorse or promote products derived
 *	from this software without specific prior written permission.
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

#ifndef VELOCITY_COMMAND_MESSAGE_H
#define VELOCITY_COMMAND_MESSAGE_H

#include "simple_message/velocity_command.h"

#include "simple_message/byte_array.h"
#include "simple_message/simple_message.h"
#include "simple_message/typed_message.h"

namespace industrial
{
namespace velocity_command_message
{

class VelocityCommandMessage : public industrial::typed_message::TypedMessage
{
public:
  VelocityCommandMessage(void);
  virtual ~VelocityCommandMessage(void);

  void init(void) override;
  void init(const industrial::velocity_command::VelocityCommand& data);
  bool init(industrial::simple_message::SimpleMessage& msg) override;

  unsigned int byteLength() override
  {
    return this->data_.byteLength();
  }

  bool load(industrial::byte_array::ByteArray* buffer) override;
  bool unload(industrial::byte_array::ByteArray* buffer) override;

  industrial::velocity_command::VelocityCommand data_;
};

}  // namespace industrial
}  // namespace velocity_command_message

#endif /* VELOCITY_COMMAND_MESSAGE_H */
