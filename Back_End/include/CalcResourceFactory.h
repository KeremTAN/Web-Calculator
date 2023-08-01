#pragma once

#include "IResourceFactory.h"

#include <tuple>
#include <string>

class CalcResourceFactory : public IResourceFactory {

public:
    CalcResourceFactory();
    virtual std::shared_ptr<restbed::Resource> get_resource() const final;

private:
    std::string to_json(float);
    float calculate(float, float, std::string);
    std::tuple<float, float, std::string> get_path_parameters(const std::shared_ptr<restbed::Session>);
    void get_handler(const std::shared_ptr<restbed::Session>);
    std::shared_ptr<restbed::Resource> m_resource;
};
