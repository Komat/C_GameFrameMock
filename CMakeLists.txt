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
        classes/modules/Modules.h
        classes/modules/Modules/delay/mod_delay.c classes/modules/Modules/delay/mod_delay.h
        classes/modules/Modules/random/mod_random.c classes/modules/Modules/random/mod_random.h
        states/loading/LoadintState.c states/loading/LoadintState.h
        states/intro/IntroState.c states/intro/IntroState.h
        states/main/MainState.c states/main/MainState.h
        states/ending/EndingState.c states/ending/EndingState.h
        states/game_over/GameOverState.c states/game_over/GameOverState.h
)

add_executable(GameFrameDemo ${SOURCE_FILES})
