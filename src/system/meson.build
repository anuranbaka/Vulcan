system_src = [
    'module_communicator.cpp',
]

system_lib = static_library(
    'vulcan_system',
    system_src,
    include_directories: [vulcan_inc],
    link_with : [lcm_lib],
    dependencies: [lcm_dep, lcmtypes_dep]
)
