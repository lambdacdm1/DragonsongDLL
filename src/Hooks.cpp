#include "Hooks.h"
#include "Settings.h"

namespace Hooks
{
    void Install() noexcept
    {
        REL::Relocation main_update{ RELOCATION_ID(0, 37943), REL::Relocate(0x0, 0x51, 0x0) };
        stl::write_thunk_call<Actor__SetMaximumMovementSpeed>(main_update);
        logger::info("Installed main update hook");
        logger::info("");
    }


    float Actor__SetMaximumMovementSpeed::Thunk(RE::Actor* a_actor) noexcept
    {
        if (a_actor) {
            if (a_actor->IsDualCasting()) {
                return Settings::speed_mult * func(a_actor);
            }
        }
        return func(a_actor);
    }

} // namespace Hooks
