# Docker-mqtt

## 描述

M2M通信平台，本分支采用RabbitMQ官方镜像部署

## 组成

项目下包括Dockerfile和相关的配置文件,容器启动配置文件为run.sh，可以配置容器初始化指令

start.sh为启动脚本，运行启动脚本完成所有部署工作


---

### 角色管理

- 新增一个用户

rabbitmqctl  add_user  Username  Password

-  设置权限

rabbitmqctl set_user_tags Username  permissions  


- 删除一个用户

rabbitmqctl  delete_user  Username

- 修改用户的密码

rabbitmqctl  change_password  Username  Newpassword

- 查看当前用户列表

rabbitmqctl  list_users

- 查看指定用户的权限信息

rabbitmqctl  list_user_permissions  User

-  清除用户的权限信息

rabbitmqctl  clear_permissions  [-p VHostPath]  User

---


## 说明

RabbitMQ是一个开源的AMQP实现，服务器端用Erlang语言编写，支持多种客户端，如：Python、Ruby、.NET、Java、JMS、C、PHP、ActionScript、XMPP、STOMP等，支持AJAX。用于在分布式系统中存储转发消息，在易用性、扩展性、高可用性等方面表现不俗。
