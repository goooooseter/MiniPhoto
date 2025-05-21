add_library(Filters STATIC
    blurfilter.cpp
    blurfilter.hpp
    brightnessfilter.cpp
    brightnessfilter.hpp
    grayscalefilter.cpp
    grayscalefilter.hpp
    ifilter.hpp
)

target_link_libraries(Filters PRIVATE ${OpenCV_LIBS})

install(TARGETS Filters DESTINATION lib)