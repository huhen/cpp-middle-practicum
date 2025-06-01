#include <print>
#include <vector>

// template <typename T>
// concept Engine = requires (T t) {
//   { t.getType() } -> std::same_as<std::string>;
//   { t.start() } -> std::same_as<void>;
//   { t.stop() } -> std::same_as<void>;
// };

struct DiselEngine {
    std::string getType() {
        return "Disel";
    }

    void start(){}
    void stop(){}
};

struct GasolineEngine {
    std::string getType() {
        return "Gasoline";
    }

    void start(){}
    void stop(){}
};

struct HybridEngine {
    std::string getType() {
        return "Hybrid";
    }

    void start(){}
    void stop(){}
};

template <typename Engine, typename AuthPolicy>
class Car {
    Engine engine_;
    AuthPolicy auth_;
    
public:
    Car(Engine engine) 
        : engine_(engine) {}

};

int main()
{
   
}