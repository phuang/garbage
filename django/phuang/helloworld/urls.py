from django.conf.urls.defaults import *

urlpatterns = patterns('',
    (r'^$', 'helloworld.views.index'),
)
