import sys
from django.core.management import setup_environ

try:
    import settings
    setup_environ(settings)
except:
    print >> sys.stderr, "Can not setup django environ" 
    sys.exit(1)
  
from taskman.sched import models

def insert_devices():
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
    )

    for name, number in devices:
        t = models.DeviceType(name=name)
        t.save()
        t.




def main():
    insert_device_type()
    

if __name__ == "__main__":
    main()

