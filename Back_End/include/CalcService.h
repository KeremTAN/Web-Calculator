#pragma once

#include "IService.h"

#include "IResourceFactory.h"
#include "IServiceSettingsFactory.h"

class CalcService : public IService {

public:

    CalcService(
        std::shared_ptr<IResourceFactory>,
        std::shared_ptr<IServiceSettingsFactory>);
    
    void start();

private:
    restbed::Service m_service;
    std::shared_ptr<IServiceSettingsFactory> m_setting_factory;
};