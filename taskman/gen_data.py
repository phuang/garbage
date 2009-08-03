#!/usr/bin/env python
# -*- coding: utf-8 -*-
import setup
import sys
from datetime import date
  
from taskman.sched import models

def create_devices():
    devices = (
        (u'剪板机', 1),
        (u'16T', 1),
        (u'25T', 4),
        (u'40T', 1),
        (u'63T', 2),
        (u'80T', 1),
        (u'100T', 1),
        (u'125T', 2),
        (u'160T', 1),
        (u'折弯机', 1),
        (u'油压机', 1),
        (u'攻丝机', 0),
        (u'手工', 0),
        (u'钻床', 0),
        (u'二保焊', 0),
        (u'点焊机', 0),
    )

    for name, number in devices:
        t = models.DeviceType(name=name, is_limit=(number != 0))
        t.save()
        for i in range(0, number):
            d = models.Device(type=t)
            d.save()

def create_product():
    products = (
        ('NHP201495P1',  2800,
            (
                (u'剪料', u'剪板机', 2),
                (u'落料', u'125T', 5),
                (u'变形1', u'25T', 10),
                (u'变形2', u'100T', 10),
                (u'冲孔1', u'63T', 8),
                (u'冲孔2', u'25T', 8),
                (u'冲窝', u'25T', 8),
                (u'电镀锌并橄榄绿钝化', None, 0),
                (u'入成品库', None, 0)
            )

        ),
        ('6932 607-5',    600,
            (
                (u'剪条料', u'剪板机', 1),
                (u'落料', u'100T', 4),
                (u'拉伸1', u'油压机', 8),
                (u'拉伸2', u'油压机', 8),
                (u'拉伸3', u'油压机', 10),
                (u'拉伸4', u'油压机', 8),
                (u'切边', u'油压机', 8),
                (u'冲孔', u'63T', 6),
                (u'清洗擦拭', u'手工', 8),
                (u'入成品库', None, 0)
            )
        ),
        ('1VFS180018P1', 1400,
            (
                (u'剪料', u'剪板机', 3),
                (u'切角', u'40T', 3),
                (u'冲孔', u'25T', 2.5),
                (u'变形1', u'折弯机', 3),
                (u'变形2', u'折弯机', 3),
                (u'变形3', u'折弯机', 4),
                (u'变形4', u'折弯机', 4),
                (u'变形5', u'折弯机', 3),
                (u'调整外形', u'手工', 12),
                (u'入成品库', None, 0)
            )
        ),
        ('NHP304539P1',  3600,
            (
                (u'剪外形', u'剪板机', 1.2),
                (u'落料', u'100T', 8),
                (u'冲缺口', u'25T', 8),
                (u'冲孔', u'40T', 8),
                (u'去毛刺', u'手工', 12),
                (u'折弯', u'25T', 8),
                (u'折弯', u'25T', 8),
                (u'折弯', u'25T', 8),
                (u'电镀', None, 0),
                (u'入成品库', None, 0)
            )
        ),
        ('NHP304737P1',  3000,
            (
                (u'剪外形', u'剪板机', 14),
                (u'冲孔', u'63T', 8),
                (u'冲孔', u'100T', 11),
                (u'攻丝', u'攻丝机', 24),
                (u'调平调直', u'手工', 12),
                (u'变三爪', u'25T', 8),
                (u'冲窝', u'25T', 8),
                (u'变形', u'63T', 5),
                (u'电镀锌并橄榄绿钝化', None, 0),
                (u'入成品库', None, 0)
            )
        ),
        ('NHP201504P1',  3000,
            (
                (u'剪外形', u'剪板机', 12),
                (u'切轮廓', u'125T', 10),
                (u'冲缺口', u'125T', 10),
                (u'切边', u'40T', 8),
                (u'变形', u'125T', 10),
                (u'变形折弯', u'折弯机', 10),
                (u'变形折弯', u'折弯机', 10),
                (u'电镀锌并橄榄绿钝化', None, 0),
                (u'入成品库', None, 0)
            )
        ),
        ('NHP304610P1',  3000,
            (
                (u'剪料', u'剪板机', 8),
                (u'落料', u'160T', 8),
                (u'冲孔', u'63T', 8),
                (u'切边', u'63T', 8),
                (u'切边', u'63T', 8),
                (u'去毛刺', u'手工', 12),
                (u'变形', u'125T', 10),
                (u'折弯', u'40T', 8),
                (u'电镀', None, 0),
                (u'入成品库', None, 0)
            )
        ),
        ('NHP304418P1',  1000,
            (
                (u'剪料', u'剪板机', 1),
                (u'落料', u'160T', 14),
                (u'冲孔', u'25T', 3),
                (u'冲孔', u'25T', 3),
                (u'扩孔', u'钻床', 3),
                (u'冲孔', u'25T', 3),
                (u'V弯曲', u'25T', 4),
                (u'V弯曲', u'25T', 3),
                (u'U弯曲', u'63T', 3),
                (u'折弯', u'手工', 6),
                (u'电镀', None, 0),
                (u'入成品库', None, 0)
            )
        ),
        ('1VFJ130023R1', 1600,
            (
                (u'剪条料', u'剪板机', 2.5),
                (u'落料', u'125T', 5),
                (u'冲孔', u'25T', 3),
                (u'拉伸', u'油压机', 10),
                (u'切外圆边', u'125T', 5),
                (u'冲兰盘孔', u'63T', 5),
                (u'冲侧孔', u'63T', 5),
                (u'冲窝', u'40T', 5),
                (u'翻遍', u'63T', 5),
                (u'焊接', u'点焊机', 17),
                (u'清洗擦拭', u'手工', 8),
                (u'入成品库', None, 0)
            )
        ),
        ('NHP101904P1', 1000,
            (
                (u'剪外形', u'剪板机', 4),
                (u'落料', u'100T', 5),
                (u'落料', u'100T', 5),
                (u'冲孔', u'100T', 5),
                (u'冲孔', u'63T', 5),
                (u'冲孔', u'63T', 5),
                (u'切边', u'40T', 5),
                (u'冲孔', u'25T', 5),
                (u'冲孔', u'25T', 5),
                (u'焊接', u'二保焊', 32),
                (u'冲窝', u'63T', 6),
                (u'变形', u'折弯机', 8),
                (u'变形', u'折弯机', 8),
                (u'变形', u'折弯机', 8),
                (u'变形', u'折弯机', 8),
                (u'入成品库', None, 0)
            )
        )
    )

    for name, number, steps in products:
        product = models.Product(name=name, number=number)
        product.save()
        for i, (step_name, device_name, effort) in enumerate(steps):
            device = None
            if device_name:
                device = models.DeviceType.objects.filter(name=device_name)[0]
            step = models.Step(name=step_name, devicetype=device, effort=effort, product=product, order=i)
            step.save()
        task = models.Task(name='2009-08', product=product,
                           start_date=date(2009,7,27),
                           deliver_date=date(2009,7,31))
        task.save()

def create_task():
    pass

def main():
    create_devices()
    create_product()
    create_task()
    

if __name__ == "__main__":
    main()

