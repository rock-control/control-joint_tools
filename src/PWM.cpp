#include <joint_tools/PWM.hpp>

using namespace std;
using namespace joint_tools;

PWM::PWM(PWMSettings settings)
    : mSettings(settings)
{
}

double PWM::update(base::Time now, double error)
{
    if (mNextCycle.isNull())
    {
        mNextCycle = now;
    }

    if (mNextCycle > now)
    {
        if (mOff < now)
            mCommand = 0;
        return mCommand;
    }

    while (now >= mNextCycle) {
        mNextCycle = mNextCycle + mSettings.period;
    }

    double cycle;
    double command;
    if (error > 0) {
        cycle = std::fabs(mSettings.Kpositive * error);
        command = mSettings.Vpositive;
    }
    else {
        cycle = std::fabs(mSettings.Knegative * error);
        command = mSettings.Vnegative;
    }

    mOff = now + mSettings.period * cycle;
    if (mOff > now)
        mCommand = command;
    else
        mCommand = 0;

    mError.error = error;
    mError.duty = cycle;
    return mCommand;
}

PWMError PWM::getError() const
{
    return mError;
}
