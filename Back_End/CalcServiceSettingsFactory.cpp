#include "include/CalcServiceSettingsFactory.h"

CalcServiceSettingsFactory::CalcServiceSettingsFactory(){

    m_settings=std::make_shared<restbed::Settings>();
    m_settings->set_port(8080);
    m_settings->set_default_header("Connection", "close");
    m_settings->set_default_header("Access-Control-Allow-Origin", "*");
}

std::shared_ptr<restbed::Settings> CalcServiceSettingsFactory::get_settings() const {
    return m_settings;
};