from django.core.management import setup_environ

try:
    import settings
    setup_environ(settings)
except:
    import sys
    print >> sys.stderr, "Can not setup django environ" 
    sys.exit(1)

