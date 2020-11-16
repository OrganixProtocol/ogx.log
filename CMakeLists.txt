add_contract(ogx.log ogx.log ${CMAKE_CURRENT_SOURCE_DIR}/src/ogx.log.cpp)

target_include_directories(ogx.log
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_CURRENT_SOURCE_DIR}/../eosio.system/include
   ${CMAKE_CURRENT_SOURCE_DIR}/../eosio.token/include)


set_target_properties(ogx.log
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ricardian/ogx.log.contracts.md ${CMAKE_CURRENT_BINARY_DIR}/ricardian/ogx.log.contracts.md @ONLY )

target_compile_options( ogx.log PUBLIC -R${CMAKE_CURRENT_SOURCE_DIR}/ricardian -R${CMAKE_CURRENT_BINARY_DIR}/ricardian )
