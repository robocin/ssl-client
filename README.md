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

1. Go to folder `/ssl-client/ssl-Client/pb/proto/` and run
```sh
sh compile.sh
```

*Obs: when building the program, if something referring to `google/protobuf/stubs/common.h` has any errors, it will probably be a version incompetbility problem with protobuf (`include/google`)*

## Usage example
1. Open the grSim
1. Turn off all robots
1. Put them all out of bounds
1. Get one of the blue team robots, put it inside the field and turn on
![](prints/exampleSimulation.png)

1. Get the Vision Multicast adress, Vision Multicast port and Command listen port on grSim
![](prints/ips.png)

1. In the project,
go to class x and paste the ip and the port of vision on the line y 
go to the class z and paste the ip and the command port on the line w

###### Author: [Renato Sousa](https://github.com/renatoosousa) 

