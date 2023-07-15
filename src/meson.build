    main_source = files([
    'Bmap.cpp',
    'creature.cpp',
    'main.cpp',
    'neuron.cpp',
    'world.cpp'
    ])

    #exclude main from the test project
    test_source = files([
        'Bmap.cpp',
        'creature.cpp',
        'neuron.cpp',
        'world.cpp'
    ])

    tests_src += test_source

    project_sources += main_source
    
    main_lib = static_library(
        'main',
        main_source,
        include_directories : inc)
