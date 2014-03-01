PROJECT(TablasMagIc)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(gtablas Main)
ADD_LIBRARY(gentablam SHARED Tabla)
TARGET_LINK_LIBRARIES(gtablas gentablam)
INSTALL(TARGETS gtablas gentablam
            RUNTIME DESTINATION /usr/bin
            LIBRARY DESTINATION /usr/lib)

