#pragma once

#include "IServiceSettingsFactory.h"

#include <tuple>
#include <string>

class CalcServiceSettingsFactory : public IServiceSettingsFactory {

public:
    CalcServiceSettingsFactory();
    virtual std::shared_ptr<restbed::Settings> get_settings() const;

private:
    std::shared_ptr<restbed::Settings> m_settings;
};
