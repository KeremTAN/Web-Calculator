#pragma once

#include <memory>
#include "source/restbed"

class IServiceSettingsFactory {

public:
    virtual std::shared_ptr<restbed::Settings> get_settings() const = 0;

};
