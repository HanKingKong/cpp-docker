#include "docker.hpp"
#include <iostream>

int main(int argc, char** argv){
    std::cout << "...start container" << std::endl;

    // 配置容器
    docker::container_config config;
	config.host_name = "shiyanlou";

    docker::container container(config);// 根据 config 构造容器
    container.start();                  // 启动容器
    std::cout << "stop container..." << std::endl;

    return 0;
}
