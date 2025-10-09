# In The Name of God
# =======================================
# [] File Name : pipe.py
#
# [] Creation Date : 27-11-2019
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

import os


def child(n, w):
    print('I am Child')
    f = os.fdopen(w, 'w')
    # the old way
    f.write('hello %d\n' % (n) )
    # the new way
    f.write(f'hello {n}\n')


def parent():
    r, w = os.pipe()
    n = 10
    if os.fork() == 0:
        child(n, w)
    else:
        print('I am Parent')
        f = os.fdopen(r, 'r')
        print(f.readline())


if __name__ == '__main__':
    parent()
