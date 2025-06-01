#include <print>

struct DefaultLogger {
    void log(const std::string& message) {
        std::println("[Default log] {}", message);
    }
};

template <typename...>
inline auto injected_logger = DefaultLogger{};

template <typename... DummyArgs>
requires (sizeof...(DummyArgs) == 0)
auto log(const std::string& s) -> void {
    auto& logger = injected_logger<DummyArgs...>;
    logger.log(s);
}

// Определяем новый логгер
class ConsoleLogger  {
public:
    void log(const std::string& message) {
        std::println("[Console log] {}", message);
    }
};

class UserManager {
public:
    UserManager() = default;

    void createUser(const std::string& name) {
        // “Бизнес”-логика
        log("Created user: " + name); //Используем внедренную извне зависимость.
    }
};

//Внедряем консольный логгер
template<> inline auto injected_logger<int> = ConsoleLogger{};

int main() {
    // Использование
    UserManager manager;
    manager.createUser("John"); //Используем внутри методов объекта
}
