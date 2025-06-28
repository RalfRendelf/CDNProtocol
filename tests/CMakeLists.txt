# # tests/CMakeLists.txt

# set(CMAKE_AUTOMOC ON)  # 🔥 Вот это нужно

# find_package(Qt6 REQUIRED COMPONENTS Test Core)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# add_executable(test_ProtocolMessage test_ProtocolMessage.cpp)
# target_link_libraries(test_ProtocolMessage PRIVATE CDNProtocol Qt6::Test Qt6::Core)
# add_test(NAME ProtocolMessageTests COMMAND test_ProtocolMessage)

# add_executable(test_CommandRegistry test_CommandRegistry.cpp)
# target_link_libraries(test_CommandRegistry PRIVATE CDNProtocol Qt6::Test Qt6::Core)
# add_test(NAME CommandRegistryTests COMMAND test_CommandRegistry)
set(CMAKE_AUTOMOC ON)  # 🔥 Для Q_OBJECT в тестах

find_package(Qt6 REQUIRED COMPONENTS Test Core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Путь к собранной DLL
# get_target_property(CDNProtocol_DLL_PATH CDNProtocol LOCATION)

# ----------------- test_ProtocolMessage -----------------
add_executable(test_ProtocolMessage test_ProtocolMessage.cpp)
target_link_libraries(test_ProtocolMessage PRIVATE CDNProtocol Qt6::Test Qt6::Core)
add_test(NAME ProtocolMessageTests COMMAND test_ProtocolMessage)

# 🔁 Копируем DLL в директорию с .exe
add_custom_command(TARGET test_ProtocolMessage POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CDNProtocol>
        $<TARGET_FILE_DIR:test_ProtocolMessage>
)


# ----------------- test_CommandRegistry -----------------
add_executable(test_CommandRegistry test_CommandRegistry.cpp)
target_link_libraries(test_CommandRegistry PRIVATE CDNProtocol Qt6::Test Qt6::Core)
add_test(NAME CommandRegistryTests COMMAND test_CommandRegistry)

# 🔁 Копируем DLL в директорию с .exe
add_custom_command(TARGET test_CommandRegistry POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:CDNProtocol>
        $<TARGET_FILE_DIR:test_CommandRegistry>
)
