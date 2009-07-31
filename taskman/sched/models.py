from django.db import models

class DeviceType(models.Model):
    name = models.CharField(max_length=64)

    def __unicode__(self):
        return "%s" % self.name

    def __repr__(self):
        return "DeviceType(name='%s')" % self.name

class Device(models.Model):
    type = models.ForeignKey(DeviceType)    

    def __unicode__(self):
        return self.type.name + " %d" % self.id

class Step(models.Model):
    name = models.CharField(max_length=64)
    devicetype = models.ForeignKey(DeviceType, null=True)
    effort = models.IntegerField()

    def __unicode__(self):
        return self.name
    
class Product(models.Model):
    name = models.CharField(max_length=64)
    number = models.IntegerField()
    # steps = models.ManyToManyField(Step)
    steps = models.ManyToManyField(Step, through='sched.ProductSteps')

    def __unicode__(self):
        return self.name
 
class ProductSteps(models.Model):
    class Meta:
        ordering = ['order']
        unique_together = ('product', 'step')
    
    product = models.ForeignKey(Product)
    step = models.ForeignKey(Step)
    order = models.IntegerField()

    def __unicode__(self):
        return '%s : %d %s' % (self.product.name, self.order, self.step.name)

class Task(models.Model):
    name = models.CharField(max_length=64)
    produce = models.ForeignKey(Product)
    start_date = models.DateField()
    end_date = models.DateField()

class SubTask(models.Model):
    step = models.ForeignKey(Step)
    task = models.ForeignKey(Task)
    device = models.ForeignKey(Device)
    start_date = models.DateField()
    end_date = models.DateField()

