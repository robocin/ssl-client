# ssl-client
> Client base code #ssl #robocup #ssl-vision #grSim 

## Description
This repository was created for the purpose of helping beginner teams.
This project is capable of:
- receive field and robot information via ssl-vision
- receive field and robot information via grSim
- Send commands to robots on grSim

Almost every material present here can be found at:
 [RoboCup/ssl-vision](https://github.com/RoboCup-SSL/ssl-vision)
 [RoboCup/grSim](https://github.com/RoboCup-SSL/grSim)
 [WarBots-RoboCup-SSL](https://github.com/findcongwang/WarBots-RoboCup-SSL)

Feel free to ask and contribute too :)

##Dependencies
- Qt Creator (remember to go in project and disable "shadow build")
- [protobuf](https://github.com/google/protobuf)

##First Steps
1. If you have protobuf installed, check which version you use with the command
```sh
protoc --version
```

1. If you do not , follow the instructions in [C++ Installation - Unix](https://github.com/google/protobuf/tree/master/src)

1. According to its version download the referent in [protobuf/releases](https://github.com/google/protobuf/releases)

1. Extract the downloaded file and go to `/protobuf-2.5.0/src/` *(example version)*

1. Copy the google folder and paste it into `/ssl-client/include/`

1. Go to folder `/ssl-client/pb/` and run
```sh
sh compile.sh
```

*Obs: when building the program, if something referring to `google/protobuf/stubs/common.h` has any errors, it will probably be a version incompetbility problem with protobuf (`include/google`)*

## Usage example
1. open the grsim
1. turn off all robots
1. put them all out of bounds
1. get one of the blue team robots, put it inside the field and turn on
[image1]

1. get the ip and the vision and command ports
[image2]

1. In the project,
go to class x and paste the ip and the port of vision on the line y 
go to the class z and paste the ip and the command port on the line w

###### Author: [Renato Sousa](https://github.com/renatoosousa) 

