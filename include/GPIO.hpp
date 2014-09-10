#ifndef GPIOHPP
#define GPIOHPP

#include <fstream>

namespace Lime {
    class GPIO {
        public:
            GPIO(std::string pname, std::string pexpnum, std::string pdirectory);
            ~GPIO();
            
            enum Status {
                Success,
                Failure
            };
            
            enum Direction {
                Input,
                Output
            };
            
            GPIO::Status exportGPIO();
            GPIO::Status unexportGPIO();
            GPIO::Status setDirection(GPIO::Direction direction);
            GPIO::Status setValue(bool value);
            GPIO::Direction getDirection();
            bool getValue();
            
        protected:
        
        private:
            std::string name;
            std::string expnum;
            std::string directory;
    };
}

#endif
