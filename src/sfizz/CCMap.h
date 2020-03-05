// SPDX-License-Identifier: BSD-2-Clause

// This code is part of the sfizz library and is licensed under a BSD 2-clause
// license. You should have receive a LICENSE.md file along with the code.
// If not, contact the sfizz maintainers at https://github.com/sfztools/sfizz

#pragma once
#include "LeakDetector.h"
#include <vector>
#include <absl/algorithm/container.h>

namespace sfz {
/**
 * @brief A simple map that holds ValueType elements at different indices, and can return a default one
 * if not present. Used mostly for CC modifiers in region descriptions as to store only the CC modifiers
 * that are specified in the SFZ file rather than a gazillion of dummy "disabled" modifiers. The default
 * value is set on construction.
 *
 * @tparam ValueType The type held in the map
 */
template <class ValueType>
class CCMap {
public:
    CCMap() = delete;
    /**
     * @brief Construct a new CCMap object with the specified default value.
     *
     * @param defaultValue
     */
    CCMap(const ValueType& defaultValue)
        : defaultValue(defaultValue)
    {
    }
    CCMap(CCMap&&) = default;
    CCMap(const CCMap&) = default;
    ~CCMap() = default;

    /**
     * @brief Returns the held object at the index, or a default value if not present
     *
     * @param index
     * @return const ValueType&
     */
    const ValueType& getWithDefault(int index) const noexcept
    {
        auto it = absl::c_find_if(container, [&](auto&& pair){ return pair.first == index; });
        if (it == container.end()) {
            return defaultValue;
        } else {
            return it->second;
        }
    }

    /**
     * @brief Get the value at index or emplace a new one if not present
     *
     * @param index the index of the element
     * @return ValueType&
     */
    ValueType& operator[](const int& index) noexcept
    {
        auto it = absl::c_find_if(container, [&](auto&& pair){ return pair.first == index; });
        if (it == container.end()) {
            container.emplace_back(index, defaultValue);
            return container.back().second;
        } else {
            return it->second;
        }
    }

    /**
     * @brief Is the container empty
     *
     * @return true
     * @return false
     */
    inline bool empty() const { return container.empty(); }
    /**
     * @brief Returns true if the container containers an element at index
     *
     * @param index
     * @return true
     * @return false
     */
    bool contains(int index) const noexcept
    {
        return absl::c_find_if(container, [&](auto&& pair){ return pair.first == index; }) != container.end();
    }
    typename std::vector<std::pair<int, ValueType>>::iterator begin() { return container.begin(); }
    typename std::vector<std::pair<int, ValueType>>::const_iterator begin() const { return container.cbegin(); }
    typename std::vector<std::pair<int, ValueType>>::iterator end() { return container.end(); }
    typename std::vector<std::pair<int, ValueType>>::const_iterator end() const { return container.cend(); }
private:
    const ValueType defaultValue;
    std::vector<std::pair<int, ValueType>> container;
    LEAK_DETECTOR(CCMap);
};
}
