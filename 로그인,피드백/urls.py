
from django.urls import path
from .views import UploadFeed,Profile,Main,ToggleLike,Seeat
urlpatterns = [
    path('upload',UploadFeed.as_view()),
    path('like',ToggleLike.as_view()),
    path('profile',Profile.as_view()),
    path('main',Main.as_view()),
    path('seeat',Seeat.as_view()),
]
