append_source_files(SOURCES)

ogs_add_library(TwoPhaseFlowWithPrho ${SOURCES})
target_link_libraries(TwoPhaseFlowWithPrho
                      PUBLIC ProcessLib
                      PRIVATE ParameterLib)

if(BUILD_TESTING)
    include(Tests.cmake)
endif()
