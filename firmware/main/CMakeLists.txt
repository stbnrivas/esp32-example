#idf_component_register(SRCS "main.c" INCLUDE_DIRS "")

set(COMPONENT_SRCS "task_boot task_init task_network task_connection task_update_sender task_update_receiver main.c" )
set(COMPONENT_ADD_INCLUDEDIRS ".")
register_component()