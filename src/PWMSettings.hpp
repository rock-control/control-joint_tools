#ifndef JOINT_TOOLS_PWM_SETTINGS_HPP
#define JOINT_TOOLS_PWM_SETTINGS_HPP

#include <base/Time.hpp>

namespace joint_tools
{
    struct PWMSettings
    {
        /** The duty cycle's period */
        base::Time period;
        /** Proportional gain to be used on positive movements
         * (when the current position is less than the target
         */
        float Kpositive = 0;
        /** Effort to be used on positive movements
         * (when the current position is less than the target
         */
        float Vpositive = 0;
        /** Proportional gain to be used on negative movements
         * (when the current position is more than the target
         */
        float Knegative = 0;
        /** Effort to be used on negative movements
         * (when the current position is more than the target
         */
        float Vnegative = 0;
    };
}

#endif

