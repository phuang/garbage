#!/usr/bin/env python
# -*- coding: utf-8 -*-
from taskman.sched.models import *

def get_devices():
    devices = Device.objects.all()

def get_tasks():
    d = {}
    tasks = Task.objects.all()
    for task in tasks:
        for step in task.steps:
            if not step.devicetype:
                name = None
            else:
                name = step.devicetype.name
            if name not in d:
                d[name] = []
            d[name].append(step)

    for name, steps in d.items():
        effort = sum(map(lambda s:s.effort, steps))
        print u'%s - %0.1f' % (name, effort)

def main():
    get_tasks()

if __name__ == "__main__":
    main()

