project('biome1', 'cpp',
    version : '0.1',
    license : ['MIT'],
    meson_version : '>=0.60.0',
    default_options : ['cpp_std=c++20'])

    #all include files in top level directory
    inc = include_directories('include')

    #gtest/gmock dep
    gtest_project = subproject('gtest')
    gtest_dep = gtest_project.get_variable('gtest_dep')
    gmock_dep = gtest_project.get_variable('gmock_dep')

    #holds src file names
    tests_src = []
    project_sources = []
    project_header_files = []

    #add subdirectories
    subdir('test')
    subdir('src')

    #build executables
    e = executable(
        'gtest_all',
        sources: [tests_src],
        include_directories: inc,
        dependencies : [
            gtest_dep,
            gmock_dep,
        ],
    )

    executable('biome1', sources: project_sources, include_directories: inc)

    #run tests
    test('gtest tests', e)