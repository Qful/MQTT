# rabbitmq as the base image
FROM rabbitmq:latest

MAINTAINER qitas <qitas@qitas.cn>

#enable plugins
RUN rabbitmq-plugins enable rabbitmq_management
RUN rabbitmq-plugins enable rabbitmq_mqtt
RUN rabbitmq-plugins enable rabbitmq_web_mqtt

# amqp port
EXPOSE 5672
# tcp port
EXPOSE 1883
# ws port
EXPOSE 15675
# management port
EXPOSE 15672

# run shell
ADD ./run.sh /run.sh
CMD ["/bin/bash", "/run.sh"]
