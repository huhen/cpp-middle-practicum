cmake_minimum_required(VERSION 3.31.6)
project(app VERSION 1.0.0 LANGUAGES CXX)

# Configure local githooks
execute_process(
        COMMAND git config core.hooksPath .githooks
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE GIT_COMMAND_RESULT
    )

#
# set(CMAKE_CXX_STANDARD 26) - На данный момент Boost не поддерживает версию стандарта 26
#
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Все предупреждения - это ошибки
    add_compile_options(-Wfatal-errors -Wall -Werror)

    # Не больше одной ошибки за раз
    add_compile_options(-fmax-errors=1)
endif()

# Ищем необходимые библиотеки
find_package(benchmark REQUIRED)
find_package(absl REQUIRED)
find_package(Boost REQUIRED)
# find_package(OpenSSL REQUIRED)
#find_package(SQLite3  REQUIRED)
find_package(GTest REQUIRED)

# Создаём статическую библиотеку
# add_library(${PROJECT_NAME}_imp STATIC ${SRC_FILES} ${HEADER_FILES})

# Добавляем в проект используемые сторонние библиотеки
# target_include_directories(${PROJECT_NAME}_imp PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
#     ${OPENSSL_INCLUDE_DIR}
#     ${Boost_INCLUDE_DIRS}
# )
# target_link_libraries(${PROJECT_NAME}_imp PRIVATE ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

# Создаём исполняемый таргет с одним cpp файлом
add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Указываем пути до include папок сторонних библиотек
target_include_directories(${PROJECT_NAME} PUBLIC
    ${benchmark_INCLUDE_DIRS}
    ${absl_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    # ${OPENSSL_INCLUDE_DIR}
    # ${SQLite3_INCLUDE_DIR}
)

# Линкуем к нему сторонние библиотеки
target_link_libraries(${PROJECT_NAME} PRIVATE 
    benchmark::benchmark_main
    abseil::abseil
    boost::boost
    # openssl::openssl
    # SQLite::SQLite3
)

#
# Тесты
#

# Рекурсивно ищем все используемые в тестах .cpp файлы
file(GLOB TEST_SRC_FILES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

add_executable(${PROJECT_NAME}_tests "${TEST_SRC_FILES}")
# ${PROJECT_NAME}_imp
target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::GTest GTest::Main)
target_include_directories(${PROJECT_NAME}_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Включаем тестирование
enable_testing()
add_test(NAME CryptoGuard_Tests COMMAND ${PROJECT_NAME}_tests)
