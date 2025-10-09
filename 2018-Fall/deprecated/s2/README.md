# Linux Kernel Modules

> Do you pine (to want or miss something or someone very much) for the days when men were men and wrote their own device drivers?
>
> Linus Torvalds

## Requirements
To compile Linux device drivers on your system,
you must install Linux'sheaders with the following command:

```sh
sudo apt-get install linux-headers-$(uname -r)
```

If you have many versions of GCC installed,
you can use the following command to specify the exact version of GCC in the build procedure.

```sh
make CC=/usr/bin/gcc
```

After successful compilation of kernel module you can insert it with the following command:

```sh
sudo insmod hello.ko
# modprobe is a clever command that parses the modules.dep file in order to load dependencies first
# sudo modprobe hello
```

But before that you can see the module information with the following command:

```sh
modinfo hello.ko
# why we can gather module information from its binary?
```

Then you can use `dmesg` to see the system logs.

```
106745.687281] hello: loading out-of-tree module taints kernel.
[106745.687321] hello: module verification failed: signature and/or required key missing - tainting kernel
[106745.688081] Hello, I am loading
```

In the end, you can remove it and see its logs again.

```sh
sudo rmmod hello
```

```
[106957.018862] Goodbye, i am unloading
```

## Points
- [Static functions in C](https://www.geeksforgeeks.org/what-are-static-functions-in-c/)
- [What does __init mean in the Linux kernel code?](https://stackoverflow.com/questions/8832114/what-does-init-mean-in-the-linux-kernel-code)
