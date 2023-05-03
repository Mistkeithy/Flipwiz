add_library(uilib STATIC
    "ui_elements.h"
    "ui_elements.cpp"
)

target_include_directories(uilib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(flipwiz
    main.cpp
)

target_link_libraries(flipwiz
    uilib
)

