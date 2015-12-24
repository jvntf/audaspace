/*******************************************************************************
* Copyright 2009-2015 Juan Francisco Crespo Galán
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
******************************************************************************/

#pragma once

#include "AUD_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

extern AUD_API AUD_HRTF* AUD_HRTF_create();
extern AUD_API void AUD_HRTF_free(AUD_HRTF* hrtfs);
extern AUD_API void AUD_HRTF_addImpulseResponse(AUD_HRTF* hrtfs, AUD_ImpulseResponse* filter);
extern AUD_API AUD_Source* AUD_Source_create(float azimuth, float elevation);
extern AUD_API void AUD_Source_free(AUD_Source* source);
extern AUD_API float AUD_Source_getAzimuth(AUD_Source* source);
extern AUD_API float AUD_Source_getElevation(AUD_Source* source);
extern AUD_API void AUD_Source_setAzimuth(AUD_Source* source, float azimuth);
extern AUD_API void AUD_Source_setElevation(AUD_Source* source, float elevation);

#ifdef __cplusplus
}
#endif