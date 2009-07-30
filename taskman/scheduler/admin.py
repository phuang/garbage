from taskman.scheduler.models import DeviceType
from taskman.scheduler.models import Device
from taskman.scheduler.models import Step
from taskman.scheduler.models import Product
from django.contrib import admin

class DeviceInline(admin.TabularInline):
    model = Device

class DeviceTypeAdmin(admin.ModelAdmin):
    inlines = [DeviceInline]
    search_fields = ['name']

admin.site.register(DeviceType)
admin.site.register(Device)
admin.site.register(Step)
admin.site.register(Product)

