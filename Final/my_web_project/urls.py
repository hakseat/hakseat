from django.urls import path
from .views import Index,Index1,Index3
urlpatterns = [
path('index', Index.as_view()),#난향
path('index1', Index1.as_view()),#수정
path('index3', Index3.as_view()),#운정
    ]