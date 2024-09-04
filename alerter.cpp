#include <iostream>
#include <cassert>

int alertFailureCount = 0;

class NetworkInterface {
public:
    virtual int sendAlert(float celcius) = 0;
};

class StubNetworkInterface : public NetworkInterface {
public:
    int sendAlert(float celcius) override {
        std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
        if (celcius > 200) {
            return 500;
        }
        return 200;
    }
};

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void alertInCelcius(float fahrenheit, NetworkInterface* networkInterface) {
    float celcius = convertFahrenheitToCelsius(fahrenheit);
    int returnCode = networkInterface->sendAlert(celcius);
    if (returnCode != 200) {
        alertFailureCount++;
    }
}

void testAlertInCelcius() {
    StubNetworkInterface stubNetwork;
    alertFailureCount = 0;  // Resetting the failure count before test

    alertInCelcius(400.5, &stubNetwork);
    alertInCelcius(392.0, &stubNetwork);
    
    alertInCelcius(303.6, &stubNetwork);
    alertInCelcius(98.6, &stubNetwork);

    assert(alertFailureCount == 2); 
}

int main() {
    testAlertInCelcius();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
