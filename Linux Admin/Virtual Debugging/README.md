# Virtual Debugging

* We used to debug using **GDB** on **CLI** or **GUI** like **VScode**.

* To debug remotely a code on the target machine.

* You can debug remotely
  1. Output binary files.
  2. Scripts (Shell script or Python script).

* The machine used to debug and the target machine must be on the same network.

* We'll use **Open SSH** protocol.

## Using **SSH**

1. Get IP (Given they're on the same network). use `ip a`
   * Get ip under `enp8s0` ethernet.
2. Use **ping** to ensure that they're on the same subnet.

* Establish connection

```shell
ssh target_username@ip_address
```

* Enter target password

* Terminal process in the Host does not have the capability to open apps that depend on graphics on the target machine.

* Download VScode extention **Remote SSH**.
