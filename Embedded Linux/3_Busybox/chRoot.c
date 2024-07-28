#include <stdlib.h>
#include <stdio.h>

int main()
{
    int input;
    printf("Please enter which root file system to start at (1 or 2) [Press 0 to quit]: \n");
    scanf("%d", &input);
    
    system("mount -t devtmpfs dev /dev");

    switch (input)
    {
    case 1:
        system("mkdir -p /mnt/rootfs_1");
        system("mkdir -p /mnt/rootfs_1");
        system("mount -t ext4 /dev/mmcblk0p2 /mnt/rootfs_1");
        printf("#### Rootfs 1 ####\n");
        system("chroot /mnt/rootfs_1");
        break;

    case 2:
        system("mkdir -p /mnt/rootfs_2");
        system("mount -t ext4 /dev/mmcblk0p3 /mnt/rootfs_2");
        printf("#### Rootfs 2 ####\n");
        system("chroot /mnt/rootfs_2");
        break;

    case 0:
        break;

    default:
        printf("Invalid input.\n");
        break;
    }

    return 0;
}