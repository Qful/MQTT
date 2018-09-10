#!/bin/bash

#add you shell 
echo "in run.sh shell"

service rabbitmq-server stop
sleep 10
chown rabbitmq:rabbitmq /var/lib/rabbitmq/.erlang.cookie
sleep 2
service rabbitmq-server start
sleep 10
#rabbitmq-server on

rabbitmqctl delete_user  guest
sleep 2
rabbitmqctl add_user  qitas  test1234
sleep 2
rabbitmqctl set_user_tags qitas administrator
sleep 2
rabbitmqctl list_users
sleep 2

echo "done qitas configure"
