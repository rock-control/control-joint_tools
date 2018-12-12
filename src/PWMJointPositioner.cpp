#include <joint_tools/PWMJointPositioner.hpp>

using namespace std;
using namespace joint_tools;

PWMJointPositioner::PWMJointPositioner()
{
}
PWMJointPositioner::PWMJointPositioner(vector<PWMSettings> const& settings)
    : mPWM(createPWM(settings))
    , mCommands(settings.size())
    , mErrors(settings.size())
{

}

vector<PWM> PWMJointPositioner::createPWM(vector<PWMSettings> const& settings)
{
    vector<PWM> out;
    for (auto s : settings) {
        out.push_back(PWM(s));
    }
    return out;
}

vector<double> const& PWMJointPositioner::update(
    base::Time now,
    base::samples::Joints const& targets,
    base::samples::Joints const& states)
{
    for (size_t i = 0; i < mPWM.size(); ++i) {
        mCommands[i] = mPWM[i].update(now,
            targets.elements[i].position,
            states.elements[i].position);
        mErrors[i] = mPWM[i].getError();
    }
    return mCommands;
}

vector<PWMError> const& PWMJointPositioner::getErrors() const {
    return mErrors;
}