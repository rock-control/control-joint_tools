#ifndef JOINT_TOOLS_PWM_HPP
#define JOINT_TOOLS_PWM_HPP

#include <base/Time.hpp>
#include <base/samples/Joints.hpp>
#include <joint_tools/PWMSettings.hpp>
#include <joint_tools/PWMError.hpp>
#include <vector>

namespace joint_tools
{
    /**
     * A simple controller that generates + or - effort for a certain duty cycle
     */
    class PWM
    {
        base::Time mNextCycle;
        base::Time mOff;
        PWMSettings mSettings;
        PWMError mError;

        double mCommand;

    public:
        PWM(PWMSettings settings);
        double update(base::Time now,
            double error);

        PWMError getError() const;
    };
}

#endif
