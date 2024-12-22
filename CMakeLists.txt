cmake_minimum_required(VERSION 3.16)

project(StristSystemQT VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск необходимых компонентов Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets PrintSupport LinguistTools)

set(TS_FILES StristSystemQT_ru_RU.ts)

# Список исходных файлов проекта
set(PROJECT_SOURCES

    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Solver.cpp
    qcustomplot.cpp qcustomplot.h
    ${TS_FILES}
)

# Проверка версии Qt
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(StristSystemQT
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        errorgraph.h errorgraph.cpp errorgraph.ui
        main.cpp
        Solver.h


    )
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(StristSystemQT SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(StristSystemQT
            ${PROJECT_SOURCES}
        )
    endif()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Подключение необходимых библиотек к целевой цели
target_link_libraries(StristSystemQT
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::PrintSupport
)

# Настройки для macOS/iOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.StristSystemQT)
endif()
set_target_properties(StristSystemQT PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Установка путей для сборки
include(GNUInstallDirs)
install(TARGETS StristSystemQT
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Финализация для Qt6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(StristSystemQT)
endif()

