#include "Settings.h"

RE::FormID Settings::ParseFormID(const std::string& str)
{
    RE::FormID         result;
    std::istringstream ss{ str };
    ss >> std::hex >> result;
    return result;
}

void Settings::LoadSettings() noexcept
{
    logger::info("Loading settings");

    CSimpleIniA ini;

    ini.SetUnicode();
    ini.LoadFile(R"(.\Data\SKSE\Plugins\DragonsongDLL.ini)");

    debug_logging = ini.GetBoolValue("Log", "Debug");

    if (debug_logging) {
        spdlog::set_level(spdlog::level::debug);
        logger::debug("Debug logging enabled");
    }

    // Load settings

    speed_mult = ini.GetDoubleValue("General", "fDualCastSpeedMult");
    logger::info("Loaded settings");
    logger::info("");
}
