// SPDX-License-Identifier: BSD-2-Clause

// This code is part of the sfizz library and is licensed under a BSD 2-clause
// license. You should have receive a LICENSE.md file along with the code.
// If not, contact the sfizz maintainers at https://github.com/sfztools/sfizz

#pragma once
#include "Defaults.h"

namespace sfz
{
struct SynthConfig
{
    bool freeWheeling { false };

    int liveSampleQuality { sfz::Default::sampleQuality };
    int freeWheelingSampleQuality { sfz::Default::sampleQualityInFreewheelingMode };

    int currentSampleQuality() const noexcept
    {
        return freeWheeling ? freeWheelingSampleQuality : liveSampleQuality;
    }
};
}
