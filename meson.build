project('biome1', 'cpp',
    version : '0.1',
    license : ['MIT'],
    meson_version : '>=0.60.0',
    default_options : ['cpp_std=c++20'])

    project_sources = []
    project_header_files = []
    project_test_sources = []

    #all include files in top level directory
    inc = include_directories('include')

    subdir('src')

    executable('biome1', sources: project_sources, include_directories: inc)
