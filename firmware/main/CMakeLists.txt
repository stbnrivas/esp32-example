#idf_component_register(SRCS "main.c" INCLUDE_DIRS "")

set(COMPONENT_SRCS "task_boot main.c" )
set(COMPONENT_ADD_INCLUDEDIRS ".")
register_component()