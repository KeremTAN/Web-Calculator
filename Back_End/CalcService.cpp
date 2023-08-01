#include "include/CalcService.h"

CalcService::CalcService(
        std::shared_ptr<IResourceFactory> resource_factory,
        std::shared_ptr<IServiceSettingsFactory> settings_factory) {
            m_setting_factory = settings_factory;
            m_service.publish(resource_factory->get_resource());
    }

void CalcService::start() {
    m_service.start(m_setting_factory->get_settings());
}