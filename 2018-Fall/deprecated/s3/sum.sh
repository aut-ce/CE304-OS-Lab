#!/bin/bash
# In The Name of God
# ========================================
# [] File Name : sum.sh
#
# [] Creation Date : 17-10-2019
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

# print the sum of 1 to n (n given as parameter)
n=10
if [ $# -eq 1 ] && [ $1 -ge 1 ]; then
        n=$1
fi

i=0
sum=0
while [ $i -le $n ]; do
        sum=$((sum + i))
        i=$((i + 1))
done
echo "1 + ... + $n = $sum"
