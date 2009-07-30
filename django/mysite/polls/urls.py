# from django.conf.urls.defaults import *
# 
# urlpatterns = patterns('mysite.polls.views',
#     (r'^$', 'index'),
#     (r'^(?P<poll_id>\d+)/$', 'detail'),
#     (r'^(?P<poll_id>\d+)/results/$', 'results'),
#     (r'^(?P<poll_id>\d+)/vote/$', 'vote'),
# )

from django.conf.urls.defaults import *
from mysite.polls.models import Poll

info_dict = {
    'queryset': Poll.objects.all(),
}

urlpatterns = patterns('',
    (r'^$', 'django.views.generic.list_detail.object_list', info_dict),
    (r'^(?P<object_id>\d+)/$', 'django.views.generic.list_detail.object_detail', info_dict),
    url(r'^(?P<object_id>\d+)/results/$', 'django.views.generic.list_detail.object_detail', dict(info_dict, template_name='polls/poll_results.html'), 'poll_results'),
    (r'^(?P<poll_id>\d+)/vote/$', 'mysite.polls.views.vote'),
    (r'^(?P<poll_id>\d+)/json/$', 'mysite.polls.views.json'),
)

