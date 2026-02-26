file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(finance-backend ${SOURCES})

target_include_directories(finance-backend PRIVATE include)

target_link_libraries(finance-backend
    PRIVATE
    Crow::Crow
    nlohmann_json::nlohmann_json
)
