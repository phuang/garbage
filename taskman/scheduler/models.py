from django.db import models

class DeviceType(models.Model):
    '''DeviceType(name)'''
    class Meta:
        db_table = 'device_type'
    
    name = models.CharField(max_length=64)

    def __unicode__(self):
        return "%s" % self.name

    def __repr__(self):
        return "DeviceType(name='%s')" % self.name

class Device(models.Model):
    class Meta:
        db_table = 'device'
    
    type = models.ForeignKey(DeviceType)    

    def __unicode__(self):
        return self.type.name + " %d" % self.id

class Step(models.Model):
    class Meta:
        db_table = 'step'
    
    name = models.CharField(max_length=64)
    devicetype = models.ForeignKey(DeviceType, null=True)
    effort = models.IntegerField()

    def __unicode__(self):
        return self.name
    
class Product(models.Model):
    class Meta:
        db_table = 'product'
    
    name = models.CharField(max_length=64)
    number = models.IntegerField()
    # steps = models.ManyToManyField(Step)
    steps = models.ManyToManyField(Step, through='scheduler.ProductSteps')

    def __unicode__(self):
        return self.name
 
class ProductSteps(models.Model):
    class Meta:
        db_table = 'product_steps'
        ordering = ['order']
        unique_together = ('product', 'step')
    
    product = models.ForeignKey(Product)
    step = models.ForeignKey(Step)
    order = models.IntegerField()

    def __unicode__(self):
        return '%s : %d %s' % (self.product.name, self.order, self.step.name)

class Task(models.Model):
    class Meta:
        db_table = 'task'

    name = models.CharField(max_length=64)
    produce = models.ForeignKey(Product)
    start_date = models.DateField()
    end_date = models.DateField()

class SubTask(models.Model):
    class Meta:
        db_table = 'sub_task'
    
    step = models.ForeignKey(Step)
    task = models.ForeignKey(Task)
    device = models.ForeignKey(Device)
    start_date = models.DateField()
    end_date = models.DateField()

