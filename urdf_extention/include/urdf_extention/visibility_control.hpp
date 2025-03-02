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

#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define URDF_EXPORT __attribute__ ((dllexport))
    #define URDF_IMPORT __attribute__ ((dllimport))
  #else
    #define URDF_EXPORT __declspec(dllexport)
    #define URDF_IMPORT __declspec(dllimport)
  #endif
  #ifdef URDF_BUILDING_LIBRARY
    #define URDF_PUBLIC URDF_EXPORT
  #else
    #define URDF_PUBLIC URDF_IMPORT
  #endif
  #define URDF_PUBLIC_TYPE URDF_PUBLIC
  #define URDF_LOCAL
#else
  #define URDF_EXPORT __attribute__ ((visibility("default")))
  #define URDF_IMPORT
  #if __GNUC__ >= 4
    #define URDF_PUBLIC __attribute__ ((visibility("default")))
    #define URDF_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define URDF_PUBLIC
    #define URDF_LOCAL
  #endif
  #define URDF_PUBLIC_TYPE
#endif
