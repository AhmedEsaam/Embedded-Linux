# Task3 Questions

## Section 1

It is required to add a user into a group after checking whether they exist or not and displaying the relative information for the user and group.

### running the bash script

The bash script file takes two arguments the user name and the group name as `./addUserInGroup userName groupName`:

```bash
./addUserInGroup nasser Mobility
```

* The script creates the group if not existed.
* Then, creates the user if not existed.
* Then, adds the user to the group if not added.
* And finally, displays user information and group information.

#### The output

![script output](screenshots/section1.1.png)

#### When adding another user to the group using this script, it does not create the already existed group, only the new user. And displays the group info including all its users

![adding new user](screenshots/section1.2.png)

#### When passing an existing user but a new group, it only creates the group and adds this user in it

![new group](screenshots/section1.3.png)

#### Adding an existing user and existing group, yet this user does not belong to this group. It adds the user into the group and displays info

![adds existing user to existing group](screenshots/section1.4.png)

#### The final case, where we pass an existing user and group and the user belongs to the group. It ony displays user and group info

![user in group already](<screenshots/section 1.5.png>)
