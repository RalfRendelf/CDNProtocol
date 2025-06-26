cmake_minimum_required(VERSION 3.14)
project(CDNProtocolTests LANGUAGES CXX)

# включаем поддержку тестов
include(CTest)
find_package(Qt6 REQUIRED COMPONENTS Test Core)

# подпроектах у вас есть таргет CDNProtocol
# если вы собираете библиотеку извне — используйте add_subdirectory(..) выше
# или найдите её через find_package/IMPORTED

add_executable(test_ProtocolMessage
    test_ProtocolMessage.cpp
)
target_link_libraries(test_ProtocolMessage
    PRIVATE
        CDNProtocol            # ваша основная библиотека
        Qt6::Test
        Qt6::Core
)
add_test(NAME ProtocolMessageTests COMMAND test_ProtocolMessage)

add_executable(test_CommandRegistry
    test_CommandRegistry.cpp
)
target_link_libraries(test_CommandRegistry
    PRIVATE
        CDNProtocol
        Qt6::Test
        Qt6::Core
)
add_test(NAME CommandRegistryTests COMMAND test_CommandRegistry)
