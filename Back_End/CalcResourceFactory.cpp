#include "include/CalcResourceFactory.h"

#include <sstream>
#include <iomanip>

#include "include/json.hpp"

CalcResourceFactory::CalcResourceFactory() {
    m_resource = std::make_shared<restbed::Resource>();
    m_resource->set_path(
        "/{operation: add|subtract|multiply|divide}"
        "/{num1: [-+]?[0-9]*\\.?[0-9]*}"
        "/{num2: [-+]?[0-9]*\\.?[0-9]*}"
    );

    m_resource->set_method_handler("GET", [&](const std::shared_ptr<restbed::Session> session){
        get_handler(session);
    });
}

std::shared_ptr<restbed::Resource> CalcResourceFactory::get_resource() const{
    return m_resource;
}

std::tuple<float, float, std::string> CalcResourceFactory::get_path_parameters(
    const std::shared_ptr<restbed::Session> session){

        const auto& request = session->get_request();
        auto operation = request->get_path_parameter("operation");
        auto num1 = atof(request->get_path_parameter("num1").c_str());
        auto num2 = atof(request->get_path_parameter("num2").c_str());

        return std::make_tuple(num1, num2, operation);
}

float CalcResourceFactory::calculate(float num1, float num2, std::string operation){
    if(operation=="add")
        return num1 + num2;

    else if(operation=="subtract")
        return num1 - num2;
    
    else if(operation=="multiply")
        return num1 * num2;

    else if(operation=="divide")
        return num2 != 0 ? num1 / num2 : 0;
    
    return -1;
}

std::string CalcResourceFactory::to_json(float result){
    std::ostringstream str_stream;
    str_stream << result;
    nlohmann::json jsonResult = {
        {"result", str_stream.str()}
    };

    return jsonResult.dump();
}

void CalcResourceFactory::get_handler(const std::shared_ptr<restbed::Session> session) {
    const auto [num1, num2, operation] = get_path_parameters(session);
    auto result = calculate(num1, num2, operation);
    auto content = to_json(result);
    session->close(restbed::OK, content, 
        {{"Content-Length", std::to_string(content.size())}});
}