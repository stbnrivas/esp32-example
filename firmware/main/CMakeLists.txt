#idf_component_register(SRCS "main.c" INCLUDE_DIRS "")

set(COMPONENT_SRCS "task_boot task_init task_network task_connection main.c" )
set(COMPONENT_ADD_INCLUDEDIRS ".")
register_component()