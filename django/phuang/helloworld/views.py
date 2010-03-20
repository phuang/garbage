from django.shortcuts import render_to_response
from datetime import datetime

def index(request):
    vars = {
        'var1' : datetime.now()
    }
    return render_to_response('index.html', vars)
