add_library(uilib STATIC
    "ui_elements.h"
    "ui_elements.cpp"
    "ui_proc.h"
    "ui_proc.cpp"
    "ui_styles.h"
    "ui_styles.cpp"
    "ui_set.h"
)

target_include_directories(uilib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(flipwiz
    main.cpp
    resources.rc
)

target_link_libraries(flipwiz
    PRIVATE uilib
)

target_link_libraries(flipwiz PRIVATE Comctl32.lib)

add_link_options("/MANIFESTUAC:\"level='asInvoker' uiAccess='false'\" /MANIFEST:EMBED,ID=1 /manifest:file:${CMAKE_CURRENT_BINARY_DIR}/../application.manifest")

target_sources(flipwiz PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/../application.manifest")