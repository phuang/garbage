from taskman.sched.models import DeviceType
from taskman.sched.models import Device
from taskman.sched.models import Step
from taskman.sched.models import Product
from taskman.sched.models import Task
from django.contrib import admin

class DeviceInline(admin.StackedInline):
    model = Device

class DeviceTypeAdmin(admin.ModelAdmin):
    inlines = [DeviceInline]
    search_fields = ['name']

admin.site.register(DeviceType, DeviceTypeAdmin)

class StepInline(admin.TabularInline):
    model = Step

class ProductAdmin(admin.ModelAdmin):
    inlines = [StepInline]
    search_fields = ['name']

admin.site.register(Product, ProductAdmin)
admin.site.register(Task)
