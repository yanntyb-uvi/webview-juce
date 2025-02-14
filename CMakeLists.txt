

cmake_minimum_required(VERSION 3.15)
project(SimpleApp VERSION 1.0.0)

set(JUCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs/juce" CACHE PATH "Path to JUCE")

option(JUCE_ENABLE_MODULE_DISCOVERY "Enable module discovery" ON)
option(JUCE_BUILD_EXTRAS "Build JUCE Extras" OFF)
option(JUCE_BUILD_EXAMPLES "Build JUCE Examples" OFF)

add_subdirectory(${JUCE_PATH} JUCE)

juce_add_gui_app(SimpleApp
        PRODUCT_NAME "Simple App"
        VERSION "1.0.0"
        COMPANY_NAME "YourCompany"
        BUNDLE_ID "com.yourcompany.SimpleApp"
        MICROPHONE_PERMISSION_ENABLED FALSE
        CAMERA_PERMISSION_ENABLED FALSE
        BLUETOOTH_PERMISSION_ENABLED FALSE
        FILE_SHARING_ENABLED FALSE
        DOCUMENT_BROWSER_ENABLED FALSE
        REQUIRES_FULL_SCREEN FALSE
#        ICON_BIG "${CMAKE_CURRENT_SOURCE_DIR}/Assets/Icon.png"
)

target_sources(SimpleApp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin/Main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin/MainComponent.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin/MainComponent.h
)

target_compile_features(SimpleApp PRIVATE cxx_std_17)

target_link_libraries(SimpleApp
        PRIVATE
        juce::juce_core
        juce::juce_data_structures
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        "-framework WebKit"
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        juce::juce_gui_extra
)

target_include_directories(SimpleApp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin
)

if(APPLE)
    target_compile_definitions(SimpleApp
            PRIVATE
            JUCE_MAC=1
    )
endif()