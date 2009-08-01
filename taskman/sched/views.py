from django.template import Context, loader
from django.http import HttpResponse
from taskman.sched import models

def expose(template):
    def __expose(func):
        def __wrapper(*args, **kargs):
            t = loader.get_template(template)
            c = Context(func(*args, **kargs))
            return HttpResponse(t.render(c))
        return __wrapper
    return __expose

@expose(template="sched/tasks.html")
def tasks(request):
    tasks = models.Task.objects.all()
    return { "tasks" : tasks}

