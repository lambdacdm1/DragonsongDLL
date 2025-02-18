#pragma once

namespace Hooks
{
    void Install() noexcept;

    class Actor__SetMaximumMovementSpeed
    {
    public:
        static float Thunk(RE::Actor*) noexcept;

        inline static REL::Relocation<decltype(&Thunk)> func;
    };

} // namespace Hooks
