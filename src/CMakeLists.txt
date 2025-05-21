add_executable(MiniPhoto
    main.cpp
    mainwindow.cpp
    mainwindow.hpp
    filtermanager.cpp
    filtermanager.hpp
    image.cpp
    image.hpp
)

add_subdirectory(filters)

target_link_libraries(MiniPhoto PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    ${OpenCV_LIBS}
    Filters
)

install(TARGETS MiniPhoto DESTINATION bin.dbg)