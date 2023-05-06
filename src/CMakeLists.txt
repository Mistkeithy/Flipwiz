add_library(uilib STATIC
    "ui_elements.h"
    "ui_elements.cpp"
    "ui_messages.h"
    "ui_messages.cpp"
)

target_include_directories(uilib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(flipwiz
    main.cpp
    resources.rc
)

target_link_libraries(flipwiz
    uilib
)

add_link_options("/MANIFESTUAC:\"level='asInvoker' uiAccess='false'\" /MANIFEST:EMBED,ID=1 /manifest:file:${CMAKE_CURRENT_BINARY_DIR}/../application.manifest")

target_sources(flipwiz PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/../application.manifest")