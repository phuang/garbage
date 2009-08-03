#!/usr/bin/env python
# -*- coding: utf-8 -*-

from django.db import models

class DeviceType(models.Model):
    class Meta:
        ordering = ['name']
    name = models.CharField(max_length=64, unique=True)
    is_limit = models.BooleanField()
    replace = models.ForeignKey("DeviceType", null=True)

    devices = property(lambda self: self.device_set.all())

    def __unicode__(self):
        return "%s - %d" % (self.name, self.device_set.count())

    def __repr__(self):
        return "DeviceType(name='%s')" % self.name

class Device(models.Model):
    class Meta:
        ordering = ['type']
    type = models.ForeignKey(DeviceType)

    name = property(lambda self: self.type.name)

    def __unicode__(self):
        return "%s - NO#%04d" % (self.name, self.id)

class Product(models.Model):
    class Meta:
        ordering = ['name']
    name = models.CharField(max_length=64, unique=True)
    number = models.IntegerField()

    steps = property(lambda self: self.step_set.all())
    effort = property(lambda self: sum(map(lambda s:s.effort, self.steps)))

    def __unicode__(self):
        return self.name

class Step(models.Model):
    class Meta:
        ordering = ['order']
        unique_together = ('product', 'order')

    name = models.CharField(max_length=64)
    devicetype = models.ForeignKey(DeviceType, null=True)
    effort = models.FloatField()
    product = models.ForeignKey('Product')
    order = models.IntegerField()

    def __unicode__(self):
        return self.name

class Task(models.Model):
    class Meta:
        ordering = ['name']

    name = models.CharField(max_length=64)
    product = models.ForeignKey(Product)
    start_date = models.DateField()
    # end_date = models.DateField()
    deliver_date = models.DateField()

    steps = property(lambda self: self.product.steps)
    subtasks = property(lambda self: self.subtask_set.all())
    effort = property(lambda self: self.product.effort)

    def __unicode__(self):
        return "%s - %s" % (self.name, self.product.name)

class SubTask(models.Model):
    # class Meta:
    #     ordering = ['start_date']

    step = models.ForeignKey(Step)
    task = models.ForeignKey(Task)
    device = models.ForeignKey(Device)
    # start_date = models.DateField()
    # end_date = models.DateField()

