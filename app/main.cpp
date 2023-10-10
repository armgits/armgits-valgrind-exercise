#include <iostream>
#include <AnalogSensor.hpp>

int main()
{
    AnalogSensor lightSensor(5);
    auto sensor_reading = lightSensor.Read();
    std::cout << "Averaged sensor reading: " << sensor_reading << std::endl;
    bool terminator = sensor_reading;
    if( terminator )
    {
        std::cout << "DONE" << std::endl;
    }
    return 0;
}
