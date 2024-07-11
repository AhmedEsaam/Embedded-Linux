#!/bin/bash

userName=$1
groupName=$2

# create the group if not exists
if ! sudo cat /etc/group | grep "^${groupName}"; then
    sudo groupadd ${groupName}
fi

# create the user if not exists
if ! sudo cat /etc/passwd | grep "^${userName}"; then
    sudo adduser ${userName}
fi

# add the user to the group if not added
if ! sudo cat /etc/group | grep "^${groupName}" | grep "${userName}"; then
    sudo usermod -aG ${groupName} ${userName}
fi

# Display relevant user information
echo ' '
echo "User information:"
echo "user id: "$(id -u ${userName})
sudo cat /etc/passwd | grep ${userName} | tr : \\n | tr , \\n


# Display relevant group information
echo ' '
echo "Group information:"
echo "group members: "$(sudo groupmems -g ${groupName} -l)
sudo getent group ${groupName} | tr : ' '



