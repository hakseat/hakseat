
from django.urls import path
from .views import UploadFeed,Profile,Main,ToggleLike,Seeat,Front_main,Sujeong,Nanhyang,Unjeong
#오늘 csv_data_view

urlpatterns = [
    path('upload',UploadFeed.as_view()),
    path('like',ToggleLike.as_view()),
    path('profile',Profile.as_view()),
    path('main',Main.as_view()),
    path('seeat',Seeat.as_view()),

    path('frontmain',Front_main.as_view()),
    path('sujeong',Sujeong.as_view()),
    path('nanhyang',Nanhyang.as_view()),
    path('unjeong',Unjeong.as_view()),


]

