#include <GPIO.hpp>

using namespace std;

namespace Lime {
    GPIO::GPIO(std::string pname, std::string pexpnum, std::string pdirectory) {
        name = pname;
        expnum = pexpnum;
        directory = pdirectory;
    }
    
    GPIO::Status GPIO::exportGPIO() {
        ofstream sys("/sys/class/gpio/export", ios::out);
        if(sys) {
            if(sys.write(expnum.c_str(), expnum.length())) {
                sys.close();
                return GPIO::Success;
            }
        }
        sys.close();
        return GPIO::Failure;
    }
    
    GPIO::Status GPIO::unexportGPIO() {
        ofstream sys("/sys/class/gpio/unexport", ios::out);
        if(sys) {
            if(sys.write(expnum.c_str(), expnum.length())) {
                sys.close();
                return GPIO::Success;
            }
        }
        sys.close();
        return GPIO::Failure;
    }
    
    GPIO::Status GPIO::setDirection(GPIO::Direction direction) {
        ofstream sys(string("/sys/class/gpio/" + directory + "/direction").c_str(), ios::out);
        
        if(sys) {
            if(direction == GPIO::Output) {
                if(sys.write("out", 3)) {
                    sys.close();
                    return GPIO::Success;
                }
            } else {
                if(sys.write("in", 2)) {
                    sys.close();
                    return GPIO::Success;
                }
            }
        }
        
        sys.close();
        return GPIO::Failure;
    }
    
    GPIO::Status GPIO::setValue(bool value) {
        ofstream sys(string("/sys/class/gpio/" + directory + "/value").c_str(), ios::out);
        
        if(sys) {
            if(value) {
                if(sys.write("1", 1)) {
                    sys.close();
                    return GPIO::Success;
                }
            } else {
                if(sys.write("0", 1)) {
                    sys.close();
                    return GPIO::Success;
                }
            }
        }
        
        sys.close();
        return GPIO::Failure;
    }
    
    GPIO::Direction GPIO::getDirection() {
        
    }
    
    bool GPIO::getValue() {
    
    }
    
    GPIO::~GPIO() {
        
    }
}
