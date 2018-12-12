#ifndef JOINT_TOOLS_PWM_JOINT_POSITIONER_HPP
#define JOINT_TOOLS_PWM_JOINT_POSITIONER_HPP

#include <joint_tools/PWM.hpp>
#include <vector>

namespace joint_tools
{
    class PWMJointPositioner
    {
        std::vector<PWM> mPWM;
        std::vector<double> mCommands;
        std::vector<PWMError> mErrors;

    private:
        static std::vector<PWM> createPWM(
            std::vector<PWMSettings> const& settings);
    public:
        PWMJointPositioner();
        PWMJointPositioner(std::vector<PWMSettings> const& settings);

        std::vector<double> const& update(
            base::Time now,
            base::samples::Joints const& targets,
            base::samples::Joints const& states);

        std::vector<PWMError> const& getErrors() const;
    };
}

#endif

