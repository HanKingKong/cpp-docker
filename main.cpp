#include "docker.hpp"
#include <iostream>

int main(int argc, char** argv){
    std::cout << "...start container" << std::endl;
    docker::container_config config;

    // 配置容器
    // ...

    docker::container container(config);// 根据 config 构造容器
    container.start();                  // 启动容器
    std::cout << "stop container..." << std::endl;

    return 0;
}
