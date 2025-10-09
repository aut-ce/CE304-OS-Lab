/*
 * In The Name of God
 * =======================================
 * [] File Name : hello.c
 *
 * [] Creation Date : 30-08-2019
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2019 Parham Alvani.
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/types.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Parham Alvani");
MODULE_DESCRIPTION("This module does nothing...");

static int __init hello_init(void){
	pr_info("Hello, I am loading\n");
	pr_debug("Hello World\n");
	return 0;
}

static void __exit hello_exit(void){
	pr_info("Goodbye, i am unloading\n");
}

module_init(hello_init);
module_exit(hello_exit);
