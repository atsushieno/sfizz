// SPDX-License-Identifier: BSD-2-Clause

// This code is part of the sfizz library and is licensed under a BSD 2-clause
// license. You should have receive a LICENSE.md file along with the code.
// If not, contact the sfizz maintainers at https://github.com/sfztools/sfizz

#pragma once
#include "Config.h"
#include "Defaults.h"
#include "SfzFilter.h"
#include "CCMap.h"

namespace sfz
{
struct FilterDescription
{
    float cutoff { Default::filterCutoff };
    float resonance { Default::filterCutoff };
    float gain { Default::filterGain };
    int keytrack { Default::filterKeytrack };
    uint8_t keycenter { Default::filterKeycenter };
    int veltrack { Default::filterVeltrack };
    int random { Default::filterRandom };
    FilterType type { FilterType::kFilterLpf2p };
    CCMap<int> cutoffCC { Default::filterCutoffCC };
    CCMap<float> resonanceCC { Default::filterResonanceCC };
    CCMap<float> gainCC { Default::filterGainCC };
};
}
