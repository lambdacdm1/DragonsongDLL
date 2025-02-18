#pragma once

class Settings
{
public:
    static void LoadSettings() noexcept;

    inline static bool debug_logging{};
    inline static float speed_mult = 0.0f;

    static RE::FormID ParseFormID(const std::string& str);

    template <typename T>
    static T* LoadFormPointerFromIni(std::string formId, std::string filename)
    {
        if (!formId.empty()) {
            auto objectFormId = ParseFormID(formId);
            auto form         = RE::TESDataHandler::GetSingleton()->LookupForm(objectFormId, filename)->As<T>();
            return form;
        }
        else {
            return nullptr;
        }
    }
};
