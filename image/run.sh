#!/bin/bash
#add you shell 
echo "now,your rabbitmq running."

rabbitmqctl add_user  qitas  test1234
rabbitmqctl list_users
