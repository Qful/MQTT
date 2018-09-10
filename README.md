# Docker-mqtt

## 描述

M2M通信平台，本分支采用RabbitMQ官方镜像部署

## 组成

项目下包括Dockerfile和相关的配置文件,容器启动配置文件为run.sh，可以配置容器初始化指令

start.sh为启动脚本，运行启动脚本完成所有部署工作

## 说明

RabbitMQ是一个开源的AMQP实现，服务器端用Erlang语言编写，支持多种客户端，如：Python、Ruby、.NET、Java、JMS、C、PHP、ActionScript、XMPP、STOMP等，支持AJAX。用于在分布式系统中存储转发消息，在易用性、扩展性、高可用性等方面表现不俗。
