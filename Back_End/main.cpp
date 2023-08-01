#include "include/CalcResourceFactory.h"
#include "include/CalcServiceSettingsFactory.h"
#include "include/CalcService.h"

int main(int argc, char** argv){
    auto resource_factory = std::make_shared<CalcResourceFactory>();
    auto setting_factory = std::make_shared<CalcServiceSettingsFactory>();
    CalcService service {resource_factory, setting_factory};
    service.start();

    return 0;
}