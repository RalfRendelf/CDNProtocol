cmake_minimum_required(VERSION 3.14)
project(CDNProtocol LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(CDNProtocol SHARED
    # public headers
    include/CDNProtocol/Export.h
    include/CDNProtocol/Roles.h
    include/CDNProtocol/CommandEnums.h
    include/CDNProtocol/ProtocolMessage.h
    include/CDNProtocol/ProtocolUtils.h
    include/CDNProtocol/CommandRegistry.h

    # implementation
    src/ProtocolMessage.cpp
    src/ProtocolUtils.cpp
    src/CommandRegistry.cpp
)

# макрос для __declspec(dllexport/dllimport)
target_compile_definitions(CDNProtocol PRIVATE CDNPROTOCOL_LIBRARY)

# так подключаются публичные заголовки
target_include_directories(CDNProtocol
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(CDNProtocol
    PRIVATE Qt6::Core
)

# (опционально) установка библиотеки и хедеров
install(TARGETS CDNProtocol
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)
