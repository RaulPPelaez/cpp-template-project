

add_executable(privilege_escalation privilege_escalation.cpp)
#Set compile with -O0 to avoid optimization
set_target_properties(privilege_escalation PROPERTIES COMPILE_FLAGS "-O0")

add_executable(memory_layout memory_layout.cpp)
add_executable(casting casting.cpp)
add_executable(pointer_arithmetics pointer_arithmetics.cpp)
