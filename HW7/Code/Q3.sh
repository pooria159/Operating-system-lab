#!bin/bash

read -sp "Enter your password: " password
if [ "$password" = "123456" ]; then
  echo "Welcome"
else
  echo "Wrong Password"
fi


