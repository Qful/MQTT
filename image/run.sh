#!/bin/bash

#add you shell 

service rabbitmq-server stop
chown rabbitmq:rabbitmq /var/lib/rabbitmq/.erlang.cookie
service rabbitmq-server start

echo "in run.sh shell"

rabbitmqctl delete_user  guest
rabbitmqctl add_user  qitas  test1234
rabbitmqctl set_user_tags qitas administrator
rabbitmqctl list_users

rabbitmq-server on
