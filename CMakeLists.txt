cmake_minimum_required(VERSION 3.5)
project(GameFrameDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.c
        classes/core/Dictionary/Hash.c classes/core/Dictionary/Hash.h
        classes/core/Dictionary/Dictionary.c classes/core/Dictionary/Dictionary.h
        classes/core/ItemList/Item.c classes/core/ItemList/Item.h
        classes/core/ItemList/ItemList.c classes/core/ItemList/ItemList.h
        classes/core/PubSub/PubSub.c classes/core/PubSub/PubSub.h
        classes/states/StateMachine/State.c classes/states/StateMachine/State.h
        classes/states/StateMachine/StateMachine.c classes/states/StateMachine/StateMachine.h
        )
add_executable(GameFrameDemo ${SOURCE_FILES})