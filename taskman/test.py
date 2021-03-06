#!/usr/bin/env python
# -*- coding: utf-8 -*-
import setup
from taskman.sched.models import *

def get_devices():
    devices = Device.objects.all()

def get_tasks():
    d = {}
    tasks = Task.objects.filter(complete=False)
    for task in tasks:
        print u'%s - %f' % (task, task.work)
        for step in task.steps:
            if not step.devicetype:
                name = None
            else:
                name = step.devicetype.name
            if name not in d:
                d[name] = []
            d[name].append(step)
    all = 0
    for name, steps in d.items():
        work = sum(map(lambda s:s.work, steps))
        all += work
        print u'%s - %0.1f' % (name, work)
    print u'All - %0.1f' % all

def main():
    get_tasks()

if __name__ == "__main__":
    main()

